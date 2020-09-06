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
 * macro to access a void* array for a given 
 * element size
 *
 * @input1 arr the pointer to the array
 * @input2 ind the index you want to change/use
 * @input3 elem_size size of each individual 
 *                   array element
 *
 * @return returns the array location of the index
 */
#define ARR_LOC(arr, ind, elem_size) (arr + (ind * elem_size))

/*
 * merge_sort function used by the user
 *
 * @input1 arr the array to be sorted
 * @input2 arr_size number of elements in
 *                  the array
 * @input3 elem_size size of each individual 
 *                   array element
 * @input4 cmp compare function used to compare two 
 *             array elements
 */
void
merge_sort (void *arr, size_t arr_size,size_t elem_size, 
            int (*cmp)(const void *, const void *));

#endif
