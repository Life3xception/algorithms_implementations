#include "dynamic_array.h"
#include <math.h>

struct _DynamicArray {
  int **array;
  long unsigned size;
  long unsigned capacity;
  int is_ordered;
};

DynamicArray *dynamic_array_create(int is_ordered, long unsigned capacity)
{
  if(is_ordered != 0 && is_ordered != 1) {
    fprintf(stderr, "%s\n", "dynamic_array_create: is_ordered must be a boolean value");
    return NULL;
  }
  
  if(capacity < 1) {
    fprintf(stderr, "%s\n", "dynamic_array_create: capacity must be more than 0");
    return NULL;
  }

  DynamicArray *dynamic_array = (DynamicArray*)malloc(sizeof(DynamicArray));
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_create: unable to allocate memory for the array");
    return NULL;
  }

  dynamic_array->is_ordered = is_ordered;
  dynamic_array->capacity = capacity;
  dynamic_array->size = 0;
  dynamic_array->array = (int**)calloc(capacity, sizeof(int*));
  if(dynamic_array->array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_create: unable to allocate memory for the internal array");
    free(dynamic_array);
    return NULL;
  }
  return dynamic_array;
}

// internal
void dynamic_array_switch_elements(DynamicArray *dynamic_array, int first, int second)
{
  int *aux = dynamic_array->array[first];
  dynamic_array->array[first] = dynamic_array->array[second];
  dynamic_array->array[second] = aux;
}

int *dynamic_array_insert(DynamicArray *dynamic_array, int *element)
{
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_insert: dynamic_array cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_insert: element cannot be NULL");
    return NULL;
  }

  // increase the space allocated for the array if it is full
  if(dynamic_array->size == dynamic_array->capacity) {
    dynamic_array->capacity *= 2;
    dynamic_array->array = (int**)realloc(dynamic_array->array, dynamic_array->capacity);
    if(dynamic_array->array == NULL) {
      fprintf(stderr, "%s\n", "dynamic_array_insert: unable to reallocate memory for the internal array");
      return NULL;
    }
  }

  if(dynamic_array->is_ordered) {
    // ordered insertion in the array
    dynamic_array->array[dynamic_array->size] = element;

    for(int i = (int)dynamic_array->size; i > 0; i++) {
      if(*(dynamic_array->array[i]) < *(dynamic_array->array[i-1])) {
        dynamic_array_switch_elements(dynamic_array, i, i-1);
      } 
      else
        break;
    }

    dynamic_array->size++;
    return element;
  } 
  else {
    dynamic_array->array[dynamic_array->size] = element;
    dynamic_array->size++;
    return element;
  }
}

// internal
int *array_remove(DynamicArray *dynamic_array, int *element)
{
  for(int i = 0; i < (int)dynamic_array->size; i++) {
    if(*(dynamic_array->array[i]) == *element) {
      dynamic_array->size--;
      for(int j = i; j < (int)dynamic_array->size; j++) {
        dynamic_array->array[j] = dynamic_array->array[j+1];
      }
      return element;
    }
  }
  return NULL;
}

int *dynamic_array_remove(DynamicArray *dynamic_array, int *element)
{
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_remove: dynamic_array cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_remove: element cannot be NULL");
    return NULL;
  }

  int *el_removed = array_remove(dynamic_array, element);
  if(el_removed == NULL)
      return NULL;

  // reduce the space allocated for the array if it is too big
  if(dynamic_array->size <= (long unsigned)(0.25 * (double)dynamic_array->capacity)) {
    dynamic_array->capacity /= 2;
    dynamic_array->array = (int**)realloc(dynamic_array->array, dynamic_array->capacity);
    if(dynamic_array->array == NULL) {
      fprintf(stderr, "%s\n", "dynamic_array_remove: unable to reallocate memory for the internal array");
      return NULL;
    }
  }

  return el_removed;
}

// internal
int dynamic_array_binary_search(DynamicArray *dynamic_array, int *element)
{
  int l = 0, h = (int)dynamic_array->size-1;
  while(l <= h) {
    int m = (int)floor((l+h)/2);
    if(*(dynamic_array->array[m]) == *element) {
      return m;
    }
    else {
      if(*(dynamic_array->array[m]) > *element)
        h = m-1;
      else // *(dynamic_array->array[m]) < *element
        l = m+1;
    }
  }
  return -1; // the indexes in the array start from 0, so -1 represents not found
}

int *dynamic_array_search(DynamicArray *dynamic_array, int *element)
{
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_search: dynamic_array cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_search: element cannot be NULL");
    return NULL;
  }

  if(dynamic_array->is_ordered) {
    // array is ordered
    int index = dynamic_array_binary_search(dynamic_array, element);
    return (index == -1 ? NULL : element);
  }
  else {
    // array is not ordered
    for(int i = 0; i < (int)dynamic_array->size; i++) {
      if(*(dynamic_array->array[i]) == *element)
        return element;
    }

    return NULL;
  }
}

