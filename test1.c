#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ONE_GB_BYTE 128000000

int
main()
{

  int *arr;
  size_t size = 0;
  size_t i = 0;

  size = ONE_GB_BYTE / sizeof(int);

  arr = malloc(size * sizeof(int));

  for(i = 0; i < size; i++) {
  
    arr[i] = i;
    printf("%d ", arr[i]);
  }

  return 0;
}
