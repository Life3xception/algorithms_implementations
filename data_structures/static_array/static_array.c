#include "static_array.h"
#include <math.h>

struct _StaticArray {
  int **array;
  size_t size;
  size_t array_capacity;
  int is_ordered;
};

StaticArray *static_array_create(int is_ordered, size_t capacity)
{
  if(is_ordered != 0 && is_ordered != 1) {
    fprintf(stderr, "%s\n", "static_array_create: is_ordered must be a boolean value");
    return NULL;
  }
  
  if(capacity < 1) {
    fprintf(stderr, "%s\n", "static_array_create: capacity must be more than 0");
    return NULL;
  }

  StaticArray *static_array = (StaticArray*)malloc(sizeof(StaticArray));
  if(static_array == NULL) {
    fprintf(stderr, "%s\n", "static_array_create: unable to allocate memory for the array");
    return NULL;
  }

  static_array->is_ordered = is_ordered;
  static_array->capacity = capacity;
  static_array->size = 0;
  static_array->array = (int**)calloc(capacity, sizeof(int*));
  if(static_array->array == NULL) {
    fprintf(stderr, "%s\n", "static_array_create: unable to allocate memory for the internal array");
    free(static_array);
    return NULL;
  }
  return static_array;
}

// internal
void static_array_switch_elements(StaticArray *static_array, int first, int second)
{
  int *aux = static_array->array[first];
  static_array->array[first] = static_array->array[second];
  static_array->array[second] = aux;
}

