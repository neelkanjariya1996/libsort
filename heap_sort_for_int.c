#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT(ind) ((2 * ind) + 1)
#define RIGHT(ind) ((2 * ind) + 2)

void
print_array (int *arr, int size)
{

  int i = 0;

  for(i = 0; i < size; i++) {
  
    printf("%d ", arr[i]);
  }
  printf("\n");

  return;
}

void
swap (int *a, int *b)
{

  int tmp = 0;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

void
heapify (int *arr, int n, int i)
{

  int largest = i;
  int l = LEFT(i);
  int r = RIGHT(i);

  if((l < n) && (arr[l] > arr[largest])) {
  
    largest = l;
  }

  if((r < n) && (arr[r] > arr[largest])) {
  
    largest = r;
  }

  if(largest != i) {
  
    swap(&arr[i], &arr[largest]);

    heapify(arr, n, largest);
  }
}

void
heap_sort (int *arr, int n)
{

  int i = 0;

  for(i = ((n / 2) - 1); i >= 0; i--) {
  
    heapify(arr, n, i);
  }

  for(i = (n - 1); i > 0; i--) {
  
    swap(&arr[0], &arr[i]);

    heapify(arr, i, 0);
  }
}

int
main ()
{

  int arr[] = {10, 5, 8, 9,7,2,3};
  int size = 0;

  size = sizeof(arr) / sizeof(int);

  printf("Original array: ");
  print_array(arr, size);

  heap_sort(arr, size);

  printf("sorted   array: ");
  print_array(arr, size);
  printf("\n");

  return 0;
}
