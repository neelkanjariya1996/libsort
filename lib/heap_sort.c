/*
 * File name: heap_sort.c
 * Author: Neel Kanjaria
 * Description: Code for heap sort
 */
#include "sort.h"
#include "sort_private.h"

#define PARENT(ind)   ((ind - 1) / 2)     //Macro to get the parent's index
#define LEFT(ind)     ((2 * ind) + 1)     //Macro to get the left child's index
#define RIGHT(ind)    ((2 * ind) + 2)     //Macro to get the right child's index

/*
 * This function is used to heapify the subtree rooted at node ind which
 * is an index in arr[]. 
 *
 * @param1 arr        The array to be sorted
 * @param2 arr_size   Number of elements in the array
 * @param3 elem_size  Size of each individual array element
 * @param4 ind        Index in array representing the subtree 
 *                    which is to be heapified
 * @param5 cmp        Compare function used to compare two array elements
 *
 * @return            void
 */
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
  
  largest = ind;    //Initializing largest as root
  l = LEFT(ind);    //Left child index in array
  r = RIGHT(ind);   //Right child index in array

  /*
   * If left child is larger than root, consider to make it as root
   */
  ret = compare((void *)ARR_LOC(arr, l, elem_size), 
                (void *)ARR_LOC(arr, largest, elem_size),
                 elem_size, cmp);
  if((l < arr_size) && (ret == SORT_GT)) {
  
    largest = l;
  }

  /*
   * If right child is larger than largest so far, make it root
   */
  ret = compare((void *)ARR_LOC(arr, r, elem_size), 
                (void *)ARR_LOC(arr, largest, elem_size),
                 elem_size, cmp);
  if((r < arr_size) && (ret == SORT_GT)) {
  
    largest = r;
  }

  /*
   * If the original largest is not the root, swap the largest child
   * and root. Also, call heapify on the largest
   */
  if(largest != ind) {
 
    swap(ARR_LOC(arr, ind, elem_size), 
         ARR_LOC(arr, largest, elem_size), 
         elem_size);

    /*
     * Recursively heapify the affected sub-tree
     */
    heapify(arr, arr_size, elem_size, largest, cmp);
  }
}

/*
 * Given an array, this function sorts the array based on the compare function
 * passed. If no compare function is provided, it uses memcmp(), to compare 
 * the elements of the array.
 *
 * @param1 arr        The array to be sorted
 * @param2 arr_size   Number of elements in the array
 * @param3 elem_size  Size of each individual array element
 * @param4 cmp        Compare function used to compare two array elements
 *
 * @return            void
 */
void
hsort (void *arr, size_t arr_size, size_t elem_size,
       cmp_e (*cmp)(const void *, const void *))
{

  long i = 0;

  if(!arr || !arr_size) {
    return;
  }

  /*
   * Building the heap (rearranging the array)
   */
  for(i = ((arr_size / 2) - 1); i >= 0; i--) {
  
    heapify(arr, arr_size, elem_size, i, cmp);
  }

  /*
   * One by one extract elements from the heap
   */
  for(i = (arr_size - 1); i > 0; i--) {
 
    /*
     * Swap element at index_0 of array to end i.e. move current root to end
     */
    swap(ARR_LOC(arr, 0, elem_size), 
         ARR_LOC(arr, i, elem_size),
         elem_size);

    /*
     * Call heapify on the reduced heap
     */
    heapify(arr, i, elem_size, 0, cmp);
  }

  return;
}