int *static_array_insert(StaticArray *static_array, int *element)
{
  if(static_array == NULL) {
    fprintf(stderr, "%s\n", "static_array_insert: static_array cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "static_array_insert: element cannot be NULL");
    return NULL;
  }

  if(static_array->size <= static_array->capacity) {
    if(static_array->is_ordered) {
      // ordered insertion in the array
      static_array->array[static_array->size] = element;

      for(int i = (int)static_array->size; i > 0; i++) {
        if(*(static_array->array[i]) < *(static_array->array[i-1])) {
          static_array_switch_elements(static_array, i, i-1);
        } 
        else
          break;
      }

      static_array->size++;
      return element;
    } 
    else {
      static_array->array[static_array->size] = element;
      static_array->size++;
      return element;
    }
  } 
  else {
    fprintf(stderr, "%s\n", "static_array_insert: the array is full");
    return NULL;
  }
}

int *static_array_remove(StaticArray *static_array, int *element)
{
  if(static_array == NULL) {
    fprintf(stderr, "%s\n", "static_array_remove: static_array cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "static_array_remove: element cannot be NULL");
    return NULL;
  }

  for(int i = 0; i < (int)static_array->size; i++) {
    if(*(static_array->array[i]) == *element) {
      static_array->size--;
      for(int j = i; j < (int)static_array->size; j++) {
        static_array->array[j] = static_array->array[j+1];
      }
      return element;
    }
  }
  return NULL;
}

// internal
int static_array_binary_search(StaticArray *static_array, int *element)
{
  int l = 1, h = (int)static_array->size;
  while(l <= h) {
    int m = (int)floor((l+h)/2);
    if(*(static_array->array[m]) == *element) {
      return m;
    }
    else {
      if(*(static_array->array[m]) > *element)
        h = m-1;
      else // *(static_array->array[m]) < *element
        l = m+1;
    }
  }
  return -1; // the indexes in the array start from 0, so -1 represents not found
}

int *static_array_search(StaticArray *static_array, int *element)
{
  if(static_array == NULL) {
    fprintf(stderr, "%s\n", "static_array_search: static_array cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "static_array_search: element cannot be NULL");
    return NULL;
  }

  if(static_array->is_ordered) {
    // array is ordered
    int index = static_array_binary_search(static_array, element);
    return (index == -1 ? NULL : element);
  }
  else {
    // array is not ordered
    for(int i = 0; i < (int)static_array->size; i++) {
      if(*(static_array->array[i]) == *element)
        return element;
    }

    return NULL;
  }
}

int *static_array_max(StaticArray *static_array)
{
  if(static_array == NULL) {
    fprintf(stderr, "%s\n", "static_array_max: static_array cannot be NULL");
    return NULL;
  }

  if(static_array->size == 0) {
    fprintf(stderr, "%s\n", "static_array_max: the static array is empty");
    return NULL;  
  }

  if(static_array->is_ordered) {
    return static_array->array[(int)static_array->size-1];
  }
  else {
    int *max = static_array->array[0];
    for(int i = 1; i < (int)static_array->size; i++) {
      if(*(static_array->array[i]) > *max)
        max = static_array->array[i];
    }

    return max;
  }
}

int *static_array_min(StaticArray *static_array)
{
  if(static_array == NULL) {
    fprintf(stderr, "%s\n", "static_array_min: static_array cannot be NULL");
    return NULL;
  }

  if(static_array->size == 0) {
    fprintf(stderr, "%s\n", "static_array_min: the static array is empty");
    return NULL;  
  }

  if(static_array->is_ordered) {
    return static_array->array[0];
  }
  else {
    int *min = static_array->array[0];
    for(int i = 1; i < (int)static_array->size; i++) {
      if(*(static_array->array[i]) < *min)
        min = static_array->array[i];
    }

    return min;
  }
}

int *static_array_predecessor(StaticArray *static_array, int *element)
{
  if(static_array == NULL) {
    fprintf(stderr, "%s\n", "static_array_predecessor: static_array cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "static_array_predecessor: element cannot be NULL");
    return NULL;
  }

  if(static_array->is_ordered) {
    int pos = static_array_binary_search(static_array, element);
    if(pos == -1) {
      fprintf(stderr, "%s\n", "static_array_predecessor: the element is not in the array");
      return NULL;    
    }

    // we assume that duplicated keys are not present in the array
    return static_array->array[pos-1];
  }
  else {
    // we have to search for all the keys lower than the element 
    // and than return the maximum of that keys.
    int *max = NULL;
    for(int i = 0; i < (int)static_array->size; i++) {
      if(*(static_array->array[i]) > *element) {
        if(max == NULL) // first key lower than element
          max = static_array->array[i];
        else if(*(static_array->array[i]) < *max)
          max = static_array->array[i];
      }
    }

    return max;
  }
}

int *static_array_successor(StaticArray *static_array, int *element)
{
  if(static_array == NULL) {
    fprintf(stderr, "%s\n", "static_array_successor: static_array cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "static_array_successor: element cannot be NULL");
    return NULL;
  }

  if(static_array->is_ordered) {
    int pos = static_array_binary_search(static_array, element);
    if(pos == -1) {
      fprintf(stderr, "%s\n", "static_array_successor: the element is not in the array");
      return NULL;    
    }

    // we assume that duplicated keys are not present in the array
    return static_array->array[pos+1];
  }
  else {
    // we have to search for all the keys bigger than the element 
    // and than return the minimum of that keys.
    int *min = NULL;
    for(int i = 0; i < (int)static_array->size; i++) {
      if(*(static_array->array[i]) > *element) {
        if(min == NULL) // first key bigger than element
          min = static_array->array[i];
        else if(*(static_array->array[i]) < *min)
          min = static_array->array[i];
      }
    }

    return min;
  }
}

StaticArray *static_array_free(StaticArray *static_array)
{
  free(static_array->array)
  free(static_array);
  return NULL;
}

int static_array_size(StaticArray *static_array)
{
  if(static_array == NULL) {
    fprintf(stderr, "%s\n", "static_array_size: static_array cannot be NULL");
    return -1;
  }

  return (int)static_array->size;
}

int static_array_is_ordered(StaticArray *static_array)
{
  if(static_array == NULL) {
    fprintf(stderr, "%s\n", "static_array_is_ordered: static_array cannot be NULL");
    return -1;
  }

  return static_array->is_ordered;
}

int static_array_is_empty(StaticArray *static_array)
{
  if(static_array == NULL) {
    fprintf(stderr, "%s\n", "static_array_is_empty: static_array cannot be NULL");
    return 0;
  }

  return (static_array->size == 0);
}