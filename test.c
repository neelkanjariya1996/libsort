#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#include "merge_sort.h"

#define ONE_MB_BYTE  1000000

/************************
      INTEGERS_START
 ************************/

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
 * compare function to sort integer 
 * array in ascending order
 */
cmp_e
int_cmp_ascending (const void *k1, const void *k2)
{

  int *p1 = NULL;
  int *p2 = NULL;

  if(!k1 && !k2) {
  
    return MERGESORT_EQ;
  }
  if(!k1) {
  
    return MERGESORT_LT;
  }
  if(!k2) {
  
    return MERGESORT_GT;
  }

  p1 = (int *)k1;
  p2 = (int *)k2;

  if(*p1 < *p2) {
  
    return MERGESORT_LT; 
  } else if(*p1 > *p2) {
  
    return MERGESORT_GT;
  } else {
  
    return MERGESORT_EQ;
  }
}

/*
 * compare function to sort integer
 * array in descending order
 */
cmp_e
int_cmp_descending (const void *k1, const void *k2)
{

  int *p1 = NULL;
  int *p2 = NULL;

  if(!k1 && !k2) {
  
    return MERGESORT_EQ;
  }
  if(!k1) {
  
    return MERGESORT_GT;
  }
  if(!k2) {
  
    return MERGESORT_LT;
  }

  p1 = (int *)k1;
  p2 = (int *)k2;

  if(*p2 < *p1) {
  
    return MERGESORT_LT; 
  } else if(*p2 > *p1) {
  
    return MERGESORT_GT;
  } else {
  
    return MERGESORT_EQ;
  }
}

/*
 * Test for sorting positive integer array 
 * in asceding order
 */
