#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>

#include "sort.h"

#define _1KB      1000
#define _1MB      1000000
#define _128MB    128000000

typedef enum sort_type_e_ {

  MSORT = 0,
  HSORT,
  QSORT,
} sort_type_e;

/*
 * Util function to get the name of the sorting method used
 */
const char *
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
 * Function to sort the array based on the specified type
 */
void
sort (void *arr, size_t arr_size, size_t elem_size,
      cmp_e (*cmp) (const void *, const void *),
      sort_type_e type) {

  switch (type) {
    case MSORT:
      msort(arr, arr_size, elem_size, cmp);
      break;
    case HSORT:
      hsort(arr, arr_size, elem_size, cmp);
      break;
    case QSORT:
      qsort(arr, arr_size, elem_size, cmp);
      break;
    default:
      break;
  }
  return;
}

/*
 * Validation function to check if the array is sorted or not
 */
bool
is_array_sorted (void *arr, size_t arr_size, size_t elem_size,
                 cmp_e (*cmp) (const void *, const void *))
{

  size_t i = 0;
  cmp_e ret;

  for(i = 1; i < arr_size; i++) {
 
    ret = cmp(ARR_LOC(arr, (i - 1), elem_size), ARR_LOC(arr, i, elem_size));
    if(ret == SORT_GT) {
      return (false);
    }
  }

  return true;
}

/***************************************
        TEST_CASES_FOR_INTEGERS
 ***************************************/

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
 * Test for sorting positive integer array in asceding order
 */
bool
int_test_1 (sort_type_e type)
{

  int arr[] = {2,0,4,6,8,1,5,3,9,7};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("%s: Test for sorting positive integer array"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(int), int_cmp_ascending);
}

/*
 * Test for sorting positive integer array in descending order
 */
bool
int_test_2 (sort_type_e type)
{

  int arr[] = {2,0,4,6,8,1,5,3,9,7};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("%s: Test for sorting positive integer array"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(int), int_cmp_descending);
}

/*
 * Test for sorting negative integer array in ascendig order
 */
bool
int_test_3 (sort_type_e type)
{

  int arr[] = {-2,-0,-4,-6,-8,-1,-5,-3,-9,-7};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("%s: Test for sorting negative integer array"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_ascending, type);
  
  return is_array_sorted(arr, size, sizeof(int), int_cmp_ascending);
}

/*
 * Test for sorting negative integer array in descending order
 */
bool
int_test_4 (sort_type_e type)
{

  int arr[] = {-2,0,-4,-6,-8,-1,-5,-3,-9,-7};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("%s: Test for sorting negative integer array"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(int), int_cmp_descending);
}

/*
 * Test for sorting integer array in ascending order
 */
bool
int_test_5 (sort_type_e type)
{

  int arr[] = {-2,0,4,6,-8,-1,5,-3,-9,-7,12,3,-2,4};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("%s: Test for sorting integer array"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(int), int_cmp_ascending);
}

/*
 * Test for sorting integer array in descending order
 */
bool
int_test_6 (sort_type_e type)
{

  int arr[] = {-2,0,4,6,-8,-1,5,-3,-9,-7,12,3,-2,4};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("%s: Test for sorting integer array"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(int), int_cmp_descending);
}

/*
 * Test for sorting integer array of size 1 in ascending order
 */
bool
int_test_7 (sort_type_e type)
{

  int arr[] = {-2};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("%s: Test for sorting integer arrayof size 1"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(int), int_cmp_ascending);
}

/*
 * Test for sorting integer array of size 2 in ascending order
 */
bool
int_test_8 (sort_type_e type)
{

  int arr[] = {-2, -10};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("%s: Test for sorting integer array of size 1"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(int), int_cmp_ascending);
}

/*
 * Test for sorting integer array with all elements equal in ascending order
 */
bool
int_test_9 (sort_type_e type)
{

  int arr[] = {-1,-1,-1,-1,-1,-1,-1};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("%s: Test for sorting integer array with all elements equal"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(int), int_cmp_ascending);
}

/***************************************
      TEST_CASES_FOR_INTEGERS_END
 ***************************************/

/***************************************
        TEST_CASES_FOR_FLOAT
 ***************************************/

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
 * Test for sorting positive float array in ascending order
 */
