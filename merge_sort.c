#include "merge_sort.h"

/*
 * This macro is used to do pointer arithmetic 
 * to get the array location based on index and 
 * each array element size
 *
 * @input1 arr the pointer to the array
 * @input2 ind the index you want to change/use
 * @input3 elem_size size of each individual 
 *                   array element
 *
 * @return returns the array location of the index
 */
#define ARR_LOC(arr, ind, elem_size) (arr + (ind * elem_size))

/*
 * This function uses memcmp to compare two
 * array elements if NULL is passed to the 
 * compare function, else uses the compare 
 * function passed by user.
 *
 * @input1 p1 pointer to element_1
 * @input2 p2 pointer to element_2
 * @input3 elem_size size of each individual 
 *                   array element
 * @input4 cmp compare function to be 
 *             used if passed from user
 *
 * @return cmp_e MERGESORT_LT -> element_1 is less than element_2
 *               MERGESORT_EQ -> element_1 is equal to element_2
 *               MERGESORT_GT-> element_1 is greater than element_2
 */
static cmp_e
merge_cmp (const void *p1, const void *p2, 
           size_t elem_size,
           cmp_e (*cmp)(const void *, const void *))
{

  int ret = 0;

  if(!cmp) {
 
    ret =  memcmp(p1, p2, elem_size);
    if(ret < 0) {
    
      ret =  MERGESORT_LT;
    } else if (ret > 0) {
    
      ret = MERGESORT_GT;
    } else {
    
      ret = MERGESORT_EQ;
    }
  } else {
    
    ret = (cmp(p1, p2));
  }

  return ret;
}

/*
 * This function merges two subarrays of arr[low...high]
 * and after merging, the array is sorted based on the 
 * compare function.
 * The first subarray is arr[low...mid]
 * The second subarray is arr[mid + 1...high]
 * 
 * @input1 arr the array to be sorted
 * @input2 elem_size size of each individual 
 *                   array element
 * @input3 low low index of the array
 * @input4 mid middle index of the array
 * @input5 high high index of the array
 * @input6 cmp compare function used to compare two 
 *             array elements
 */
void
merge (void *arr, size_t elem_size, size_t low, 
       size_t mid, size_t high, 
       cmp_e (*cmp)(const void *, const void *))
{

  size_t n1 = 0;    //size of first subarray
  size_t n2 = 0;    //size of second subarray
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;
  void *L;          //temporary array for first subarray
  void *R;          //temporary array for second subarray

  if(!arr) {

    return;
  }

  n1 = mid - low + 1;
  n2 = high - mid;

  /*
   * Temporary array of size n1
   */
  L = malloc(n1 * elem_size);
  if(!L) {
    
    return;
  }

  /*
   * Temporay array of size n2
   */
  R = malloc(n2 * elem_size);
  if(!R) {
  
    free(L);
    return;
  }

  /* copy first half(low...mid) of array to L
   * and second half(mid + 1...high) to R
   */
  memcpy(L, ARR_LOC(arr, low, elem_size), 
        (n1 * elem_size));
  memcpy(R, ARR_LOC(arr, (mid + 1),
         elem_size), (n2 * elem_size));

  /*
   * Merge the two temporary subarrays L and R 
   * back to arr[low...high]
   */
  i = 0;            //initial index of first subarray
  j = 0;            //initial index of second subarray
  k = low;          //initial index of merged subarray
  while((i < n1) && (j < n2)) {
  
    /* Compare two elements and place them in the 
     * merged array based on compare function to be
     * used.
     */
    if( merge_cmp((void *)ARR_LOC(L, i, elem_size), 
                  (void *)ARR_LOC(R, j, elem_size), 
                  elem_size, cmp) == MERGESORT_LT) {
    
      memcpy(ARR_LOC(arr, k, elem_size),
             ARR_LOC(L, i, elem_size), elem_size);
      i++;
    } else {
    
      memcpy(ARR_LOC(arr, k, elem_size), 
             ARR_LOC(R, j, elem_size), elem_size);
      j++;
    }
    k++;
  }

  /*
   * Copy the remaining elements of first subarray,
   * if there are any
   */
  while(i < n1) {
  
    memcpy(ARR_LOC(arr, k, elem_size), 
           ARR_LOC(L, i, elem_size), elem_size);
    i++;
    k++;
  }

  /*
   * Copy the remaining elements of second subarray,
   * if there are any
   */
  while(j < n2) {
  
    memcpy(ARR_LOC(arr, k, elem_size), 
           ARR_LOC(R, j, elem_size), elem_size);
    j++;
    k++;
  }

  /*
   * Free the temporarily allocated subarrays
   */
  if(L) {

    free(L);
  }
  if(R) {

    free(R);
  }

  return;
}

/*
 * This is a recursive function that divides the 
 * array into smaller subarrays and then merges them
 * to form the sorted array.
 * 
 * @input1 arr the array to be sorted
 * @input2 elem_size size of each individual 
 *                   array element
 * @input3 low low index of the subarray
 * @input4 high high index of the subarray
 * @input5 cmp compare function used to compare two 
 *             array elements
 */
void
merge_sort_recur (void *arr, size_t elem_size, 
                  size_t low, size_t high,
                  cmp_e (*cmp)(const void *, const void *))
{
  
  size_t mid = 0;

  if(!arr) {

    return;
  }

  if(low >= high) {

    return;
  }

  mid = low + ((high - low) / 2);

  /*
   * sort the first and second halves
   */
  merge_sort_recur(arr, elem_size, low, mid, cmp);
  merge_sort_recur(arr, elem_size, (mid + 1), high, cmp);

  merge (arr, elem_size, low, mid, high, cmp);

  return;
}

/*
 * Given an array, this function 
 * sorts the array based on the compare
 * function passed. If no compare function 
 * is provided, it uses memcmp(), to compare 
 * the elements of the array.
 *
 * @input1 arr the array to be sorted
 * @input2 arr_size number of elements in
 *                  the array
 * @input3 elem_size size of each individual 
 *                   array element
 * @input4 cmp compare function used to compare two 
 *             array elements
 */
void
merge_sort (void *arr, size_t arr_size,size_t elem_size, 
            cmp_e (*cmp)(const void *, const void *))
{

  if(!arr) {

    printf("ARRAY EMPTY\n");
    return;
  }

  if(arr_size == 0) {

    printf("ARRAY EMPTY\n");
    return;
  }

  if(!cmp) {
  
    printf("Compared function passed as NULL, "
           "memcmp() is used for comparison\n");
  }

  merge_sort_recur(arr, elem_size, 0, arr_size - 1, cmp);
}
