#ifndef STATIC_ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#define STATIC_ARRAY_H

typedef struct _StaticArray StaticArray;

/*
 * Method that creates the static array. 
 * Time complexity: O(1)
 * @param is_ordered: boolean, 1 if the array is ordered, 0 otherwise
 * @param capacity: the maximum number of elements in the array
 * @return the pointer to the static array
 */
StaticArray *static_array_create(int is_ordered, long unsigned capacity);

/*
 * Method that inserts the element in the static array. 
 * Time complexity: O(1) if static_array is not ordered, O(N) if is ordered
 * @param static_array: the pointer to the static array
 * @param element: the pointer to the element to insert
 * @return the pointer to the element if the insertion is successful, NULL otherwise
 */
int *static_array_insert(StaticArray *static_array, int *element);

/*
 * Method that removes the element from the static array. 
 * Time complexity: O(N)
 * @param static_array: the pointer to the static array
 * @param element: the pointer to the element to remove
 * @return the pointer to the element if the removal is successful, NULL otherwise
 */
int *static_array_remove(StaticArray *static_array, int *element);

/*
 * Method that searches if the element from the static array is present. 
 * Time complexity: O(N) if static_array is not ordered, O(log N) if ordered
 * @param static_array: the pointer to the static array
 * @param element: the pointer to the element to search
 * @return the pointer to the element if it is in the array, NULL otherwise
 */
int *static_array_search(StaticArray *static_array, int *element);

/*
 * Method that returns the maximum element in the static array. 
 * Time complexity: O(N) if static_array is not ordered, O(1) if ordered
 * @param static_array: the pointer to the static array
 * @return the pointer to the maximum element, NULL in case of error
 */
int *static_array_max(StaticArray *static_array);

/*
 * Method that returns the minimum element in the static array. 
 * Time complexity: O(N) if static_array is not ordered, O(1) if ordered
 * @param static_array: the pointer to the static array
 * @return the pointer to the minimum element, NULL in case of error
 */
int *static_array_min(StaticArray *static_array);

/*
 * Method that returns the predecessor of the passed element in the static array. 
 * Time complexity: O(N) if static_array is not ordered, O(log N) if ordered
 * @param static_array: the pointer to the static array
 * @param element: the pointer to the element whose predecessor we search
 * @return the pointer to the predecessor of the element, NULL in case of error
 */
int *static_array_predecessor(StaticArray *static_array, int *element);

/*
 * Method that returns the successor of the passed element in the static array. 
 * Time complexity: O(N) if static_array is not ordered, O(log N) if ordered
 * @param static_array: the pointer to the static array
 * @param element: the pointer to the element whose successor we search
 * @return the pointer to the successor of the element, NULL in case of error
 */
int *static_array_successor(StaticArray *static_array, int *element);

/*
 * Method that free the space occupied by the static array. 
 * Time complexity: O(1)
 * @param static_array: the pointer to the static array
 * @return NULL if the free fails (??)
 */
StaticArray *static_array_free(StaticArray *static_array);

/*
 * Method that returns the size of the static array. 
 * Time complexity: O(1)
 * @param static_array: the pointer to the static array
 * @return the size of the static_array, NULL in case of error.
 */
int static_array_size(StaticArray *static_array);

/*
 * Method that returns whether the static array is ordered or not. 
 * Time complexity: O(1)
 * @param static_array: the pointer to the static array
 * @return true if static_array is ordered, false otherwise.
 */
int static_array_is_ordered(StaticArray *static_array);

/*
 * Method that returns whether the static array is empty or not. 
 * Time complexity: O(1)
 * @param static_array: the pointer to the static array
 * @return true if static_array is empty, false otherwise.
 */
int static_array_is_empty(StaticArray *static_array);

/*
 * Method that prints the static array to stdout. 
 * Time complexity: O(N)
 * @param static_array: the pointer to the static array
 */
void static_array_print(StaticArray *static_array);
#endif /* STATIC_ARRAY_H */