bool
float_test_1 (sort_type_e type)
{

  float arr[] = {2,2.5,1,3,7,9,100,2.1,34,5,2.7,4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("%s: Test for sorting positive float array"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(float), float_cmp_ascending);
}

/*
 * Test for sorting positive float array in descending order
 */
bool
float_test_2 (sort_type_e type)
{

  float arr[] = {2,2.5,1,3,7,9,100,2.1,34,5,2.7,4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("%s: Test for sorting positive float array"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(float), float_cmp_descending);
}

/*
 * Test for sorting negative float array in ascending order
 */
bool
float_test_3 (sort_type_e type)
{

  float arr[] = {-2,-2.5,-1,-3,-7,-9,-100,-2.1,-34,-5,-2.7,-4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("%s: Test for sorting positive float array"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(float), float_cmp_ascending);
}

/*
 * Test for sorting negative float array in descending order
 */
bool
float_test_4 (sort_type_e type)
{

  float arr[] = {-2,-2.5,-1,-3,-7,-9,-100,-2.1,-34,-5,-2.7,-4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("%s: Test for sorting positive float array"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(float), float_cmp_descending);
}

/*
 * Test for sorting float array in ascending order
 */
bool
float_test_5 (sort_type_e type)
{

  float arr[] = {-2,2.5,1,-3,-7,9,-100,2.1,-34,5,2.7,-4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("%s: Test for sorting positive float array"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(float), float_cmp_ascending);
}

/*
 * Test for sorting float array in descending order
 */
bool
float_test_6 (sort_type_e type)
{

  float arr[] = {-2,2.5,1,-3,-7,9,-100,2.1,-34,5,2.7,-4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("%s: Test for sorting positive float "
         "array in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(float), float_cmp_descending);
}

/*
 * Test for sorting float array of size 1 in descending order
 */
bool
float_test_7 (sort_type_e type)
{

  float arr[] = {-2};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("%s: Test for sorting float array of size 1"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(float), float_cmp_descending);
}

/*
 * Test for sorting float array of size 2 in ascending order
 */
bool
float_test_8 (sort_type_e type)
{

  float arr[] = {2,-10};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("%s: Test for sorting float array of size 2"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(float), float_cmp_ascending);
}

/*
 * Test for sorting float array with all elements equal in ascending order
 */
bool
float_test_9 (sort_type_e type)
{

  float arr[] = {2,2,2,2,2,2,2,2};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("%s: Test for sorting float array with all elements equal"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(float), float_cmp_ascending);
}

/***************************************
      TEST_CASES_FOR_FLOAT_END
 ***************************************/

/***************************************
         TEST_CASES_FOR_CHAR
 ***************************************/

/*
 * Function to print character array
 */
void
print_char_array (char *arr)
{

  size_t len = 0;

  if(!arr) {

    return;
  }

  len = strlen(arr);

  printf("%s ", arr);
  printf("\n");

  return;
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
 * Test for sorting capital letters in ascending order
 */
bool
char_test_1 (sort_type_e type)
{

  char arr[] = "ANFAHPJFA";
  size_t size = 0;

  size = strlen(arr);

  printf("%s: Test for sorting capital letters"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(char), char_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(char), char_cmp_ascending);
}

/*
 * Test for sorting capital letters in descending order
 */
bool
char_test_2 (sort_type_e type)
{

  char arr[] = "ANFAHPJFA";
  size_t size = 0;

  size = strlen(arr);

  printf("%s: Test for sorting capital letters"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(char), char_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(char), char_cmp_descending);
}

/*
 * Test for sorting small letters in ascending order
 */
bool
char_test_3 (sort_type_e type)
{

  char arr[] = "afbajfak";
  size_t size = 0;

  size = strlen(arr);

  printf("%s: Test for sorting small letters"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(char), char_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(char), char_cmp_ascending);
}

/*
 * Test for sorting small letters in descending order
 */
bool
char_test_4 (sort_type_e type)
{

  char arr[] = "afbajfak";
  size_t size = 0;

  size = strlen(arr);

  printf("%s: Test for sorting small letters"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(char), char_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(char), char_cmp_descending);
}

/*
 * Test for sorting characters in ascending order
 */
bool
char_test_5 (sort_type_e type)
{

  char arr[] = "fanj28nfAFfa93fFJaF0";
  size_t size = 0;

  size = strlen(arr);

  printf("%s: Test for sorting characters"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(char), char_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(char), char_cmp_ascending);
}

/*
 * Test for sorting characters in descending order
 */
bool
char_test_6 (sort_type_e type)
{

  char arr[] = "fanj28nfAFfa93fFJaF0";
  size_t size = 0;

  size = strlen(arr);

  printf("%s: Test for sorting charcters"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(char), char_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(char), char_cmp_descending);
}

/*
 * Test for sorting special characters in ascending order
 */
bool
char_test_7 (sort_type_e type)
{

  char arr[] = "*$!&$*$*@$($@)!#";
  size_t size = 0;

  size = strlen(arr);

  printf("%s: Test for sorting charcters"
         " in ascending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(char), char_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(char), char_cmp_ascending);
}

/*
 * Test for sorting special characters in descending order
 */
bool
char_test_8 (sort_type_e type)
{

  char arr[] = "*$!&$*$*@$($@)!#";
  size_t size = 0;

  size = strlen(arr);

  printf("%s: Test for sorting charcters"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(char), char_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(char), char_cmp_descending);
}

/*
 * Test for sorting character array of size 1 in descending order
 */
bool
char_test_9 (sort_type_e type)
{

  char arr[] = "a";
  size_t size = 0;

  size = strlen(arr);

  printf("%s: Test for sorting charcter array of size 1"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(char), char_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(char), char_cmp_descending);
}

/*
 * Test for sorting character array of size 2 in descending order
 */
bool
char_test_10 (sort_type_e type)
{

  char arr[] = "ad";
  size_t size = 0;

  size = strlen(arr);

  printf("%s: Test for sorting charcter array of size 2"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(char), char_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(char), char_cmp_descending);
}

/*
 * Test for sorting character array with all elements same in descending order
 */
bool
char_test_11 (sort_type_e type)
{

  char arr[] = "bbbbbbbbbbbbbbbb";
  size_t size = 0;

  size = strlen(arr);

  printf("%s: Test for sorting charcter array of size 2"
         " in descending order -> ", sort_type2str(type));

  sort(arr, size, sizeof(char), char_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(char), char_cmp_descending);
}

/***************************************
       TEST_CASES_FOR_CHAR_END
 ***************************************/

/***************************************
         TEST_CASES_FOR_POINTS
 ***************************************/

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

/*
 * Test for sorting points array in
 * ascending order based on x coordinate
 */
bool
point_t_test_1 (sort_type_e type)
{

  point_t arr[] = {{9, 0}, {5, 9}, {1, 7}, {10,2}, {0,100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("%s: Test for sorting points array in ascending"
         " order based on x coordinate -> ", sort_type2str(type));

  sort(arr, size, sizeof(point_t), point_x_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(point_t), point_x_cmp_ascending);
}

/*
 * Test for sorting points array in 
 * ascending order based on y coordinate
 */
bool
point_t_test_2 (sort_type_e type)
{

  point_t arr[] = {{9, 0}, {5, 9}, {1, 7}, {10,2}, {0,100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("%s: Test for sorting points array in ascending"
         " order based on y coordinate -> ", sort_type2str(type));

  sort(arr, size, sizeof(point_t), point_y_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(point_t), point_y_cmp_ascending);
}

/*
 * Test for sorting points array in
 * descending order based on x coordinate
 */
bool
point_t_test_3 (sort_type_e type)
{

  point_t arr[] = {{9, 0}, {5, 9}, {1, 7}, {10,2}, {0,100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("%s: Test for sorting points array in descending"
         " order based on x coordinate -> ", sort_type2str(type));

  sort(arr, size, sizeof(point_t), point_x_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(point_t), point_x_cmp_descending);
}

/*
 * Test for sorting points array in
 * descending order based on y coordinate
 */
bool
point_t_test_4 (sort_type_e type)
{

  point_t arr[] = {{9, 0}, {5, 9}, {1, 7}, {10,2}, {0,100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("%s: Test for sorting points array in descending"
         " order based on y coordinate -> ", sort_type2str(type));

  sort(arr, size, sizeof(point_t), point_y_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(point_t), point_y_cmp_descending);
}

/*
 * Test for sorting points array in
 * ascending order based on x coordinate
 */
bool
point_t_test_5 (sort_type_e type)
{

  point_t arr[] = {{9, 0}, {-5, -9}, {1, 7}, {-10,2}, {0,-100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("%s: Test for sorting points array in ascending"
         " order based on x coordinate -> ", sort_type2str(type));

  sort(arr, size, sizeof(point_t), point_x_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(point_t), point_x_cmp_ascending);
}

/*
 * Test for sorting points array in
 * ascending order based on y coordinate
 */
bool
point_t_test_6 (sort_type_e type)
{

  point_t arr[] = {{9, 0}, {-5, -9}, {1, 7}, {-10,2}, {0,-100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("%s: Test for sorting points array in ascending"
         " order based on y coordinate -> ", sort_type2str(type));

  sort(arr, size, sizeof(point_t), point_y_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(point_t), point_y_cmp_ascending);
}

/*
 * Test for sorting points array in
 * descending order based on x coordinate
 */
bool
point_t_test_7 (sort_type_e type)
{

  point_t arr[] = {{9, 0}, {-5, -9}, {1, 7}, {-10,2}, {0,-100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("%s: Test for sorting points array in descending"
         " order based on x coordinate -> ", sort_type2str(type));

  sort(arr, size, sizeof(point_t), point_x_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(point_t), point_x_cmp_descending);
}

/*
 * Test for sorting points array in
 * descending order based on y coordinate
 */
bool
point_t_test_8 (sort_type_e type)
{

  point_t arr[] = {{9, 0}, {-5, -9}, {1, 7}, {-10,2}, {0,-100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("%s: Test for sorting points array in descending"
        " order based on y coordinate -> ", sort_type2str(type));

  sort(arr, size, sizeof(point_t), point_y_cmp_descending, type);

  return is_array_sorted(arr, size, sizeof(point_t), point_y_cmp_descending);
}


/***************************************
       TEST_CASES_FOR_POINTS_END
 ***************************************/

/**************************************
            GENERAL_TEST
 *************************************/

/*
 * Array passed as NULL
 */
bool
test_1 (sort_type_e type)
{

  int arr[] = {};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);
 
  printf("%s: Test for empty array -> ", sort_type2str(type));

  sort(NULL, size, sizeof(int), int_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(int), int_cmp_ascending);
}

/*
 * Compare function passed as NULL
 */
bool
test_2 (sort_type_e type)
{

  int arr[] = {20,3,2,3,5,7,4,3,100};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("%s: Test for compare function passed as NULL -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), NULL, type);

  return is_array_sorted(arr, size, sizeof(int), int_cmp_ascending);
}

/*
 * Test for 1KB of integer array
 */
bool
test_3 (sort_type_e type)
{

  int arr[(_1KB / sizeof(int))];
  size_t size = 0;
  size_t i = 0;
  
  for(i = 0; i < (_1KB / sizeof(int)); i++) {
  
    arr[i] = (rand() % INT_MAX);
  }

  size = sizeof(arr) / sizeof(int);

  printf("%s: Test for 1KB of integer array -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(int), int_cmp_ascending);

}

/*
 * Test for 1KB of float array
 */
bool
test_4 (sort_type_e type)
{

  float arr[(_1KB / sizeof(float))];
  size_t size = 0;
  size_t i = 0;
  
  for(i = 0; i < (_1KB / sizeof(float)); i++) {
  
    arr[i] = (rand() % LONG_MAX);
  }

  size = sizeof(arr) / sizeof(float);

  printf("%s: Test for 1KB of float array -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_ascending, type);

  return is_array_sorted(arr, size, sizeof(float), float_cmp_ascending);
}

/*
 * Test for 1MB of integer array
 */
bool
test_5 (sort_type_e type)
{

  int *arr;
  size_t size = 0;
  size_t i = 0;
  bool ret = false;
 
  size = (_1MB / sizeof(int));

  arr = malloc(size * sizeof(int));
  if(!arr) {
  
    printf("Malloc Failure\n");
    return ret;
  }

  for(i = 0; i < (_1MB / sizeof(int)); i++) {
  
    arr[i] = (rand() % INT_MAX);
  }

  printf("%s: Test for 1MB of integer array -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_ascending, type);

  print_int_array(arr, size);

  ret = is_array_sorted(arr, size, sizeof(int), int_cmp_ascending);

  if(arr) {
  
    free(arr);
  }

  return ret;
}

/*
 * Test for 1MB of float array
 */
bool
test_6 (sort_type_e type)
{

  float *arr;
  size_t size = 0;
  size_t i = 0;
  bool ret = false;
  
  size = (_1MB / sizeof(float));

  arr = malloc(size * sizeof(float));
  if(!arr) {
  
    printf("Malloc Failure\n");
    return ret;
  }

  for(i = 0; i < (_1MB / sizeof(float)); i++) {
  
    arr[i] = (rand() % LONG_MAX);
  }

  size = sizeof(arr) / sizeof(float);

  printf("%s: Test for 1MB of float array -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_ascending, type);

  ret = is_array_sorted(arr, size, sizeof(float), float_cmp_ascending);

  if(arr) {
  
    free(arr);
  }

  return ret;
}

/*
 * Test for 128MB of integer array
 */
bool
test_7 (sort_type_e type)
{

  int *arr;
  size_t size = 0;
  size_t i = 0;
  bool ret = false;
 
  size = _128MB / sizeof(int);

  arr = malloc(size * sizeof(int));
  if(!arr) {
  
    printf("Malloc Failure\n");
    return ret;
  }

  for(i = 0; i < size; i++) {
  
    arr[i] = (rand() % INT_MAX);
  }

  printf("%s: Test for 128MB of integer array -> ", sort_type2str(type));

  sort(arr, size, sizeof(int), int_cmp_ascending, type);

  ret = is_array_sorted(arr, size, sizeof(int), int_cmp_ascending);

  if(arr) {
  
    free(arr);
  }

  return ret;
}

/*
 * Test for 128MB of float array
 */
bool
test_8 (sort_type_e type)
{

  float *arr;
  size_t size = 0;
  size_t i = 0;
  bool ret = false;

  size = _128MB / sizeof(float);

  arr = malloc(size * sizeof(float));
  if(!arr) {
  
    printf("Malloc Failure\n");
    return ret;
  }

  for(i = 0; i < size; i++) {
  
    arr[i] = (rand() % LONG_MAX);
  }

  printf("%s: Test for 128MB of float array -> ", sort_type2str(type));

  sort(arr, size, sizeof(float), float_cmp_ascending, type);

  ret = is_array_sorted(arr, size, sizeof(float), float_cmp_ascending);

  if(arr) {
  
    free(arr);
  }

  return ret;
}

/**************************************
          GENERAL_TEST_ENDS
 *************************************/

/***************************************
 *          TEST_FUNCTION
 ***************************************/

void
test_for_int_arr (sort_type_e type)
{
  
  if(int_test_1(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(int_test_2(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(int_test_3(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(int_test_4(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(int_test_5(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(int_test_6(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(int_test_7(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(int_test_8(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(int_test_9(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

}

void
test_for_float_arr (sort_type_e type)
{
  
  if(float_test_1(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(float_test_2(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(float_test_3(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(float_test_4(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(float_test_5(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(float_test_6(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(float_test_7(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(float_test_8(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(float_test_9(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

}

void
test_for_char_arr (sort_type_e type)
{

  if(char_test_1(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(char_test_2(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(char_test_3(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(char_test_4(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(char_test_5(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(char_test_6(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(char_test_7(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(char_test_8(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(char_test_9(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(char_test_10(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(char_test_11(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

}

void
test_for_points_arr (sort_type_e type)
{

  if(point_t_test_1(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(point_t_test_2(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(point_t_test_3(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(point_t_test_4(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(point_t_test_5(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(point_t_test_6(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(point_t_test_7(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(point_t_test_8(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

}
  
void
test_for_arr (sort_type_e type)
{
  
  
  if(test_1(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }
/*
  if(test_2(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }
*/
  if(test_3(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(test_4(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }
/*
  if(test_5(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(test_6(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(test_7(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }

  if(test_8(type)) {
  
    printf("%s\n", "SUCCESS");
  } else {
  
    printf("%s\n", "FAILURE");
  }
*/
}

void
test_cases ()
{

  size_t i = 0;

  //used for generating random number
  srand(time(0));
  
  for(i = MSORT; i <= QSORT; i++) {
  
    test_for_int_arr(i);
    test_for_float_arr(i);
    test_for_char_arr(i);
    test_for_points_arr(i);
    test_for_arr(i);
    printf("\n\n");
  }

  return;
}

/***************************************
 *        TEST_FUNCTION_END
 ***************************************/

/***************************************
 *          MAIN_FUNCTION
 ***************************************/

int
main ()
{

  test_cases();

  return 0;
}
