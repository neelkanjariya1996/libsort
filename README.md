# libsort

Generic Library which provides merge sort and heap sort implementation. The library provides following two APIs:

1. void msort (void *arr, size_t arr_size,size_t elem_size, int (*cmp)(const void *, const void *)):
The msort() function sorts an array using merge sort algorithm with arr_size elements of size elem_size. The arr argument point to the start of the array. The contents of the array are sorted in ascending order according to a comparison function ponted to by cmp, which is called with two arguments that point to the objects being compared. The comparison function must return SORT_LT, SORT_EQ, or SORT_GT if the first argument is conidered to be respectively less than, equal to, or greater than the second. If two members compare as equal, their order in the sorted array is undefined.

2. void hsort (void *arr, size_t arr_size, size_t elem_size, cmp_e (*cmp)(const void *, const void *)):
The hsort() function sorts an array using heap sort algorithm with arr_size elements of size elem_size. The arr argument point to the start of the array. The contents of the array are sorted in ascending order according to a comparison function ponted to by cmp, which is called with two arguments that point to the objects being compared. The comparison function must return SORT_LT, SORT_EQ, or SORT_GT if the first argument is conidered to be respectively less than, equal to, or greater than the second. If two members compare as equal, their order in the sorted array is undefined.

The example usage of these API's is given in the test directory. The test directory also includes a generic unit-test framework used for testing the sorting library. 
I have compared the performance of merge sort and heap sort algorithms implemented in this library with the standard implementation of quick sort. 

Instruction for compilation: 
1. make clean
        cleans all the generated object and binary files
2. make
        Generates the shared object for the sorting library(libsort.so)
        It also compiles the driver code written in the test directory (run test)
3. ./run_test
        Execute this command to run all the test cases
