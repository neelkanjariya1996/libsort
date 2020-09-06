#include "sort.h"

/*
 * This function uses memcmp to compare two array elements if NULL is passed 
 * to the compare function, else uses the compare function passed by user.
 *
 * @param1 p1         Pointer to element_1
 * @param2 p2         Pointer to element_2
 * @param3 elem_size  Size of each individual array element
 * @param4 cmp        Compare function to be used if passed from user
 *
 * @return cmp_e      SORT_LT -> element_1 is less than element_2
 *                    SORT_EQ -> element_1 is equal to element_2
 *                    SORT_GT-> element_1 is greater than element_2
 */
static cmp_e
merge_cmp (const void *p1, const void *p2, size_t elem_size,
           cmp_e (*cmp)(const void *, const void *))
{

  int ret = 0;

  if(!cmp) {
 
    ret =  memcmp(p1, p2, elem_size);
    if(ret < 0) {
    
      ret =  SORT_LT;
    } else if (ret > 0) {
    
      ret = SORT_GT;
    } else {
    
      ret = SORT_EQ;
    }
  } else {
    
    ret = (cmp(p1, p2));
  }

  return ret;
}

/*
 * This function merges two subarrays of arr[low...high] and after merging,
 * the array is sorted based on the compare function.
 *
 * The first subarray is arr[low...mid]
 * The second subarray is arr[mid + 1...high]
 * 
 * @param1 arr        The array to be sorted
 * @param2 elem_size  Size of each individual array element
 * @param3 low        Low index of the array
 * @param4 mid        Middle index of the array
 * @param5 high       High index of the array
 * @param6 cmp        Compare function used to compare two array elements
 */
void
merge (void *arr, size_t elem_size, size_t low, size_t mid, size_t high, 
       cmp_e (*cmp)(const void *, const void *))
{

  size_t n1 = 0;    //Size of first subarray
  size_t n2 = 0;    //Size of second subarray
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;
  void *L;          //Temporary array for first subarray
  void *R;          //Temporary array for second subarray

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

  /* Copy first half(low...mid) of array to L
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
  i = 0;            //Initial index of first subarray
  j = 0;            //Initial index of second subarray
  k = low;          //Initial index of merged subarray
  while((i < n1) && (j < n2)) {
  
    /* Compare two elements and place them in the 
     * merged array based on compare function to be
     * used.
     */
    if( merge_cmp((void *)ARR_LOC(L, i, elem_size), 
                  (void *)ARR_LOC(R, j, elem_size), 
                  elem_size, cmp) == SORT_LT) {
    
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
 * @param1 arr        The array to be sorted
 * @param2 elem_size  Size of each individual array element
 * @param3 low        Low index of the subarray
 * @param4 high       High index of the subarray
 * @param5 cmp        Compare function used to compare two array elements
 */
void
merge_sort_recur (void *arr, size_t elem_size, size_t low, size_t high,
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
 * Given an array, this function sorts the array based on the compare function
 * passed. If no compare function is provided, it uses memcmp(), to compare 
 * the elements of the array.
 *
 * @param1 arr        The array to be sorted
 * @param2 arr_size   Number of elements in the array
 * @param3 elem_size  Size of each individual array element
 * @param4 cmp        Compare function used to compare two array elements
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
