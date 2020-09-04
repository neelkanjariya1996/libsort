#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LOC(arr, ind, ele_size) (arr + (ind * ele_size))

void
print_array (int *arr, int size)
{

  int i = 0;

  if(!arr)
    return;

  for(i = 0; i < size; i++) {
  
    printf("%d ", arr[i]);
  }
  printf("\n");

  return;
}

int
merge_cmp (const void *p1, const void *p2, size_t ele_size,
           int (*cmp)(const void *, const void *))
{

  int ret = 0;

  if(!cmp) {
 
    ret =  memcmp(p1, p2, ele_size);
    //printf("p1: %f, p2: %f, ret: %d\n", *(float *)p1, *(float *)p2, ret);
    
    return ret;
  }

  ret = (cmp(p1, p2));
  //printf("p1: %f, p2: %f, ret: %d\n", *(float *)p1, *(float *)p2, ret);

  return ret;
}

void
merge (void *arr, size_t ele_size, size_t low, size_t mid, size_t high, 
       int (*cmp)(const void *, const void *))
{

  size_t n1 = 0;
  size_t n2 = 0;
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;
  void *L;
  void *R;

  if(!arr)
    return;

  n1 = mid - low + 1;
  n2 = high - mid;

  L = malloc(n1 * ele_size);
  if(!L)
    return;
  R = malloc(n2 * ele_size);
  if(!R) {
  
    free(L);
    return;
  }

  memcpy(L, ARR_LOC(arr, low, ele_size), (n1 * ele_size));
  memcpy(R, ARR_LOC(arr, (mid + 1), ele_size), (n2 * ele_size));

  i = 0;
  j = 0;
  k = low;
  while((i < n1) && (j < n2)) {
  
    if( merge_cmp((void *)ARR_LOC(L, i, ele_size), (void *)ARR_LOC(R, j, ele_size), ele_size, cmp) < 0) {
    
      memcpy(ARR_LOC(arr, k, ele_size), ARR_LOC(L, i, ele_size), ele_size);
      i++;
    } else {
    
      memcpy(ARR_LOC(arr, k, ele_size), ARR_LOC(R, j, ele_size), ele_size);
      j++;
    }
    k++;
  }

  while(i < n1) {
  
    memcpy(ARR_LOC(arr, k, ele_size), ARR_LOC(L, i, ele_size), ele_size);
    i++;
    k++;
  }

  while(j < n2) {
  
    memcpy(ARR_LOC(arr, k, ele_size), ARR_LOC(R, j, ele_size), ele_size);
    j++;
    k++;
  }
 
  if(L) {

    free(L);
  }
  if(R) {

    free(R);
  }

  return;
}

void
merge_sort_util (void *arr, size_t ele_size, size_t low, size_t high,
                 int (*cmp)(const void *, const void *))
{
  
  size_t mid = 0;

  if(!arr)
    return;

  if(low >= high)
    return;

  mid = low + ((high - low) / 2);

  merge_sort_util(arr, ele_size, low, mid, cmp);
  merge_sort_util(arr, ele_size, (mid + 1), high, cmp);

  merge (arr, ele_size, low, mid, high, cmp);

  return;
}

void
merge_sort (void *arr, size_t arr_size,size_t ele_size, 
            int (*cmp)(const void *, const void *))
{

  if(!arr)
    return;

  if(arr_size == 0)
    return;

  merge_sort_util(arr, ele_size, 0, arr_size - 1, cmp);
}

int
cmp (const void *p1, const void *p2)
{

  return (*(int *)p1 - *(int *)p2);
}

int
main ()
{

  int arr[] = {2, 0, 4, 6, 8, 1, 5, 3, 9, 7};
  int size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("Original array: ");
  print_array(arr, size);

  merge_sort(arr, size, sizeof(int), cmp);

  printf("Sorted   array: ");
  print_array(arr, size);

  return 0;
}
