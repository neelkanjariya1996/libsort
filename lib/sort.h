/*
 * File name: sort.h
 * Author: Neel Kanjaria
 * Description: This Header file defines 
 * the various APIs provided by the library
 */
#ifndef __SORT_H__

#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Return types for the compare function
 */
typedef enum cmp_e_{

  SORT_LT = -1,       /* elem1 < elem2 */  
  SORT_EQ,            /* elem1 == elem2 */
  SORT_GT,            /* elem1 > elem2 */
}cmp_e;

/*
 * The msort() function sorts an array using merge sort algorithm with arr_size
 * elements of size elem_size. The arr argument point to the start of the array. 
 *
 * The contents of the array are sorted in ascending order according to a
 * comparison function ponted to by cmp, which is called with two arguments 
 * that point to the objects being compared. The comparison function must
 * return SORT_LT, SORT_EQ, or SORT_GT if the first argument is conidered to be 
 * respectively less than, equal to, or greater than the second. If two members
 * compare as equal, their order in the sorted array is undefined.
 *
 * @param1 arr        The array to be sorted
 * @param2 arr_size   Number of elements in
 *                    the array
 * @param3 elem_size  Size of each individual array element
 * @param4 cmp        Compare function used to compare two array elements
 *
 * @return            void
 */
void
msort (void *arr, size_t arr_size,size_t elem_size, 
            int (*cmp)(const void *, const void *));

/*
 * The hsort() function sorts an array using heap sort algorithm with arr_size
 * elements of size elem_size. The arr argument point to the start of the array. 
 *
 * The contents of the array are sorted in ascending order according to a
 * comparison function ponted to by cmp, which is called with two arguments 
 * that point to the objects being compared. The comparison function must
 * return SORT_LT, SORT_EQ, or SORT_GT if the first argument is conidered to be 
 * respectively less than, equal to, or greater than the second. If two members
 * compare as equal, their order in the sorted array is undefined.
 *
 * @param1 arr        The array to be sorted
 * @param2 arr_size   Number of elements in
 *                    the array
 * @param3 elem_size  Size of each individual array element
 * @param4 cmp        Compare function used to compare two array elements
 *
 * @return            void
 */
void
hsort (void *arr, size_t arr_size, size_t elem_size,
           cmp_e (*cmp)(const void *, const void *));
#endif
