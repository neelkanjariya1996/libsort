#include "sort.h"
#include "sort_private.h"

#define PARENT(ind)   ((ind - 1) / 2)
#define LEFT(ind)     ((2 * ind) + 1)
#define RIGHT(ind)    ((2 * ind) + 2)

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

void
heapify (void *arr, size_t arr_size, 
         size_t elem_size, size_t ind,
         cmp_e (*cmp)(const void *, const void *))
{

  size_t largest = 0;
  size_t l = 0;
  size_t r = 0;
  cmp_e ret = 0;

  if(!arr) {
  
    return;
  }
  
  largest = ind;
  l = LEFT(ind);
  r = RIGHT(ind);

  ret = compare((void *)ARR_LOC(arr, l, elem_size), 
                 (void *)ARR_LOC(arr, largest, elem_size),
                  elem_size, cmp);
  if((l < arr_size) && (ret == SORT_GT)) {
  
    largest = l;
  }

  ret = compare((void *)ARR_LOC(arr, r, elem_size), 
                 (void *)ARR_LOC(arr, largest, elem_size),
                  elem_size, cmp);
  if((r < arr_size) && (ret == SORT_GT)) {
  
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

  if(!arr || !arr_size) {
  
    printf("ARRAY EMPTY ");
    return;
  }

  for(i = ((arr_size / 2) - 1); i >= 0; i--) {
  
    heapify(arr, arr_size, elem_size, i, cmp);
  }

  for(i = (arr_size - 1); i > 0; i--) {
 
    swap(ARR_LOC(arr, 0, elem_size), 
         ARR_LOC(arr, i, elem_size),
         elem_size);

    heapify(arr, i, elem_size, 0, cmp);
  }

  return;
}
