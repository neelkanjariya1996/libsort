#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

#include "sort.h"
#include "test_cmp_fnc.h"

#define NAME_SIZE     255
#define NUM_CASES     18

#define ARR_SIZE_1    1
#define ARR_SIZE_2    2
#define ARR_SIZE_10   10

#define _1KB      1000
#define _1MB      1000000
#define _128MB    128000000

typedef enum sort_type_e_ {

  MSORT = 0,
  HSORT,
  QSORT,
} sort_type_e;

typedef enum test_cases_e_ {

  int_test_1 = 0,
  int_test_2,
  int_test_3,
  int_test_4,
  int_test_5,
  int_test_6,
  int_test_7,
  int_test_8,
  int_test_9,
  float_test_1,
  float_test_2,
  float_test_3,
  float_test_4,
  float_test_5,
  float_test_6,
  float_test_7,
  float_test_8,
  float_test_9,
  char_test_1,
  char_test_2,
  char_test_3,
  char_test_4,
  char_test_5,
  char_test_6,
  char_test_7,
  char_test_8,
  char_test_9,
  char_test_10,
  char_test_11,
  point_t_test_1,
  point_t_test_2,
  point_t_test_3,
  point_t_test_4,
  point_t_test_5,
  point_t_test_6,
  point_t_test_7,
  point_t_test_8,
  test_1,
  test_2,
  test_3,
  test_4,
  test_5,
  test_6,
  test_7,
  test_8,
} test_cases_e;

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

