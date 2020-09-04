#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge_sort.h"

/************************
 *****INTEGERS_START*****
 ************************/

/* Print integer array
 */
void
print_int_array (int *arr, int size)
{

  int i = 0;

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
int
int_cmp_ascending (const void *p1, const void *p2)
{

  return (*(int *)p1 - *(int *)p2);
}

int
int_cmp_descending (const void *p1, const void *p2)
{

  return (*(int *)p2 - *(int *)p1);
}

/************************
 ******INTEGERS_END******
 ************************/

int
main ()
{

  /*
   * Test for sorting positive integer array 
   * in asceding order
   */
  int arr1[] = {2,0,4,6,8,1,5,3,9,7};
  size_t size1 = 0;

  size1 = sizeof(arr1) / sizeof(int);

  printf("Test for sorting positive integer \
          array in ascending order\n");
  printf("Original array: ");
  print_int_array(arr1, size1);

  merge_sort(arr1, size1, sizeof(int), int_cmp_ascending);

  printf("Sorted   array: ");
  print_int_array(arr1, size1);
  printf("\n");

  /*
   * Test for sorting positive integer array 
   * in descending order
   */
  int arr2[] = {2,0,4,6,8,1,5,3,9,7};
  size_t size2 = 0;

  size2 = sizeof(arr2) / sizeof(int);

  printf("Test for sorting positive integer \
          array in descending order\n");
  printf("Original array: ");
  print_int_array(arr2, size2);

  merge_sort(arr2, size2, sizeof(int), int_cmp_descending);

  printf("Sorted   array: ");
  print_int_array(arr2, size2);
  printf("\n");

  /*
   * Test for sorting negative integer array 
   * in ascendig order
   */
  int arr3[] = {-2,-0,-4,-6,-8,-1,-5,-3,-9,-7};
  size_t size3 = 0;

  size3 = sizeof(arr3) / sizeof(int);

  printf("Test for sorting negative integer \
          array in ascending order\n");
  printf("Original array: ");
  print_int_array(arr3, size3);

  merge_sort(arr3, size3, sizeof(int), int_cmp_ascending);

  printf("Sorted   array: ");
  print_int_array(arr3, size3);
  printf("\n");

  /*
   * Test for sorting negative integer array 
   * in descending order
   */
  int arr4[] = {-2,0,-4,-6,-8,-1,-5,-3,-9,-7};
  size_t size4 = 0;

  size4 = sizeof(arr4) / sizeof(int);

  printf("Test for sorting negative integer \
          array in descending order\n");
  printf("Original array: ");
  print_int_array(arr4, size4);

  merge_sort(arr4, size4, sizeof(int), int_cmp_descending);

  printf("Sorted   array: ");
  print_int_array(arr4, size4);
  printf("\n");

  /*
   * Test for sorting integer array 
   * in ascending order
   */
  int arr5[] = {-2,0,4,6,-8,-1,5,-3,-9,-7,12,3,-2,4};
  size_t size5 = 0;

  size5 = sizeof(arr5) / sizeof(int);

  printf("Test for sorting integer \
          array in ascending order\n");
  printf("Original array: ");
  print_int_array(arr5, size5);

  merge_sort(arr5, size5, sizeof(int), int_cmp_ascending);

  printf("Sorted   array: ");
  print_int_array(arr5, size5);
  printf("\n");

  /*
   * Test for sorting integer array 
   * in descending order
   */
  int arr6[] = {-2,0,4,6,-8,-1,5,-3,-9,-7,12,3,-2,4};
  size_t size6 = 0;

  size6 = sizeof(arr6) / sizeof(int);

  printf("Test for sorting negative integer \
          array in descending order\n");
  printf("Original array: ");
  print_int_array(arr6, size6);

  merge_sort(arr6, size6, sizeof(int), int_cmp_descending);

  printf("Sorted   array: ");
  print_int_array(arr6, size6);
  printf("\n");

#if 0
  /*
   * TEST FOR SORTING POSITIVE FLOAT ARRAY
   * IN ASCENDING ORDER
   */
  float arr2[] = {2,2.5,1,3,7,9,100,2.1,34,5,2.7,4.3};
  size_t size2 = 0;

  size2 = sizeof(arr2) / sizeof(float);

  printf("Origianl array: ");
  print_float_array(arr2, size2);

  merge_sort(arr2, size2, sizeof(float), float_cmp);

  printf("Sorted   array: ");
  print_float_array(arr2, size2);
#endif

  return 0;
}
