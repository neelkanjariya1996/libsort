/*
 * File name: test_private.h
 * Author: Neel Kanjaria
 * Description: Unit test framework for testing various sorting algorithms
 * To add a new test case, follow these steps.
 * 1. Add an enum in enum test_case_e
 * 2. Increment the number of cases i.e NUM_CASES macro in test_private.h
 * 3. Generate the input test case by modifying the generate_input function
 */

#include "test_private.h"

/*
 * Function to sort the array based on the specified type
 */
void
sort (void *arr, size_t arr_size, size_t elem_size,
      compare_fn cmp,
      sort_type_e type)
{
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
                 compare_fn cmp)
{
  size_t i = 0;
  cmp_e ret;

  for(i = 1; i < arr_size; i++) {

    ret = cmp(ARR_LOC(arr, (i - 1), elem_size), ARR_LOC(arr, i, elem_size));
    if(ret == SORT_GT) {
      return (false);
    }
  }

  return (true);
}

/*
 * This function generates the input needed for individual test cases
 */
bool
generate_input (void **arr, size_t *arr_size,
                size_t *elem_size, char *name, uint8_t name_size,
                compare_fn *cmp,
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
    case INT_TEST_1:

      /*
       * Test for sorting positive integer array in asceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {

        printf("INT_TEST_1: Malloc Failure\n");
        return (false);
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
      *cmp = int_cmp_ascending;
      break;
    case INT_TEST_2:

      /*
       * Test for sorting positive integer array in desceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {

        printf("INT_TEST_2: Malloc Failure\n");
        return (false);
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
      *cmp = int_cmp_descending;
      break;
    case INT_TEST_3:

      /*
       * Test for sorting negative integer array in asceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {

        printf("INT_TEST_3: Malloc Failure\n");
        return (false);
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
      *cmp = int_cmp_ascending;
      break;
    case INT_TEST_4:

      /*
       * Test for sorting negative integer array in desceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {

        printf("INT_TEST_4: Malloc Failure\n");
        return (false);
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
      *cmp = int_cmp_descending;
      break;
    case INT_TEST_5:

      /*
       * Test for sorting integer array in asceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {

        printf("INT_TEST_5: Malloc Failure\n");
        return (false);
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
      *cmp = int_cmp_ascending;
      break;
    case INT_TEST_6:

      /*
       * Test for sorting integer array in desceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {

        printf("INT_TEST_6: Malloc Failure\n");
        return (false);
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
      *cmp = int_cmp_descending;
      break;
    case INT_TEST_7:

      /*
       * Test for sorting integer array of size 1 in asceding order
       */
      int_a = malloc(ARR_SIZE_1 * sizeof(int));
      if(!int_a) {

        printf("INT_TEST_7: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_1; i++) {

        int_a[i] = (rand() % INT_MAX);
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting integer array "
              " of size 1 in ascending order", name_size);
      *cmp = int_cmp_ascending;
      break;
    case INT_TEST_8:

      /*
       * Test for sorting integer array of size 2 in asceding order
       */
      int_a = malloc(ARR_SIZE_2 * sizeof(int));
      if(!int_a) {

        printf("INT_TEST_8: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_2; i++) {

        int_a[i] = (rand() % INT_MAX);
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting integer array "
              " of size 2 in ascending order", name_size);
      *cmp = int_cmp_ascending;
      break;
    case INT_TEST_9:

      /*
       * Test for sorting integer array with all elements
       * equal in asceding order
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {

        printf("INT_TEST_9: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        int_a[i] = -1;
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for sorting integer array with all"
              " elements equal in ascending order", name_size);
      *cmp = int_cmp_ascending;
      break;

    /*
     * Float test cases
     */
    case FLOAT_TEST_1:

    /*
     * Test for sorting positive float array in ascending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {

        printf("FLOAT_TEST_1: Malloc Failure\n");
        return (false);
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
      *cmp = float_cmp_ascending;
      break;
    case FLOAT_TEST_2:

    /*
     * Test for sorting positive float array in descending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {

        printf("FLOAT_TEST_2: Malloc Failure\n");
        return (false);
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
      *cmp = float_cmp_descending;
      break;
    case FLOAT_TEST_3:

    /*
     * Test for sorting negative float array in ascending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {

        printf("FLOAT_TEST_3: Malloc Failure\n");
        return (false);
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
      *cmp = float_cmp_ascending;
      break;
    case FLOAT_TEST_4:

    /*
     * Test for sorting negative float array in descending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {

        printf("FLOAT_TEST_4: Malloc Failure\n");
        return (false);
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
      *cmp = float_cmp_descending;
      break;
    case FLOAT_TEST_5:

    /*
     * Test for sorting float array in ascending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {

        printf("FLOAT_TEST_5: Malloc Failure\n");
        return (false);
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
      *cmp = float_cmp_ascending;
      break;
    case FLOAT_TEST_6:

    /*
     * Test for sorting float array in descending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {

        printf("FLOAT_TEST_6: Malloc Failure\n");
        return (false);
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
      *cmp = float_cmp_descending;
      break;
    case FLOAT_TEST_7:

    /*
     * Test for sorting float array of size 1 in descending order
     */
      float_a = malloc(ARR_SIZE_1 * sizeof(float));
      if(!float_a) {

        printf("FLOAT_TEST_7: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_1; i++) {

        float_a[i] = ((float)rand() / (float)(RAND_MAX/rand()));
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting float array of"
                    " size 1 in descending order", name_size);
      *cmp = float_cmp_descending;
      break;
    case FLOAT_TEST_8:

    /*
     * Test for sorting float array of size 2 in descending order
     */
      float_a = malloc(ARR_SIZE_2 * sizeof(float));
      if(!float_a) {

        printf("FLOAT_TEST_8: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_2; i++) {

        float_a[i] = ((float)rand() / (float)(RAND_MAX/rand()));
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting float array of size"
                    " 2 in descending order", name_size);
      *cmp = float_cmp_descending;
      break;
    case FLOAT_TEST_9:

    /*
     * Test for sorting float array with all element equal in ascending order
     */
      float_a = malloc(ARR_SIZE_10 * sizeof(float));
      if(!float_a) {

        printf("FLOAT_TEST_9: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        float_a[i] = 23.97;
      }

      *arr = float_a;
      *arr_size = sizeof(float_a) / sizeof(float);
      *elem_size = sizeof(float);
      strncpy(name, "Test for sorting float array with all "
                    "equal in ascending order", name_size);
      *cmp = float_cmp_ascending;
      break;

    /*
     * Character test cases
     */
    case CHAR_TEST_1:

      /*
       * Test for sorting capital letters in ascending order
      */
      char_a = malloc(ARR_SIZE_10 * sizeof(char));
      if(!char_a) {

        printf("CHAR_TEST_1: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        char_a[i] = (rand() % ALPHABETS) + 'A';
      }

      *arr = char_a;
      *arr_size = sizeof(char_a) / sizeof(char);
      *elem_size = sizeof(char);
      strncpy(name, "Test for sorting capital leters"
                    " in ascending order", name_size);
      *cmp = char_cmp_ascending;
      break;
    case CHAR_TEST_2:

      /*
       * Test for sorting capital letters in descending order
      */
      char_a = malloc(ARR_SIZE_10 * sizeof(char));
      if(!char_a) {

        printf("CHAR_TEST_2: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        char_a[i] = (rand() % ALPHABETS) + 'A';
      }

      *arr = char_a;
      *arr_size = sizeof(char_a) / sizeof(char);
      *elem_size = sizeof(char);
      strncpy(name, "Test for sorting capital leters"
                    " in descending order", name_size);
      *cmp = char_cmp_descending;
      break;
    case CHAR_TEST_3:

      /*
       * Test for sorting small letters in ascending order
      */
      char_a = malloc(ARR_SIZE_10 * sizeof(char));
      if(!char_a) {

        printf("CHAR_TEST_3: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        char_a[i] = (rand() % ALPHABETS) + 'a';
      }

      *arr = char_a;
      *arr_size = sizeof(char_a) / sizeof(char);
      *elem_size = sizeof(char);
      strncpy(name, "Test for sorting small leters"
                    " in ascending order", name_size);
      *cmp = char_cmp_ascending;
      break;
    case CHAR_TEST_4:

      /*
       * Test for sorting small letters in descending order
      */
      char_a = malloc(ARR_SIZE_10 * sizeof(char));
      if(!char_a) {

        printf("CHAR_TEST_4: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        char_a[i] = (rand() % ALPHABETS) + 'a';
      }

      *arr = char_a;
      *arr_size = sizeof(char_a) / sizeof(char);
      *elem_size = sizeof(char);
      strncpy(name, "Test for sorting small leters"
                    " in descending order", name_size);
      *cmp = char_cmp_descending;
      break;
    case CHAR_TEST_5:

      /*
       * Test for sorting characters in ascending order
      */
      char_a = malloc(ARR_SIZE_10 * sizeof(char));
      if(!char_a) {

        printf("CHAR_TEST_5: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        char_a[i] = (rand() % CHAR_MAX);
      }

      *arr = char_a;
      *arr_size = sizeof(char_a) / sizeof(char);
      *elem_size = sizeof(char);
      strncpy(name, "Test for sorting characters"
                    " in ascending order", name_size);
      *cmp = char_cmp_ascending;
      break;
    case CHAR_TEST_6:

      /*
       * Test for sorting characters in descending order
      */
      char_a = malloc(ARR_SIZE_10 * sizeof(char));
      if(!char_a) {

        printf("CHAR_TEST_6: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        char_a[i] = (rand() % CHAR_MAX);
      }

      *arr = char_a;
      *arr_size = sizeof(char_a) / sizeof(char);
      *elem_size = sizeof(char);
      strncpy(name, "Test for sorting characters"
                    " in descending order", name_size);
      *cmp = char_cmp_descending;
      break;
    case CHAR_TEST_7:

      /*
       * Test for sorting special characters in ascending order
      */
      char_a = malloc(ARR_SIZE_10 * sizeof(char));
      if(!char_a) {

        printf("CHAR_TEST_7: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        char_a[i] = (rand() % SPECIAL_CHARACTERS) + ' ';
      }

      *arr = char_a;
      *arr_size = sizeof(char_a) / sizeof(char);
      *elem_size = sizeof(char);
      strncpy(name, "Test for sorting special characters"
                    " in ascending order", name_size);
      *cmp = char_cmp_ascending;
      break;
    case CHAR_TEST_8:

      /*
       * Test for sorting special characters in descending order
      */
      char_a = malloc(ARR_SIZE_10 * sizeof(char));
      if(!char_a) {

        printf("CHAR_TEST_8: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        char_a[i] = (rand() % SPECIAL_CHARACTERS) + ' ';
      }

      *arr = char_a;
      *arr_size = sizeof(char_a) / sizeof(char);
      *elem_size = sizeof(char);
      strncpy(name, "Test for sorting special characters"
                    " in descending order", name_size);
      *cmp = char_cmp_descending;
      break;
    case CHAR_TEST_9:

      /*
       * Test for sorting char array of size 1 in descending order
      */
      char_a = malloc(ARR_SIZE_1 * sizeof(char));
      if(!char_a) {

        printf("CHAR_TEST_9: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_1; i++) {

        char_a[i] = (rand() % SPECIAL_CHARACTERS) + ' ';
      }

      *arr = char_a;
      *arr_size = sizeof(char_a) / sizeof(char);
      *elem_size = sizeof(char);
      strncpy(name, "Test for sorting char array of size"
                    " 1 in descending order", name_size);
      *cmp = char_cmp_descending;
      break;
    case CHAR_TEST_10:

      /*
       * Test for sorting char array of size 2 in ascending order
      */
      char_a = malloc(ARR_SIZE_2 * sizeof(char));
      if(!char_a) {

        printf("CHAR_TEST_10: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_2; i++) {

        char_a[i] = (rand() % SPECIAL_CHARACTERS) + ' ';
      }

      *arr = char_a;
      *arr_size = sizeof(char_a) / sizeof(char);
      *elem_size = sizeof(char);
      strncpy(name, "Test for sorting char array of size"
                    " 2 in ascending order", name_size);
      *cmp = char_cmp_ascending;
      break;
    case CHAR_TEST_11:

      /*
       * Test for sorting char array with all characters
       * same in descending order
      */
      char_a = malloc(ARR_SIZE_10 * sizeof(char));
      if(!char_a) {

        printf("CHAR_TEST_11: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        char_a[i] = 'a';
      }

      *arr = char_a;
      *arr_size = sizeof(char_a) / sizeof(char);
      *elem_size = sizeof(char);
      strncpy(name, "Test for sorting char array with all characters"
                    " same in descending order", name_size);
      *cmp = char_cmp_descending;
      break;

    /*
     * Points test cases
     */
    case POINT_T_TEST_1:

      /*
       * Test for sorting points array in
       * ascending order based on x coordinate
      */
      point_t_a = malloc(ARR_SIZE_10 * sizeof(point_t));
      if(!point_t_a) {

        printf("POINT_T_TEST_1: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        point_t_a[i].x = rand() % INT_MAX;
        if(point_t_a[i].x < 0) {

          point_t_a[i].x *= (-1);
        }
        point_t_a[i].y = rand() % INT_MAX;
        if(point_t_a[i].y < 0) {

          point_t_a[i].y *= (-1);
        }
      }

      *arr = point_t_a;
      *arr_size = sizeof(point_t_a) / sizeof(point_t);
      *elem_size = sizeof(point_t);
      strncpy(name, "Test for sorting points array in ascending"
                    " order based on x coordinate", name_size);
      *cmp = point_x_cmp_ascending;
      break;
    case POINT_T_TEST_2:

      /*
       * Test for sorting points array in
       * ascending order based on y coordinate
      */
      point_t_a = malloc(ARR_SIZE_10 * sizeof(point_t));
      if(!point_t_a) {

        printf("POINT_T_TEST_2: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        point_t_a[i].x = rand() % INT_MAX;
        if(point_t_a[i].x < 0) {

          point_t_a[i].x *= (-1);
        }
        point_t_a[i].y = rand() % INT_MAX;
        if(point_t_a[i].y < 0) {

          point_t_a[i].y *= (-1);
        }
      }

      *arr = point_t_a;
      *arr_size = sizeof(point_t_a) / sizeof(point_t);
      *elem_size = sizeof(point_t);
      strncpy(name, "Test for sorting points array in ascending"
                    " order based on y coordinate", name_size);
      *cmp = point_y_cmp_ascending;
      break;
    case POINT_T_TEST_3:

      /*
       * Test for sorting points array in
       * descending order based on x coordinate
      */
      point_t_a = malloc(ARR_SIZE_10 * sizeof(point_t));
      if(!point_t_a) {

        printf("POINT_T_TEST_3: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        point_t_a[i].x = rand() % INT_MAX;
        if(point_t_a[i].x < 0) {

          point_t_a[i].x *= (-1);
        }
        point_t_a[i].y = rand() % INT_MAX;
        if(point_t_a[i].y < 0) {

          point_t_a[i].y *= (-1);
        }
      }

      *arr = point_t_a;
      *arr_size = sizeof(point_t_a) / sizeof(point_t);
      *elem_size = sizeof(point_t);
      strncpy(name, "Test for sorting points array in descending"
                    " order based on x coordinate", name_size);
      *cmp = point_x_cmp_descending;
      break;
    case POINT_T_TEST_4:

      /*
       * Test for sorting points array in
       * descending order based on y coordinate
      */
      point_t_a = malloc(ARR_SIZE_10 * sizeof(point_t));
      if(!point_t_a) {

        printf("POINT_T_TEST_4: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        point_t_a[i].x = rand() % INT_MAX;
        if(point_t_a[i].x < 0) {

          point_t_a[i].x *= (-1);
        }
        point_t_a[i].y = rand() % INT_MAX;
        if(point_t_a[i].y < 0) {

          point_t_a[i].y *= (-1);
        }
      }

      *arr = point_t_a;
      *arr_size = sizeof(point_t_a) / sizeof(point_t);
      *elem_size = sizeof(point_t);
      strncpy(name, "Test for sorting points array in descending"
                    " order based on y coordinate", name_size);
      *cmp = point_y_cmp_descending;
      break;
    case POINT_T_TEST_5:

      /*
       * Test for sorting points array in
       * ascending order based on x coordinate
      */
      point_t_a = malloc(ARR_SIZE_10 * sizeof(point_t));
      if(!point_t_a) {

        printf("POINT_T_TEST_5: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        point_t_a[i].x = rand() % INT_MAX;
        if(((i % 2) == 0) && (point_t_a[i].x < 0)) {

          point_t_a[i].x *= (-1);
        } else if(((i % 2) == 1) && (point_t_a[i].x > 0)){

          point_t_a[i].x *= (-1);
        }
        point_t_a[i].y = rand() % INT_MAX;
        if(((i % 2) == 0) && (point_t_a[i].y < 0)) {

          point_t_a[i].y *= (-1);
        } else if(((i % 2) == 1) && (point_t_a[i].y > 0)){

          point_t_a[i].y *= (-1);
        }
      }

      *arr = point_t_a;
      *arr_size = sizeof(point_t_a) / sizeof(point_t);
      *elem_size = sizeof(point_t);
      strncpy(name, "Test for sorting points array in ascending"
                    " order based on x coordinate", name_size);
      *cmp = point_x_cmp_ascending;
      break;
    case POINT_T_TEST_6:

      /*
       * Test for sorting points array in
       * ascending order based on y coordinate
      */
      point_t_a = malloc(ARR_SIZE_10 * sizeof(point_t));
      if(!point_t_a) {

        printf("POINT_T_TEST_6: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        point_t_a[i].x = rand() % INT_MAX;
        if(((i % 2) == 0) && (point_t_a[i].x < 0)) {

          point_t_a[i].x *= (-1);
        } else if(((i % 2) == 1) && (point_t_a[i].x > 0)){

          point_t_a[i].x *= (-1);
        }
        point_t_a[i].y = rand() % INT_MAX;
        if(((i % 2) == 0) && (point_t_a[i].y < 0)) {

          point_t_a[i].y *= (-1);
        } else if(((i % 2) == 1) && (point_t_a[i].y > 0)){

          point_t_a[i].y *= (-1);
        }
      }

      *arr = point_t_a;
      *arr_size = sizeof(point_t_a) / sizeof(point_t);
      *elem_size = sizeof(point_t);
      strncpy(name, "Test for sorting points array in ascending"
                    " order based on y coordinate", name_size);
      *cmp = point_y_cmp_ascending;
      break;
    case POINT_T_TEST_7:

      /*
       * Test for sorting points array in
       * descending order based on x coordinate
      */
      point_t_a = malloc(ARR_SIZE_10 * sizeof(point_t));
      if(!point_t_a) {

        printf("POINT_T_TEST_7: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        point_t_a[i].x = rand() % INT_MAX;
        if(((i % 2) == 0) && (point_t_a[i].x < 0)) {

          point_t_a[i].x *= (-1);
        } else if(((i % 2) == 1) && (point_t_a[i].x > 0)){

          point_t_a[i].x *= (-1);
        }
        point_t_a[i].y = rand() % INT_MAX;
        if(((i % 2) == 0) && (point_t_a[i].y < 0)) {

          point_t_a[i].y *= (-1);
        } else if(((i % 2) == 1) && (point_t_a[i].y > 0)){

          point_t_a[i].y *= (-1);
        }
      }

      *arr = point_t_a;
      *arr_size = sizeof(point_t_a) / sizeof(point_t);
      *elem_size = sizeof(point_t);
      strncpy(name, "Test for sorting points array in descending"
                    " order based on x coordinate", name_size);
      *cmp = point_x_cmp_descending;
      break;
    case POINT_T_TEST_8:

      /*
       * Test for sorting points array in
       * descending order based on y coordinate
      */
      point_t_a = malloc(ARR_SIZE_10 * sizeof(point_t));
      if(!point_t_a) {

        printf("POINT_T_TEST_8: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        point_t_a[i].x = rand() % INT_MAX;
        if(((i % 2) == 0) && (point_t_a[i].x < 0)) {

          point_t_a[i].x *= (-1);
        } else if(((i % 2) == 1) && (point_t_a[i].x > 0)){

          point_t_a[i].x *= (-1);
        }
        point_t_a[i].y = rand() % INT_MAX;
        if(((i % 2) == 0) && (point_t_a[i].y < 0)) {

          point_t_a[i].y *= (-1);
        } else if(((i % 2) == 1) && (point_t_a[i].y > 0)){

          point_t_a[i].y *= (-1);
        }
      }

      *arr = point_t_a;
      *arr_size = sizeof(point_t_a) / sizeof(point_t);
      *elem_size = sizeof(point_t);
      strncpy(name, "Test for sorting points array in descending"
                    " order based on y coordinate", name_size);
      *cmp = point_y_cmp_descending;
      break;

    /*
     * General test cases
     */
    case TEST_1:

      /*
       * Array passed as NULL
       */
      *arr = NULL;
      *arr_size = 0;
      *elem_size = 0;
      strncpy(name, "Test for empty array", name_size);
      *cmp = int_cmp_ascending;
      break;
    case TEST_2:

      /*
       * Compare function passed as NULL
       */
      int_a = malloc(ARR_SIZE_10 * sizeof(int));
      if(!int_a) {

        printf("TEST_2: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < ARR_SIZE_10; i++) {

        int_a[i] = (rand() % INT_MAX);
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for compare function passed as NULL", name_size);
      break;
    case TEST_3:

      /*
       * Test for 1KB of integer array
       */
      int_a = malloc((_1KB / sizeof(int)) * sizeof(int));
      if(!int_a) {

        printf("TEST_3: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < (_1KB / sizeof(int)); i++) {

        int_a[i] = (rand() % INT_MAX);
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for 1KB of integer array", name_size);
      *cmp = int_cmp_ascending;
      break;
    case TEST_4:

      /*
       * Test for 1MB of integer array
       */
      int_a = malloc((_1MB / sizeof(int)) * sizeof(int));
      if(!int_a) {

        printf("TEST_4: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < (_1MB / sizeof(int)); i++) {

        int_a[i] = (rand() % INT_MAX);
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for 1MB of integer array", name_size);
      *cmp = int_cmp_ascending;
      break;
    case TEST_5:

      /*
       * Test for 128MB of integer array
       */
      int_a = malloc((_128MB / sizeof(int)) * sizeof(int));
      if(!int_a) {

        printf("TEST_5: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < (_128MB / sizeof(int)); i++) {

        int_a[i] = (rand() % INT_MAX);
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for 128MB of integer array", name_size);
      *cmp = int_cmp_ascending;
      break;
    case TEST_6:

      /*
       * Test for 256MB of integer array
       */
      int_a = malloc((_256MB / sizeof(int)) * sizeof(int));
      if(!int_a) {

        printf("TEST_6: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < (_256MB / sizeof(int)); i++) {

        int_a[i] = (rand() % INT_MAX);
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for 256MB of integer array", name_size);
      *cmp = int_cmp_ascending;
      break;
    case TEST_7:

      /*
       * Test for 512MB of integer array
       */
      int_a = malloc((_512MB / sizeof(int)) * sizeof(int));
      if(!int_a) {

        printf("TEST_7: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < (_512MB / sizeof(int)); i++) {

        int_a[i] = (rand() % INT_MAX);
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for 512MB of integer array", name_size);
      *cmp = int_cmp_ascending;
      break;
    case TEST_8:

      /*
       * Test for 1GB of integer array
       */
      int_a = malloc((_1GB / sizeof(int)) * sizeof(int));
      if(!int_a) {

        printf("TEST_8: Malloc Failure\n");
        return (false);
      }

      for(i = 0; i < (_1GB / sizeof(int)); i++) {

        int_a[i] = (rand() % INT_MAX);
      }

      *arr = int_a;
      *arr_size = sizeof(int_a) / sizeof(int);
      *elem_size = sizeof(int);
      strncpy(name, "Test for 1GB of integer array", name_size);
      *cmp = int_cmp_ascending;
      break;
    default:
    break;
  }

  return (true);
}

void
test_cases ()
{
  void *arr;
  size_t arr_size = 0;
  size_t elem_size = 0;
  char *name = NULL;
  uint8_t name_size = 0;
  compare_fn cmp = NULL;
  test_cases_e case_no = 0;
  sort_type_e type = 0;
  bool is_sorted = false;
  clock_t begin = 0;
  clock_t end = 0;
  double time_spent = 0;

  srand(time(0));

  name_size = NAME_SIZE;
  name = malloc(name_size * sizeof(char));

  for(case_no = 0; case_no < NUM_CASES; case_no++) {

    for(type = MSORT; type <= QSORT; type++) {
      if(!(generate_input(&arr, &arr_size, &elem_size,
                     name, name_size, &cmp, case_no))) {

        printf("%s %-75s %-10s %-8s\n",
              sort_type2str(type), name, "FAILURE", "Invalid Input");
        continue;
      }

      /*
       * Quick sort doesn't take NULL as parameters
       */
      if(type == QSORT && (!arr || !cmp)) {
        continue;
      }

      begin = clock();
      sort(arr, arr_size, elem_size, cmp, type);
      end = clock();
      time_spent = (double)(end - begin)/CLOCKS_PER_SEC;

      is_sorted = is_array_sorted(arr, arr_size, elem_size, cmp);
      if(is_sorted) {

        printf("%-12s %-75s %-10s execution time: %lf\n",
              sort_type2str(type), name, "SUCCESS", time_spent);
      } else {

        printf("%s %-75s %-10s execution time: %lf\n",
              sort_type2str(type), name, "FAILURE", time_spent);
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