void
generate_input (void **arr, size_t *arr_size, 
                size_t *elem_size, char *name, uint8_t name_size,
                cmp_e (*cmp) (const void *, const void *),
                test_cases_e t_case)
{

  int *int_a;
  float *float_a;
  char *char_a;
  point_t *point_t_a;
  size_t i = 0;

  switch(t_case) {
 
    /*
     * Integer test cases
     */
    case int_test_1:
      
      /*
       * Test for sorting positive integer array in asceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        int_a[i] = (rand() % INT_MAX);
        if(int_a[i] < 0) {
        
          int_a[i] *= (-1);
        }
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting positive integer "
                    "array in ascending order", name_size);
      cmp = int_cmp_ascending;
    break;
    case int_test_2:
    
      /*
       * Test for sorting positive integer array in desceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        int_a[i] = (rand() % INT_MAX);
        if(int_a[i] < 0) {
        
          int_a[i] *= (-1);
        }
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting positive integer "
                    "array in descending order", name_size);
      cmp = int_cmp_descending;
    break;
    case int_test_3:
    
      /*
       * Test for sorting negative integer array in asceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        int_a[i] = (rand() % INT_MAX);
        if(int_a[i] > 0) {
        
          int_a[i] *= (-1);
        }
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting negative integer "
                    "array in ascending order", name_size);
      cmp = int_cmp_ascending;
    break;
    case int_test_4:
    
      /*
       * Test for sorting negative integer array in desceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        int_a[i] = (rand() % INT_MAX);
        if(int_a[i] > 0) {
        
          int_a[i] *= (-1);
        }
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting negative integer "
                    "array in descending order", name_size);
      cmp = int_cmp_descending;
    break;
    case int_test_5:
    
      /*
       * Test for sorting integer array in asceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        int_a[i] = (rand() % INT_MAX);
        if(((i % 2) == 0) && (int_a[i] > 0)) {
        
          int_a[i] *= (-1);
        } else if(((i % 2) == 1) && (int_a[i] < 0)){
        
          int_a[i] *= (-1);
        }
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting integer "
                    "array in ascending order", name_size);
      cmp = int_cmp_ascending;
    break;
    case int_test_6:
    
      /*
       * Test for sorting integer array in desceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        int_a[i] = (rand() % INT_MAX);
        if(((i % 2) == 0) && (int_a[i] > 0)) {
        
          int_a[i] *= (-1);
        } else if(((i % 2) == 1) && (int_a[i] < 0)){
        
          int_a[i] *= (-1);
        }
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting integer "
                    "array in descending order", name_size);
      cmp = int_cmp_descending;
    break;
    case int_test_7:
    
      /*
       * Test for sorting integer array of size 1 in asceding order
       */
      int_a = malloc(ARR_SIZE_1 * sizeof(int));
      if(!int_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_1; i++) {
      
        int_a[i] = (rand() % INT_MAX);
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting integer array "
              " of size 1 in ascending order", name_size);
      cmp = int_cmp_ascending;
    break;
    case int_test_8:
    
      /*
       * Test for sorting integer array of size 2 in asceding order
       */
      int_a = malloc(ARR_SIZE_2 * sizeof(int));
      if(!int_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_2; i++) {
      
        int_a[i] = (rand() % INT_MAX);
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting integer array "
              " of size 2 in ascending order", name_size);
      cmp = int_cmp_ascending;
    break;
    case int_test_9:
    
      /*
       * Test for sorting integer array with all elements 
       * equal in asceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        int_a[i] = -1;
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting integer array with all"
              " elements equal in ascending order", name_size);
      cmp = int_cmp_ascending;
    break;

    /*
     * Float test cases
     */
    case float_test_1:

    /*
     * Test for sorting positive float array in ascending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        float_a[i] = ((float)rand() / (float)(RAND_MAX/rand()));
        if(float_a[i] < 0) {
        
          float_a[i] *= (-1);
        }
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting positive float array"
                    " in ascending order", name_size);
      cmp = float_cmp_ascending;
    break;
    case float_test_2:

    /*
     * Test for sorting positive float array in descending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        float_a[i] = ((float)rand() / (float)(RAND_MAX/rand()));
        if(float_a[i] < 0) {
        
          float_a[i] *= (-1);
        }
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting positive float array"
                    " in descending order", name_size);
      cmp = float_cmp_descending;
    break;
    case float_test_3:

    /*
     * Test for sorting negative float array in ascending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        float_a[i] = ((float)rand() / (float)(RAND_MAX/rand()));
        if(float_a[i] > 0) {
        
          float_a[i] *= (-1);
        }
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting negative float array"
                    " in ascending order", name_size);
      cmp = float_cmp_ascending;
    break;
    case float_test_4:

    /*
     * Test for sorting negative float array in descending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        float_a[i] = ((float)rand() / (float)(RAND_MAX/rand()));
        if(float_a[i] > 0) {
        
          float_a[i] *= (-1);
        }
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting negative float array"
                    " in descending order", name_size);
      cmp = float_cmp_descending;
    break;
    case float_test_5:

    /*
     * Test for sorting float array in ascending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        float_a[i] = ((float)rand() / (float)(RAND_MAX/rand()));
        if(((i % 2) == 0) && (float_a[i] > 0)) {
        
          float_a[i] *= (-1);
        } else if(((i % 2) == 1) && (float_a[i] < 0)){
        
          float_a[i] *= (-1);
        }
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting float array"
                    " in ascending order", name_size);
      cmp = float_cmp_ascending;
    break;
    case float_test_6:

    /*
     * Test for sorting float array in descending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        float_a[i] = ((float)rand() / (float)(RAND_MAX/rand()));
        if(((i % 2) == 0) && (float_a[i] > 0)) {
        
          float_a[i] *= (-1);
        } else if(((i % 2) == 1) && (float_a[i] < 0)){
        
          float_a[i] *= (-1);
        }
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting float array"
                    " in descending order", name_size);
      cmp = float_cmp_descending;
    break;
    case float_test_7:

    /*
     * Test for sorting float array of size 1 in descending order
     */
      float_a = malloc(ARR_SIZE_1 * sizeof(float));
      if(!float_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_1; i++) {
      
        float_a[i] = ((float)rand() / (float)(RAND_MAX/rand()));
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting float array of"
                    " size 1 in descending order", name_size);
      cmp = float_cmp_descending;
    break;
    case float_test_8:

    /*
     * Test for sorting float array of size 2 in descending order
     */
      float_a = malloc(ARR_SIZE_2 * sizeof(float));
      if(!float_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_2; i++) {
      
        float_a[i] = ((float)rand() / (float)(RAND_MAX/rand()));
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting float array of size"
                    " 2 in descending order", name_size);
      cmp = float_cmp_descending;
    break;
    case float_test_9:

    /*
     * Test for sorting float array with all element equal in ascending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {
      
        printf("Malloc Failure\n");
        return;
      }

      for(i = 0; i < ARR_SIZE_10; i++) {
      
        float_a[i] = 23.97;
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting float array with all "
                    "equal in ascending order", name_size);
      cmp = float_cmp_ascending;
    break;

    /*
     * Character test cases
     */
    case char_test_1:

    break;
    case char_test_2:

    break;
    case char_test_3:

    break;
    case char_test_4:

    break;
    case char_test_5:

    break;
    case char_test_6:

    break;
    case char_test_7:

    break;
    case char_test_8:

    break;
    case char_test_9:

    break;
    case char_test_10:

    break;
    case char_test_11:

    break;

    /*
     * Points test cases
     */
    case point_t_test_1:

    break;
    case point_t_test_2:

    break;
    case point_t_test_3:

    break;
    case point_t_test_4:

    break;
    case point_t_test_5:

    break;
    case point_t_test_6:

    break;
    case point_t_test_7:

    break;
    case point_t_test_8:

    break;

    /*
     * General test cases
     */
    case test_1:

    break;
    case test_2:

    break;
    case test_3:

    break;
    case test_4:

    break;
    case test_5:

    break;
    case test_6:

    break;
    case test_7:

    break;
    case test_8:

    break;
  }
}

void
test_cases ()
{

  void *arr;
  size_t arr_size = 0;
  size_t elem_size = 0;
  char *name = NULL;
  uint8_t name_size = 0;
  cmp_e (* cmp) (const void *, const void *);
  test_cases_e case_no = 0;
  sort_type_e type = 0;
  bool is_sorted = false;

  srand(time(0));

  name_size = NAME_SIZE;
  name = malloc(name_size * sizeof(char));

  for(case_no = 9; case_no < NUM_CASES; case_no++) {
  
    for(type = MSORT; type <= QSORT; type++) {
      
      generate_input(&arr, &arr_size, &elem_size, name, name_size, cmp, case_no);

      sort(arr, arr_size, elem_size, cmp, type);

      is_sorted = is_array_sorted(arr, arr_size, elem_size, cmp);

      if(is_sorted) {
      
        printf("%s: %s -> %s\n", sort_type2str(type), name, "SUCCESS");
      } else {
      
        printf("%s: %s -> %s\n", sort_type2str(type), name, "FAILURE");
      }

      if(arr) {
      
        free(arr);
      }
    }
  }

  return;
}

int
main ()
{

  test_cases();

  return 0;
}