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
 * Test for 1KB of integer array
 */
void
test3 ()
{

  int arr[(_1KB / sizeof(int))];
  size_t size = 0;
  size_t i = 0;
  
  for(i = 0; i < (_1KB / sizeof(int)); i++) {
  
    arr[i] = (rand() % INT_MAX);
  }

  size = sizeof(arr) / sizeof(int);
  printf("Test for 1KB of integer array: \n");
  printf("Original array: ");
  print_int_array(arr, size);

  merge_sort(arr, size, sizeof(int), int_cmp_ascending);

  printf("Sorted   array: ");
  print_int_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for 1KB of float array
 */
void
test4 ()
{

  float arr[(_1KB / sizeof(float))];
  size_t size = 0;
  size_t i = 0;
  
  for(i = 0; i < (_1KB / sizeof(float)); i++) {
  
    arr[i] = (rand() % LONG_MAX);
  }

  size = sizeof(arr) / sizeof(float);
  printf("Test for 1KB of float array: \n");
  printf("Original array: ");
  print_float_array(arr, size);

  merge_sort(arr, size, sizeof(float), float_cmp_ascending);

  printf("Sorted   array: ");
  print_float_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for 1MB of integer array
 */
void
test5 ()
{

  int arr[(_1MB / sizeof(int))];
  size_t size = 0;
  size_t i = 0;
  
  for(i = 0; i < (_1MB / sizeof(int)); i++) {
  
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
test6 ()
{

  float arr[(_1MB / sizeof(float))];
  size_t size = 0;
  size_t i = 0;
  
  for(i = 0; i < (_1MB / sizeof(float)); i++) {
  
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

/*
 * Test for 128MB of integer array
 */
void
test7 ()
{

  int *arr;
  size_t size = 0;
  size_t i = 0;
 
  size = _128MB / sizeof(int);

  arr = malloc(size * sizeof(int));
  
  for(i = 0; i < size; i++) {
  
    arr[i] = (rand() % INT_MAX);
  }

  printf("Test for 128MB of integer array: \n");
  printf("Original array: ");
  print_int_array(arr, size);

  merge_sort(arr, size, sizeof(int), int_cmp_ascending);

  printf("Sorted   array: ");
  print_int_array(arr, size);
  printf("\n");

  return;
}

/*
 * Test for 128MB of float array
 */
void
test8 ()
{

  float *arr;
  size_t size = 0;
  size_t i = 0;

  size = _128MB / sizeof(float);

  printf("size: %ld\n", size);
  arr = malloc(size * sizeof(float));

  for(i = 0; i < size; i++) {
  
    arr[i] = (rand() % LONG_MAX);
  }

  printf("Test for 128MB of float array: \n");
  printf("Original array: ");
  //print_float_array(arr, size);

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
  //test5();
  //test6();
  //test7();
  //test8();

  return 0;
}