void
int_test_1 ()
{

  int arr[] = {2,0,4,6,8,1,5,3,9,7};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("Test for sorting positive integer"
         " array in ascending order\n");
  printf("Original array: ");
  print_int_array(arr, size);

  merge_sort(arr, size, sizeof(int), int_cmp_ascending);

  printf("Sorted   array: ");
  print_int_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting positive integer array 
 * in descending order
 */
void
int_test_2 ()
{

  int arr[] = {2,0,4,6,8,1,5,3,9,7};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("Test for sorting positive integer"
         " array in descending order\n");
  printf("Original array: ");
  print_int_array(arr, size);

  merge_sort(arr, size, sizeof(int), int_cmp_descending);

  printf("Sorted   array: ");
  print_int_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting negative integer array 
 * in ascendig order
 */
void
int_test_3 ()
{

  int arr[] = {-2,-0,-4,-6,-8,-1,-5,-3,-9,-7};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("Test for sorting negative integer"
         " array in ascending order\n");
  printf("Original array: ");
  print_int_array(arr, size);

  merge_sort(arr, size, sizeof(int), int_cmp_ascending);

  printf("Sorted   array: ");
  print_int_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting negative integer array 
 * in descending order
 */
void
int_test_4 ()
{

  int arr[] = {-2,0,-4,-6,-8,-1,-5,-3,-9,-7};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("Test for sorting negative integer"
         " array in descending order\n");
  printf("Original array: ");
  print_int_array(arr, size);

  merge_sort(arr, size, sizeof(int), int_cmp_descending);

  printf("Sorted   array: ");
  print_int_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting integer array 
 * in ascending order
 */
void
int_test_5 ()
{

  int arr[] = {-2,0,4,6,-8,-1,5,-3,-9,-7,12,3,-2,4};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("Test for sorting integer"
         " array in ascending order\n");
  printf("Original array: ");
  print_int_array(arr, size);

  merge_sort(arr, size, sizeof(int), int_cmp_ascending);

  printf("Sorted   array: ");
  print_int_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting integer array 
 * in descending order
 */
void
int_test_6 ()
{

  int arr[] = {-2,0,4,6,-8,-1,5,-3,-9,-7,12,3,-2,4};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("Test for sorting integer"
          " array in descending order\n");
  printf("Original array: ");
  print_int_array(arr, size);

  merge_sort(arr, size, sizeof(int), int_cmp_descending);

  printf("Sorted   array: ");
  print_int_array(arr, size);
  printf("\n");

  return;
}


/************************
      INTEGERS_END
************************/

/************************
      FLOAT_START
 ************************/

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
 * compare function to sort float 
 * array in ascending order
 */
cmp_e
float_cmp_ascending (const void *k1, const void *k2)
{

  float *p1 = NULL;
  float *p2 = NULL;

  if(!k1 && !k2) {
  
    return MERGESORT_EQ;
  }
  if(!k1) {
  
    return MERGESORT_LT;
  }
  if(!k2) {
  
    return MERGESORT_GT;
  }

  p1 = (float *)k1;
  p2 = (float *)k2;

  if(*p1 < *p2) {
  
    return MERGESORT_LT; 
  } else if(*p1 > *p2) {
  
    return MERGESORT_GT;
  } else {
  
    return MERGESORT_EQ;
  }
}

/*
 * compare function to sort float 
 * array in descending order
 */
cmp_e
float_cmp_descending (const void *k1, const void *k2)
{

  float *p1 = NULL;
  float *p2 = NULL;

  if(!k1 && !k2) {
  
    return MERGESORT_EQ;
  }
  if(!k1) {
  
    return MERGESORT_GT;
  }
  if(!k2) {
  
    return MERGESORT_LT;
  }

  p1 = (float *)k1;
  p2 = (float *)k2;

  if(*p2 < *p1) {
  
    return MERGESORT_LT; 
  } else if(*p2 > *p1) {
  
    return MERGESORT_GT;
  } else {
  
    return MERGESORT_EQ;
  }
}

/*
 * Test for sorting positive float array
 * in ascending order
 */
void
float_test_1 ()
{

  float arr[] = {2,2.5,1,3,7,9,100,2.1,34,5,2.7,4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("Test for sorting positive float"
         " array in ascending order\n");
  printf("Origianl array: ");
  print_float_array(arr, size);

  merge_sort(arr, size, sizeof(float), float_cmp_ascending);

  printf("Sorted   array: ");
  print_float_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting positive float array
 * in descending order
 */
void
float_test_2 ()
{

  float arr[] = {2,2.5,1,3,7,9,100,2.1,34,5,2.7,4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("Test for sorting positive float"
         " array in descending order\n");
  printf("Origianl array: ");
  print_float_array(arr, size);

  merge_sort(arr, size, sizeof(float), float_cmp_descending);

  printf("Sorted   array: ");
  print_float_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting negative float array
 * in ascending order
 */
void
float_test_3 ()
{

  float arr[] = {-2,-2.5,-1,-3,-7,-9,-100,-2.1,-34,-5,-2.7,-4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("Test for sorting positive float"
         " array in ascending order\n");
  printf("Origianl array: ");
  print_float_array(arr, size);

  merge_sort(arr, size, sizeof(float), float_cmp_ascending);

  printf("Sorted   array: ");
  print_float_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting negative float array
 * in descending order
 */
void
float_test_4 ()
{

  float arr[] = {-2,-2.5,-1,-3,-7,-9,-100,-2.1,-34,-5,-2.7,-4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("Test for sorting positive float"
         " array in descending order\n");
  printf("Origianl array: ");
  print_float_array(arr, size);

  merge_sort(arr, size, sizeof(float), float_cmp_descending);

  printf("Sorted   array: ");
  print_float_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting float array
 * in ascending order
 */
void
float_test_5 ()
{

  float arr[] = {-2,2.5,1,-3,-7,9,-100,2.1,-34,5,2.7,-4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("Test for sorting positive float"
         " array in ascending order\n");
  printf("Origianl array: ");
  print_float_array(arr, size);

  merge_sort(arr, size, sizeof(float), float_cmp_ascending);

  printf("Sorted   array: ");
  print_float_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting float array
 * in descending order
 */
void
float_test_6 ()
{

  float arr[] = {-2,2.5,1,-3,-7,9,-100,2.1,-34,5,2.7,-4.3};
  size_t size = 0;

  size = sizeof(arr) / sizeof(float);

  printf("Test for sorting positive float"
         " array in descending order\n");
  printf("Origianl array: ");
  print_float_array(arr, size);

  merge_sort(arr, size, sizeof(float), float_cmp_descending);

  printf("Sorted   array: ");
  print_float_array(arr, size);
  printf("\n");

  return;
}

/************************
       FLOAT_END
 ************************/

/************************
       CHAR_START
 ************************/

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
 * compare function to sort char 
 * array in ascending order
 */
cmp_e
char_cmp_ascending (const void *k1, const void *k2)
{

  char *p1 = NULL;
  char *p2 = NULL;

  if(!k1 && !k2) {
  
    return MERGESORT_EQ;
  }
  if(!k1) {
  
    return MERGESORT_LT;
  }
  if(!k2) {
  
    return MERGESORT_GT;
  }

  p1 = (char *)k1;
  p2 = (char *)k2;

  if(*p1 < *p2) {
  
    return MERGESORT_LT; 
  } else if(*p1 > *p2) {
  
    return MERGESORT_GT;
  } else {
  
    return MERGESORT_EQ;
  }
}

/*
 * compare function to sort char 
 * array in descending order
 */
cmp_e
char_cmp_descending (const void *k1, const void *k2)
{

  char *p1 = NULL;
  char *p2 = NULL;

  if(!k1 && !k2) {
  
    return MERGESORT_EQ;
  }
  if(!k1) {
  
    return MERGESORT_GT;
  }
  if(!k2) {
  
    return MERGESORT_LT;
  }

  p1 = (char *)k1;
  p2 = (char *)k2;

  if(*p2 < *p1) {
  
    return MERGESORT_LT; 
  } else if(*p2 > *p1) {
  
    return MERGESORT_GT;
  } else {
  
    return MERGESORT_EQ;
  }
}

/*
 * Test for sorting capital letters
 * in ascending order
 */
void
char_test_1 ()
{

  char arr[] = "ANFAHPJFA";
  size_t size = 0;

  size = strlen(arr);

  printf("Test for sorting capital letters"
         " in ascending order\n");
  printf("Origianl array: ");
  print_char_array(arr);

  merge_sort(arr, size, sizeof(char), char_cmp_ascending);

  printf("Sorted   array: ");
  print_char_array(arr);
  printf("\n");

  return;
}

/*
 * Test for sorting capital letters
 * in descending order
 */
void
char_test_2 ()
{

  char arr[] = "ANFAHPJFA";
  size_t size = 0;

  size = strlen(arr);

  printf("Test for sorting capital letters"
         " in descending order\n");
  printf("Origianl array: ");
  print_char_array(arr);

  merge_sort(arr, size, sizeof(char), char_cmp_descending);

  printf("Sorted   array: ");
  print_char_array(arr);
  printf("\n");

  return;
}

/*
 * Test for sorting small letters
 * in ascending order
 */
void
char_test_3 ()
{

  char arr[] = "afbajfak";
  size_t size = 0;

  size = strlen(arr);

  printf("Test for sorting small letters"
         " in ascending order\n");
  printf("Origianl array: ");
  print_char_array(arr);

  merge_sort(arr, size, sizeof(char), char_cmp_ascending);

  printf("Sorted   array: ");
  print_char_array(arr);
  printf("\n");

  return;
}

/*
 * Test for sorting small letters
 * in descending order
 */
void
char_test_4 ()
{

  char arr[] = "afbajfak";
  size_t size = 0;

  size = strlen(arr);

  printf("Test for sorting small letters"
         " in descending order\n");
  printf("Origianl array: ");
  print_char_array(arr);

  merge_sort(arr, size, sizeof(char), char_cmp_descending);

  printf("Sorted   array: ");
  print_char_array(arr);
  printf("\n");

  return;
}

/*
 * Test for sorting characters
 * in ascending order
 */
void
char_test_5 ()
{

  char arr[] = "fanj28nfAFfa93fFJaF0";
  size_t size = 0;

  size = strlen(arr);

  printf("Test for sorting characters"
         " in ascending order\n");
  printf("Origianl array: ");
  print_char_array(arr);

  merge_sort(arr, size, sizeof(char), char_cmp_ascending);

  printf("Sorted   array: ");
  print_char_array(arr);
  printf("\n");

  return;
}

/*
 * Test for sorting characters
 * in descending order
 */
void
char_test_6 ()
{

  char arr[] = "fanj28nfAFfa93fFJaF0";
  size_t size = 0;

  size = strlen(arr);

  printf("Test for sorting charcters"
         " in descending order\n");
  printf("Origianl array: ");
  print_char_array(arr);

  merge_sort(arr, size, sizeof(char), char_cmp_descending);

  printf("Sorted   array: ");
  print_char_array(arr);
  printf("\n");

  return;
}

/*
 * Test for sorting special characters
 * in ascending order
 */
void
char_test_7 ()
{

  char arr[] = "*$!&$*$*@$($@)!#";
  size_t size = 0;

  size = strlen(arr);

  printf("Test for sorting charcters"
         " in ascending order\n");
  printf("Origianl array: ");
  print_char_array(arr);

  merge_sort(arr, size, sizeof(char), char_cmp_ascending);

  printf("Sorted   array: ");
  print_char_array(arr);
  printf("\n");

  return;
}

/*
 * Test for sorting special characters
 * in descending order
 */
void
char_test_8 ()
{

  char arr[] = "*$!&$*$*@$($@)!#";
  size_t size = 0;

  size = strlen(arr);

  printf("Test for sorting charcters"
         " in descending order\n");
  printf("Origianl array: ");
  print_char_array(arr);

  merge_sort(arr, size, sizeof(char), char_cmp_descending);

  printf("Sorted   array: ");
  print_char_array(arr);
  printf("\n");

  return;
}

/************************
       CHAR_END
 ************************/

/************************
      POINTS_START
 ************************/

/*
 * structure to represent 
 * a point in 2-D plane
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
 * compare function to sort points 
 * array in ascending order based on
 * x coordinate
 */
cmp_e
point_x_cmp_ascending (const void *k1, const void *k2)
{

  point_t *p1 = NULL;
  point_t *p2 = NULL;

  if(!k1 && !k2) {
  
    return MERGESORT_EQ;
  }
  if(!k1) {
  
    return MERGESORT_LT;
  }
  if(!k2) {
  
    return MERGESORT_GT;
  }

  p1 = (point_t *) k1;
  p2 = (point_t *) k2;

  if(p1->x == p2->x) {
  
    if(p1->y < p2->y) {
    
      return MERGESORT_LT;
    } else if(p1->y > p2->y) {
    
      return MERGESORT_GT;
    } else {
    
      return MERGESORT_EQ;
    }
  } else if(p1->x < p2->x) {
  
    return MERGESORT_LT;
  } else {
  
    return MERGESORT_GT;
  }
}

/*
 * compare function to sort points 
 * array in ascending order based on
 * y coordinate
 */
cmp_e
point_y_cmp_ascending (const void *k1, const void *k2)
{

  point_t *p1 = NULL;
  point_t *p2 = NULL;

  if(!k1 && !k2) {
  
    return MERGESORT_EQ;
  }
  if(!k1) {
  
    return MERGESORT_LT;
  }
  if(!k2) {
  
    return MERGESORT_GT;
  }

  p1 = (point_t *) k1;
  p2 = (point_t *) k2;

  if(p1->y == p2->y) {
  
    if(p1->x < p2->x) {
    
      return MERGESORT_LT;
    } else if(p1->x > p2->x) {
    
      return MERGESORT_GT;
    } else {
    
      return MERGESORT_EQ;
    }
  } else if(p1->y < p2->y) {
  
    return MERGESORT_LT;
  } else {
  
    return MERGESORT_GT;
  }
}

/*
 * compare function to sort points 
 * array in descending order based on
 * x coordinate
 */
cmp_e
point_x_cmp_descending (const void *k1, const void *k2)
{

  point_t *p1 = NULL;
  point_t *p2 = NULL;

  if(!k1 && !k2) {
  
    return MERGESORT_EQ;
  }
  if(!k1) {
  
    return MERGESORT_LT;
  }
  if(!k2) {
  
    return MERGESORT_GT;
  }

  p1 = (point_t *) k1;
  p2 = (point_t *) k2;

  if(p2->x == p1->x) {
  
    if(p2->y < p1->y) {
    
      return MERGESORT_LT;
    } else if(p2->y > p1->y) {
    
      return MERGESORT_GT;
    } else {
    
      return MERGESORT_EQ;
    }
  } else if(p2->x < p1->x) {
  
    return MERGESORT_LT;
  } else {
  
    return MERGESORT_GT;
  }
}

/*
 * compare function to sort points 
 * array in descending order based on
 * y coordinate
 */
cmp_e
point_y_cmp_descending (const void *k1, const void *k2)
{

  point_t *p1 = NULL;
  point_t *p2 = NULL;

  if(!k1 && !k2) {
  
    return MERGESORT_EQ;
  }
  if(!k1) {
  
    return MERGESORT_LT;
  }
  if(!k2) {
  
    return MERGESORT_GT;
  }

  p1 = (point_t *) k1;
  p2 = (point_t *) k2;

  if(p2->y == p1->y) {
  
    if(p2->x < p1->x) {
    
      return MERGESORT_LT;
    } else if(p2->x > p1->x) {
    
      return MERGESORT_GT;
    } else {
    
      return MERGESORT_EQ;
    }
  } else if(p2->y < p1->y) {
  
    return MERGESORT_LT;
  } else {
  
    return MERGESORT_GT;
  }
}

/*
 * Test for sorting points array 
 * in ascending order based on 
 * x coordinate
 */
void
point_t_test_1 ()
{

  point_t arr[] = {{9, 0}, {5, 9}, {1, 7}, {10,2}, {0,100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("Test for sorting points array in "
         "ascending order based on x coordinate\n");
  printf("Original array: ");
  print_points_array(arr, size);

  merge_sort(arr, size, sizeof(point_t), point_x_cmp_ascending);

  printf("Sorted   array: ");
  print_points_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting points array 
 * in ascending order based on 
 * y coordinate
 */
void
point_t_test_2 ()
{

  point_t arr[] = {{9, 0}, {5, 9}, {1, 7}, {10,2}, {0,100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("Test for sorting points array in "
         "ascending order based on y coordinate\n");
  printf("Original array: ");
  print_points_array(arr, size);

  merge_sort(arr, size, sizeof(point_t), point_y_cmp_ascending);

  printf("Sorted   array: ");
  print_points_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting points array 
 * in descending order based on 
 * x coordinate
 */
void
point_t_test_3 ()
{

  point_t arr[] = {{9, 0}, {5, 9}, {1, 7}, {10,2}, {0,100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("Test for sorting points array in "
         "descending order based on x coordinate\n");
  printf("Original array: ");
  print_points_array(arr, size);

  merge_sort(arr, size, sizeof(point_t), point_x_cmp_descending);

  printf("Sorted   array: ");
  print_points_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting points array 
 * in descending order based on 
 * y coordinate
 */
void
point_t_test_4 ()
{

  point_t arr[] = {{9, 0}, {5, 9}, {1, 7}, {10,2}, {0,100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("Test for sorting points array in "
         "descending order based on y coordinate\n");
  printf("Original array: ");
  print_points_array(arr, size);

  merge_sort(arr, size, sizeof(point_t), point_y_cmp_descending);

  printf("Sorted   array: ");
  print_points_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting points array 
 * in ascending order based on 
 * x coordinate
 */
void
point_t_test_5 ()
{

  point_t arr[] = {{9, 0}, {-5, -9}, {1, 7}, {-10,2}, {0,-100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("Test for sorting points array in "
         "ascending order based on x coordinate\n");
  printf("Original array: ");
  print_points_array(arr, size);

  merge_sort(arr, size, sizeof(point_t), point_x_cmp_ascending);

  printf("Sorted   array: ");
  print_points_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting points array 
 * in ascending order based on 
 * y coordinate
 */
void
point_t_test_6 ()
{

  point_t arr[] = {{9, 0}, {-5, -9}, {1, 7}, {-10,2}, {0,-100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("Test for sorting points array in "
         "ascending order based on y coordinate\n");
  printf("Original array: ");
  print_points_array(arr, size);

  merge_sort(arr, size, sizeof(point_t), point_y_cmp_ascending);

  printf("Sorted   array: ");
  print_points_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting points array 
 * in descending order based on 
 * x coordinate
 */
void
point_t_test_7 ()
{

  point_t arr[] = {{9, 0}, {-5, -9}, {1, 7}, {-10,2}, {0,-100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("Test for sorting points array in "
         "descending order based on x coordinate\n");
  printf("Original array: ");
  print_points_array(arr, size);

  merge_sort(arr, size, sizeof(point_t), point_x_cmp_descending);

  printf("Sorted   array: ");
  print_points_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for sorting points array 
 * in descending order based on 
 * y coordinate
 */
void
point_t_test_8 ()
{

  point_t arr[] = {{9, 0}, {-5, -9}, {1, 7}, {-10,2}, {0,-100}};
  size_t size = 0;

  size = sizeof(arr) / sizeof(point_t);

  printf("Test for sorting points array in "
         "descending order based on y coordinate\n");
  printf("Original array: ");
  print_points_array(arr, size);

  merge_sort(arr, size, sizeof(point_t), point_y_cmp_descending);

  printf("Sorted   array: ");
  print_points_array(arr, size);
  printf("\n");

  return;
}

/************************
       POINTS_END
 ************************/


/************************
      GENERAL_START
 ************************/

/*
 * Array passed as NULL
 */
void
test1 ()
{

  int arr[] = {};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);
  printf("Test for empty array: \n");
  printf("Original array: ");
  print_int_array(arr, size);

  merge_sort(NULL, size, sizeof(int), int_cmp_ascending);

  printf("Sorted   array: ");
  print_int_array(arr, size);
  printf("\n");

  return;
}

/*
 * Compare function passed as NULL
 */
void
test2 ()
{

  int arr[] = {20,3,2,3,5,7,4,3,100};
  size_t size = 0;

  size = sizeof(arr) / sizeof(int);
  printf("Test for compare function passed as NULL: \n");
  printf("Original array: ");
  print_int_array(arr, size);

  merge_sort(arr, size, sizeof(int), NULL);

  printf("Sorted   array: ");
  print_int_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for 1MB of integer array
 */
void
test3 ()
{

  int arr[(ONE_MB_BYTE / sizeof(int))];
  size_t size = 0;
  size_t i = 0;
  
  for(i = 0; i < (ONE_MB_BYTE / sizeof(int)); i++) {
  
    arr[i] = (rand() % INT_MAX);
  }

  size = sizeof(arr) / sizeof(int);
  printf("Test for 1MB of integer array: \n");
  printf("Original array: ");
  print_int_array(arr, size);

  merge_sort(arr, size, sizeof(int), int_cmp_ascending);

  printf("Sorted   array: ");
  print_int_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for 1MB of float array
 */
void
test4 ()
{

  float arr[(ONE_MB_BYTE / sizeof(float))];
  size_t size = 0;
  size_t i = 0;
  
  for(i = 0; i < (ONE_MB_BYTE / sizeof(float)); i++) {
  
    arr[i] = (rand() % LONG_MAX);
  }

  size = sizeof(arr) / sizeof(float);
  printf("Test for 1MB of float array: \n");
  printf("Original array: ");
  print_float_array(arr, size);

  merge_sort(arr, size, sizeof(float), float_cmp_ascending);

  printf("Sorted   array: ");
  print_float_array(arr, size);
  printf("\n");

  return;
}

/************************
      GENERAL_END
 ************************/


int
main ()
{

  //used for generating random number
  srand(time(0));

/*
  int_test_1();
  int_test_2();
  int_test_3();
  int_test_4();
  int_test_5();
  int_test_6();
*/

/*
  float_test_1();
  float_test_2();
  float_test_3();
  float_test_4();
  float_test_5();
  float_test_6();
*/

/*  
  char_test_1();
  char_test_2();
  char_test_3();
  char_test_4();
  char_test_5();
  char_test_6();
  char_test_7();
  char_test_8();
*/

/*
  point_t_test_1();
  point_t_test_2();
  point_t_test_3();
  point_t_test_4();
  point_t_test_5();
  point_t_test_6();
  point_t_test_7();
  point_t_test_8();
*/

  //test1();
  //test2();
  //test3();
  //test4();

  return 0;
}