int *dynamic_array_max(DynamicArray *dynamic_array)
{
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_max: dynamic_array cannot be NULL");
    return NULL;
  }

  if(dynamic_array->size == 0) {
    fprintf(stderr, "%s\n", "dynamic_array_max: the dynamic array is empty");
    return NULL;  
  }

  if(dynamic_array->is_ordered) {
    return dynamic_array->array[(int)dynamic_array->size-1];
  }
  else {
    int *max = dynamic_array->array[0];
    for(int i = 1; i < (int)dynamic_array->size; i++) {
      if(*(dynamic_array->array[i]) > *max)
        max = dynamic_array->array[i];
    }

    return max;
  }
}

int *dynamic_array_min(DynamicArray *dynamic_array)
{
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_min: dynamic_array cannot be NULL");
    return NULL;
  }

  if(dynamic_array->size == 0) {
    fprintf(stderr, "%s\n", "dynamic_array_min: the dynamic array is empty");
    return NULL;  
  }

  if(dynamic_array->is_ordered) {
    return dynamic_array->array[0];
  }
  else {
    int *min = dynamic_array->array[0];
    for(int i = 1; i < (int)dynamic_array->size; i++) {
      if(*(dynamic_array->array[i]) < *min)
        min = dynamic_array->array[i];
    }

    return min;
  }
}

int *dynamic_array_predecessor(DynamicArray *dynamic_array, int *element)
{
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_predecessor: dynamic_array cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_predecessor: element cannot be NULL");
    return NULL;
  }

  if(dynamic_array->is_ordered) {
    int pos = dynamic_array_binary_search(dynamic_array, element);
    if(pos == -1) {
      fprintf(stderr, "%s\n", "dynamic_array_predecessor: the element is not in the array");
      return NULL;    
    }

    // we assume that duplicated keys are not present in the array
    if(pos > 0)
      return dynamic_array->array[pos-1];
    else // there isn't a predecessor in the array
      return NULL;
  }
  else {
    // we have to search for all the keys lower than the element 
    // and than return the maximum of that keys.
    int *max = NULL;
    for(int i = 0; i < (int)dynamic_array->size; i++) {
      if(*(dynamic_array->array[i]) < *element) {
        if(max == NULL) // first key lower than element
          max = dynamic_array->array[i];
        else if(*(dynamic_array->array[i]) > *max)
          max = dynamic_array->array[i];
      }
    }

    return max;
  }
}

int *dynamic_array_successor(DynamicArray *dynamic_array, int *element)
{
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_successor: dynamic_array cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_successor: element cannot be NULL");
    return NULL;
  }

  if(dynamic_array->is_ordered) {
    int pos = dynamic_array_binary_search(dynamic_array, element);
    if(pos == -1) {
      fprintf(stderr, "%s\n", "dynamic_array_successor: the element is not in the array");
      return NULL;    
    }

    // we assume that duplicated keys are not present in the array
    if(pos < (int)dynamic_array->size-1)
      return dynamic_array->array[pos+1];
    else // there isn't a successor in the array
      return NULL;
  }
  else {
    // we have to search for all the keys bigger than the element 
    // and than return the minimum of that keys.
    int *min = NULL;
    for(int i = 0; i < (int)dynamic_array->size; i++) {
      if(*(dynamic_array->array[i]) > *element) {
        if(min == NULL) // first key bigger than element
          min = dynamic_array->array[i];
        else if(*(dynamic_array->array[i]) < *min)
          min = dynamic_array->array[i];
      }
    }

    return min;
  }
}

DynamicArray *dynamic_array_free(DynamicArray *dynamic_array)
{
  free(dynamic_array->array);
  free(dynamic_array);
  return NULL;
}

int dynamic_array_size(DynamicArray *dynamic_array)
{
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_size: dynamic_array cannot be NULL");
    return -1;
  }

  return (int)dynamic_array->size;
}

int dynamic_array_is_ordered(DynamicArray *dynamic_array)
{
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_is_ordered: dynamic_array cannot be NULL");
    return -1;
  }

  return dynamic_array->is_ordered;
}

int dynamic_array_is_empty(DynamicArray *dynamic_array)
{
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_is_empty: dynamic_array cannot be NULL");
    return 0;
  }

  return (dynamic_array->size == 0);
}

void dynamic_array_print(DynamicArray *dynamic_array)
{
  if(dynamic_array == NULL) {
    fprintf(stderr, "%s\n", "dynamic_array_print: dynamic_array cannot be NULL");
  }

  printf("\nPrinting dynamic array...\n");
  for(long unsigned i = 0; i < dynamic_array->size; i++)
    printf("\t- %i\n", *(dynamic_array->array[i]));
  printf("\n");
}