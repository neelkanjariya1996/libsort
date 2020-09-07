#ifndef __TEST_CMP_FNC_H__

#define __TEST_CMP_FNC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Function to print integer array
 */
void
print_int_array (int *arr, size_t size)
{

  size_t i = 0;

  if(!arr) {

    return;
  }

  for(i = 0; i < size; i++) {
  
    printf("%d ", arr[i]);
  }
  printf("\n");

  return;
}

/*
 * compare function to sort integer array in ascending order
 */
cmp_e
int_cmp_ascending (const void *k1, const void *k2)
{

  int *p1 = NULL;
  int *p2 = NULL;

  if(!k1 && !k2) {
    return SORT_EQ;
  }

  if(!k1) {
    return SORT_LT;
  }

  if(!k2) {
    return SORT_GT;
  }

  p1 = (int *)k1;
  p2 = (int *)k2;

  if(*p1 < *p2) {
    return SORT_LT; 
  } else if(*p1 > *p2) {
    return SORT_GT;
  } else {
    return SORT_EQ;
  }
}

/*
 * compare function to sort integer array in descending order
 */
cmp_e
int_cmp_descending (const void *k1, const void *k2)
{

  return ((-1) * int_cmp_ascending(k1, k2));
}

/* 
 * Function to print float array
 */
void
print_float_array (float *arr, size_t size)
{

  size_t i = 0;

  if(!arr) {

    return;
  }

  for(i = 0; i < size; i++) {
  
    printf("%.2f ", arr[i]);
  }
  printf("\n");

  return;
}

/*
 * compare function to sort float array in ascending order
 */
cmp_e
float_cmp_ascending (const void *k1, const void *k2)
{

  float *p1 = NULL;
  float *p2 = NULL;

  if(!k1 && !k2) {
  
    return SORT_EQ;
  }
  if(!k1) {
  
    return SORT_LT;
  }
  if(!k2) {
  
    return SORT_GT;
  }

  p1 = (float *)k1;
  p2 = (float *)k2;

  if(*p1 < *p2) {
  
    return SORT_LT; 
  } else if(*p1 > *p2) {
  
    return SORT_GT;
  } else {
  
    return SORT_EQ;
  }
}

/*
 * compare function to sort float array in descending order
 */
cmp_e
float_cmp_descending (const void *k1, const void *k2)
{

  return ((-1) * float_cmp_ascending(k1, k2));
}

/*
 * Function to print character array
 */
void
print_char_array (char *arr)
{

  size_t len = 0;

  if(!arr) {

    return;
  }

  len = strlen(arr);

  printf("%s ", arr);
  printf("\n");

  return;
}

/*
 * compare function to sort char array in ascending order
 */
cmp_e
char_cmp_ascending (const void *k1, const void *k2)
{

  char *p1 = NULL;
  char *p2 = NULL;

  if(!k1 && !k2) {
  
    return SORT_EQ;
  }
  if(!k1) {
  
    return SORT_LT;
  }
  if(!k2) {
  
    return SORT_GT;
  }

  p1 = (char *)k1;
  p2 = (char *)k2;

  if(*p1 < *p2) {
  
    return SORT_LT; 
  } else if(*p1 > *p2) {
  
    return SORT_GT;
  } else {
  
    return SORT_EQ;
  }
}

/*
 * compare function to sort char array in descending order
 */
cmp_e
char_cmp_descending (const void *k1, const void *k2)
{

  return ((-1) * char_cmp_ascending(k1, k2));
}

/*
 * structure to represent a point in 2-D plane
 */
typedef struct point_t_ {

  int x;
  int y;
} point_t;

/*
 * Function to print points array
 */
void
print_points_array (point_t *arr, size_t size)
{

  size_t i = 0;

  if(!arr) {

    return;
  }

  for(i = 0; i < size; i++) {
  
    printf("(%d, %d) ", arr[i].x, arr[i].y);
  }
  printf("\n");

  return;
}

/*
 * compare function to sort points array in 
 * ascending order based on x coordinate
 */
cmp_e
point_x_cmp_ascending (const void *k1, const void *k2)
{

  point_t *p1 = NULL;
  point_t *p2 = NULL;

  if(!k1 && !k2) {
  
    return SORT_EQ;
  }
  if(!k1) {
  
    return SORT_LT;
  }
  if(!k2) {
  
    return SORT_GT;
  }

  p1 = (point_t *) k1;
  p2 = (point_t *) k2;

  if(p1->x == p2->x) {
  
    if(p1->y < p2->y) {
    
      return SORT_LT;
    } else if(p1->y > p2->y) {
    
      return SORT_GT;
    } else {
    
      return SORT_EQ;
    }
  } else if(p1->x < p2->x) {
  
    return SORT_LT;
  } else {
  
    return SORT_GT;
  }
}

/*
 * compare function to sort points  array in
 * ascending order based on y coordinate
 */
cmp_e
point_y_cmp_ascending (const void *k1, const void *k2)
{

  point_t *p1 = NULL;
  point_t *p2 = NULL;

  if(!k1 && !k2) {
  
    return SORT_EQ;
  }
  if(!k1) {
  
    return SORT_LT;
  }
  if(!k2) {
  
    return SORT_GT;
  }

  p1 = (point_t *) k1;
  p2 = (point_t *) k2;

  if(p1->y == p2->y) {
  
    if(p1->x < p2->x) {
    
      return SORT_LT;
    } else if(p1->x > p2->x) {
    
      return SORT_GT;
    } else {
    
      return SORT_EQ;
    }
  } else if(p1->y < p2->y) {
  
    return SORT_LT;
  } else {
  
    return SORT_GT;
  }
}

/*
 * compare function to sort points  array in
 * descending order based on x coordinate
 */
cmp_e
point_x_cmp_descending (const void *k1, const void *k2)
{

  return ((-1) * point_x_cmp_ascending(k1, k2));
}

/*
 * compare function to sort points  array in
 * descending order based on y coordinate
 */
cmp_e
point_y_cmp_descending (const void *k1, const void *k2)
{

  return ((-1) * point_y_cmp_ascending(k1, k2));
}

#endif
