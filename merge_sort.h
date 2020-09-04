#ifndef __MERGE_SORT_H__

#define __MERGE_SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
