/*
 * File name: test_private.h
 * Author: Neel Kanjaria
 * Description: Header file for unit test framework
 * Defines various macros, utility functions and structures
 * needed in test.c
 */

#ifndef __TEST_CMP_FNC_H__

#define __TEST_CMP_FNC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

#include "../lib/sort.h"

#define NAME_SIZE           255
#define NUM_CASES           45
#define ALPHABETS           26
#define SPECIAL_CHARACTERS  15

#define ARR_SIZE_1          1
#define ARR_SIZE_2          2
#define ARR_SIZE_10         10

#define _1KB                1000
#define _1MB                1000000
#define _128MB              128000000
#define _256MB              256000000
#define _512MB              512000000
#define _1GB                1000000000

#define ARR_LOC(arr, ind, elem_size) (arr + (ind * elem_size))

/*
 * Enum to represent the sort types
 */
typedef enum sort_type_e_ {

  MSORT = 0,
  HSORT,
  QSORT,
} sort_type_e;

/*
 * Enum to represent all test cases
 */
typedef enum test_cases_e_ {

  INT_TEST_1 = 0,
  INT_TEST_2,
  INT_TEST_3,
  INT_TEST_4,
  INT_TEST_5,
  INT_TEST_6,
  INT_TEST_7,
  INT_TEST_8,
  INT_TEST_9,
  FLOAT_TEST_1,
  FLOAT_TEST_2,
  FLOAT_TEST_3,
  FLOAT_TEST_4,
  FLOAT_TEST_5,
  FLOAT_TEST_6,
  FLOAT_TEST_7,
  FLOAT_TEST_8,
  FLOAT_TEST_9,
  CHAR_TEST_1,
  CHAR_TEST_2,
  CHAR_TEST_3,
  CHAR_TEST_4,
  CHAR_TEST_5,
  CHAR_TEST_6,
  CHAR_TEST_7,
  CHAR_TEST_8,
  CHAR_TEST_9,
  CHAR_TEST_10,
  CHAR_TEST_11,
  POINT_T_TEST_1,
  POINT_T_TEST_2,
  POINT_T_TEST_3,
  POINT_T_TEST_4,
  POINT_T_TEST_5,
  POINT_T_TEST_6,
  POINT_T_TEST_7,
  POINT_T_TEST_8,
  TEST_1,
  TEST_2,
  TEST_3,
  TEST_4,
  TEST_5,
  TEST_6,
  TEST_7,
  TEST_8,
} test_cases_e;

/*
 * Util function to get the name of the sorting method used
 */
static inline const char *
sort_type2str (sort_type_e type)
{
  switch (type) {
    case MSORT:
      return ("merge-sort");
    case HSORT:
      return ("heap-sort");
    case QSORT:
      return ("quick-sort");
    default:
      break;
  }

  return ("n/a");
}

/*
 * Function to print integer array
 */
void
print_int_array (int *arr, size_t size)
{
  size_t i = 0;

  if(!arr) {
    return;
  }

  for(i = 0; i < size; i++) {
  
    printf("%d ", arr[i]);
  }
  printf("\n");

  return;
}

/*
 * compare function to sort integer array in ascending order
 */
cmp_e
int_cmp_ascending (const void *k1, const void *k2)
{
  int *p1 = NULL;
  int *p2 = NULL;

  if(!k1 && !k2) {
    return SORT_EQ;
  }

  if(!k1) {
    return SORT_LT;
  }

  if(!k2) {
    return SORT_GT;
  }

  p1 = (int *)k1;
  p2 = (int *)k2;

  if(*p1 < *p2) {
    return SORT_LT; 
  } else if(*p1 > *p2) {
    return SORT_GT;
  } else {
    return SORT_EQ;
  }
}

/*
 * compare function to sort integer array in descending order
 */
cmp_e
int_cmp_descending (const void *k1, const void *k2)
{
  return ((-1) * int_cmp_ascending(k1, k2));
}

/* 
 * Function to print float array
 */
void
print_float_array (float *arr, size_t size)
{
  size_t i = 0;

  if(!arr) {
    return;
  }

  for(i = 0; i < size; i++) {
  
    printf("%.2f ", arr[i]);
  }
  printf("\n");

  return;
}

