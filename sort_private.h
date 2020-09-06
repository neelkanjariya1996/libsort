#ifndef __SORT_PRIVATE_H__

#define __SORT_PRIVATE_H__

#include "sort.h"

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
           cmp_e (*cmp)(const void *, const void *))
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

#endif
