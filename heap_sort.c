#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARENT(ind)   ((ind - 1) / 2)
#define LEFT(ind)     ((2 * ind) + 1)
#define RIGHT(ind)    ((2 * ind) + 2)

#define ARR_LOC(arr, ind, elem_size)  (arr + (ind * elem_size))

typedef enum cmp_e_ {

  HEAPSORT_LT = -1,
  HEAPSORT_EQ,
  HEAPSORT_GT,
} cmp_e;

#define swap(a, b, size)                                                      \
  do                                                                              \
    {                                                                              \
      size_t __size = (size);                                                      \
      char *__a = (a), *__b = (b);                                              \
      do                                                                      \
        {                                                                      \
          char __tmp = *__a;                                                      \
          *__a++ = *__b;                                                      \
          *__b++ = __tmp;                                                      \
        } while (--__size > 0);                                                      \
    } while (0)

/*
void
swap (const void *k1, const void *k2, size_t size)
{

  char *p1 = NULL;
  char *p2 = NULL;
  char tmp;

  p1 = (char *)k1;
  p2 = (char *)k2;

  do {
  
    tmp = *p1;
    *p1++ = *p2;
    *p2++ = tmp;
  } while(--size > 0);
}
*/

cmp_e
heap_cmp (const void *p1, const void *p2, size_t elem_size, 
          cmp_e (*cmp)(const void *, const void *))
{

  int ret = 0;

  if(!cmp) {
  
    ret = memcmp(p1, p2, elem_size);
    if(ret < 0) {
    
      ret = HEAPSORT_LT;
    } else if(ret > 0) {
    
      ret = HEAPSORT_GT;
    } else {
    
      ret = HEAPSORT_EQ;
    }
  } else {
  
    ret = cmp(p1, p2);
  }

  return ret;
}

void
heapify (void *arr, size_t arr_size, 
         size_t elem_size, size_t ind,
         cmp_e (*cmp)(const void *, const void *))
{

  size_t largest = 0;
  size_t l = 0;
  size_t r = 0;

  if(!arr) {
  
    return;
  }
  
  largest = ind;
  l = LEFT(ind);
  r = RIGHT(ind);

  if((l < arr_size) && 
      heap_cmp((void *)ARR_LOC(arr, l, elem_size), 
               (void *)ARR_LOC(arr, largest, elem_size),
               elem_size, cmp) == HEAPSORT_GT) {
  
    largest = l;
  }

  if((r < arr_size) && 
      heap_cmp((void *)ARR_LOC(arr, r, elem_size), 
               (void *)ARR_LOC(arr, largest, elem_size),
               elem_size, cmp) == HEAPSORT_GT) {
  
    largest = r;
  }

  if(largest != ind) {
 
    swap(ARR_LOC(arr, ind, elem_size), 
         ARR_LOC(arr, largest, elem_size), 
         elem_size);

    heapify(arr, arr_size, elem_size, largest, cmp);
  }
}

void
heap_sort (void *arr, size_t arr_size, size_t elem_size,
           cmp_e (*cmp)(const void *, const void *))
{

  long i = 0;

  if(!arr) {
  
    printf("Array Empty\n");
    return;
  }

  if(arr_size == 0) {
  
    printf("Array Empty\n");
    return;
  }

  if(!cmp) {
  
    printf("No compare function passed, memcmp() is"
           "being used for comparison\n");
  }

  for(i = ((arr_size / 2) - 1); i >= 0; i--) {
  
    printf("i : %ld\n", i);
    heapify(arr, arr_size, elem_size, i, cmp);
  }

  printf("heapified fist half of array\n");

  for(i = (arr_size - 1); i > 0; i--) {
 
    printf("i : %ld\n", i);
    swap(ARR_LOC(arr, 0, elem_size), 
         ARR_LOC(arr, i, elem_size),
         elem_size);

    heapify(arr, i, elem_size, 0, cmp);
  }

  return;
}

cmp_e
cmp (const void *k1, const void *k2)
{
  
  int *p1 = NULL;
  int *p2 = NULL;

  if(!k1 && !k2) {

    return HEAPSORT_EQ;
  }
  if(!k1) {

    return HEAPSORT_LT;
  }
  if(!k2) {

    return HEAPSORT_GT;
  }

  p1 = (int *)k1;
  p2 = (int *)k2;

  if(*p1 < *p2) {

    return HEAPSORT_LT;
  } else if(*p1 > *p2) {

    return HEAPSORT_GT;
  } else {

    return HEAPSORT_EQ;
  }
}

void
print_array (int *arr, int n)
{

  size_t i = 0;

  for(i = 0; i < n; i++) {
  
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int
main ()
{

  int arr[] = {1,5,8,9,7,2,3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("Original array: ");
  print_array(arr, size);

  heap_sort(arr, size, sizeof(int), cmp);

  printf("Sorted   array: ");
  print_array(arr, size);
}