/*
 * compare function to sort float array in ascending order
 */
cmp_e
float_cmp_ascending (const void *k1, const void *k2)
{
  float *p1 = NULL;
  float *p2 = NULL;

  if(!k1 && !k2) {
    return SORT_EQ;
  }
  if(!k1) {
    return SORT_LT;
  }
  if(!k2) {
    return SORT_GT;
  }

  p1 = (float *)k1;
  p2 = (float *)k2;

  if(*p1 < *p2) {
    return SORT_LT; 
  } else if(*p1 > *p2) {
    return SORT_GT;
  } else {
    return SORT_EQ;
  }
}

/*
 * compare function to sort float array in descending order
 */
cmp_e
float_cmp_descending (const void *k1, const void *k2)
{
  return ((-1) * float_cmp_ascending(k1, k2));
}

/*
 * compare function to sort char array in ascending order
 */
cmp_e
char_cmp_ascending (const void *k1, const void *k2)
{
  char *p1 = NULL;
  char *p2 = NULL;

  if(!k1 && !k2) {
    return SORT_EQ;
  }
  if(!k1) {
    return SORT_LT;
  }
  if(!k2) {
    return SORT_GT;
  }

  p1 = (char *)k1;
  p2 = (char *)k2;

  if(*p1 < *p2) {
    return SORT_LT; 
  } else if(*p1 > *p2) {
    return SORT_GT;
  } else {
    return SORT_EQ;
  }
}

/*
 * compare function to sort char array in descending order
 */
cmp_e
char_cmp_descending (const void *k1, const void *k2)
{

  return ((-1) * char_cmp_ascending(k1, k2));
}

/*
 * structure to represent a point in 2-D plane
 */
typedef struct point_t_ {

  int x;
  int y;
} point_t;

/*
 * Function to print points array
 */
void
print_points_array (point_t *arr, size_t size)
{
  size_t i = 0;

  if(!arr) {
    return;
  }

  for(i = 0; i < size; i++) {
  
    printf("(%d, %d) ", arr[i].x, arr[i].y);
  }
  printf("\n");

  return;
}

/*
 * compare function to sort points array in 
 * ascending order based on x coordinate
 */
cmp_e
point_x_cmp_ascending (const void *k1, const void *k2)
{
  point_t *p1 = NULL;
  point_t *p2 = NULL;

  if(!k1 && !k2) {
    return SORT_EQ;
  }
  if(!k1) {
    return SORT_LT;
  }
  if(!k2) {
    return SORT_GT;
  }

  p1 = (point_t *) k1;
  p2 = (point_t *) k2;

  if(p1->x == p2->x) {
  
    if(p1->y < p2->y) {
      return SORT_LT;
    } else if(p1->y > p2->y) {
      return SORT_GT;
    } else {
      return SORT_EQ;
    }
  } else if(p1->x < p2->x) {
    return SORT_LT;
  } else {
    return SORT_GT;
  }
}

/*
 * compare function to sort points  array in
 * ascending order based on y coordinate
 */
cmp_e
point_y_cmp_ascending (const void *k1, const void *k2)
{
  point_t *p1 = NULL;
  point_t *p2 = NULL;

  if(!k1 && !k2) {
    return SORT_EQ;
  }
  if(!k1) {
    return SORT_LT;
  }
  if(!k2) {
    return SORT_GT;
  }

  p1 = (point_t *) k1;
  p2 = (point_t *) k2;

  if(p1->y == p2->y) {
  
    if(p1->x < p2->x) {
      return SORT_LT;
    } else if(p1->x > p2->x) {
      return SORT_GT;
    } else {
      return SORT_EQ;
    }
  } else if(p1->y < p2->y) {
    return SORT_LT;
  } else {
    return SORT_GT;
  }
}

/*
 * compare function to sort points  array in
 * descending order based on x coordinate
 */
cmp_e
point_x_cmp_descending (const void *k1, const void *k2)
{
  return ((-1) * point_x_cmp_ascending(k1, k2));
}

/*
 * compare function to sort points  array in
 * descending order based on y coordinate
 */
cmp_e
point_y_cmp_descending (const void *k1, const void *k2)
{
  return ((-1) * point_y_cmp_ascending(k1, k2));
}

#endif
