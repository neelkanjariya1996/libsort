/*
 * File name: sort_private.h
 * Author: Neel Kanjaria
 * Description: private header file needed for sorting library
 * NOT TO BE USED BY USER DIRECTLY
 */
#ifndef __SORT_PRIVATE_H__
#define __SORT_PRIVATE_H__

#include "sort.h"

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
 * It used the compare function passed by the user. If no compare function
 * is passed, it uses the standard memcmp() function.
 *
 * @param1 p1         Pointer to element_1
 * @param2 p2         Pointer to element_2
 * @param3 elem_size  Size of each individual array element
 * @param4 cmp        Compare function to be used if passed from user
 *
 * @return cmp_e      SORT_LT -> element_1 is less than element_2
 *                    SORT_EQ -> element_1 is equal to element_2
 *                    SORT_GT -> element_1 is greater than element_2
 */
static inline cmp_e
compare (const void *p1, const void *p2, size_t elem_size,
         compare_fn cmp)
{

  cmp_e ret = 0;

  if(cmp) {

    return (cmp(p1, p2));
  }

  ret = memcmp(p1, p2, elem_size);
  if(ret < 0) {

    ret =  SORT_LT;
  } else if (ret > 0) {

    ret = SORT_GT;
  } else {

    ret = SORT_EQ;
  }

  return ret;
}

/*
 * Function to swap two elements byte by bte of size SIZE
 *
 * @param1 k1   pointer to element_1
 * @param2 k2   pointer to element_2
 * @param3 size size of the individual array element
 *
 * @return      void
 */
static inline void
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
  } while((--size) > 0);
}

#endif
