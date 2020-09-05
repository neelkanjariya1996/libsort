#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge_sort.h"

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

  if(!arr)
    return;

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
int_cmp_ascending (const void *p1, const void *p2)
{

  if((*(int *)p1 - *(int *)p2) < 0) {
  
    return MERGESORT_LT; 
  } else if((*(int *)p1 - *(int *)p2) > 0) {
  
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
int_cmp_descending (const void *p1, const void *p2)
{

  if((*(int *)p2 - *(int *)p1) < 0) {
  
    return MERGESORT_LT; 
  } else if((*(int *)p2 - *(int *)p1) > 0) {
  
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

  if(!arr)
    return;

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
float_cmp_ascending (const void *p1, const void *p2)
{

  if((*(float *)p1 - *(float *)p2) < 0) {
  
    return MERGESORT_LT;
  }else if((*(float *)p1 - *(float *)p2) > 0) {
  
    return MERGESORT_GT;
  } else {
  
    return MERGESORT_EQ;
  }
}

/*
 * compare function to sort float 
 * array in descending order
 */
int
float_cmp_descending (const void *p1, const void *p2)
{

  if((*(float *)p2 - *(float *)p1) < 0) {
  
    return MERGESORT_LT;
  }else if((*(float *)p2 - *(float *)p1) > 0) {
  
    return MERGESORT_GT;
  } else {
  
    return MERGESORT_EQ;
  }
}

void
float_test_1 ()
{

  /*
   * Test for sorting positive float array
   * in ascending order
   */
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

void
float_test_2 ()
{

  /*
   * Test for sorting positive float array
   * in descending order
   */
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

void
float_test_3 ()
{

  /*
   * Test for sorting negative float array
   * in ascending order
   */
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

void
float_test_4 ()
{

  /*
   * Test for sorting negative float array
   * in descending order
   */
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

void
float_test_5 ()
{

  /*
   * Test for sorting float array
   * in ascending order
   */
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

void
float_test_6 ()
{

  /*
   * Test for sorting float array
   * in descending order
   */
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

int
main ()
{

  int_test_1();
  int_test_2();
  int_test_3();
  int_test_4();
  int_test_5();
  int_test_6();

  float_test_1();
  float_test_2();
  float_test_3();
  float_test_4();
  float_test_5();
  float_test_6();

  return 0;
}
