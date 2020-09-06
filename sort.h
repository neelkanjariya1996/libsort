#ifndef __SORT_H__

#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum cmp_e_{

  SORT_LT = -1,
  SORT_EQ,
  SORT_GT,
}cmp_e;

/*
 * macro to access a void* array for a given element size
 *
 * @param1 arr        The pointer to the array
 * @param2 ind        The index you want to change/use
 * @param3 elem_size  Size of each individual array element
 *
 * @return            Returns the array location of the index
 */
#define ARR_LOC(arr, ind, elem_size) (arr + (ind * elem_size))

/*
 * merge_sort function used by the user
 *
 * @param1 arr        The array to be sorted
 * @param2 arr_size   Number of elements in
 *                    the array
 * @param3 elem_size  Size of each individual array element
 * @param4 cmp        Compare function used to compare two array elements
 */
void
merge_sort (void *arr, size_t arr_size,size_t elem_size, 
            int (*cmp)(const void *, const void *));

#endif
