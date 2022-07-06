#ifndef DYNAMIC_ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#define DYNAMIC_ARRAY_H

typedef struct _DynamicArray DynamicArray;

/*
 * Method that creates the dynamic array. 
 * Time complexity: O(1)
 * @param is_ordered: boolean, 1 if the array is ordered, 0 otherwise
 * @param capacity: the maximum number of elements in the array
 * @return the pointer to the dynamic array
 */
DynamicArray *dynamic_array_create(int is_ordered, long unsigned capacity);

/*
 * Method that inserts the element in the dynamic array. 
 * Time complexity: O(1) if dynamic_array is not ordered, O(N) if is ordered
 * @param dynamic_array: the pointer to the dynamic array
 * @param element: the pointer to the element to insert
 * @return the pointer to the element if the insertion is successful, NULL otherwise
 */
int *dynamic_array_insert(DynamicArray *dynamic_array, int *element);

/*
 * Method that removes the element from the dynamic array. 
 * Time complexity: O(N)
 * @param dynamic_array: the pointer to the dynamic array
 * @param element: the pointer to the element to remove
 * @return the pointer to the element if the removal is successful, NULL otherwise
 */
int *dynamic_array_remove(DynamicArray *dynamic_array, int *element);

/*
 * Method that searches if the element from the dynamic array is present. 
 * Time complexity: O(N) if dynamic_array is not ordered, O(log N) if ordered
 * @param dynamic_array: the pointer to the dynamic array
 * @param element: the pointer to the element to search
 * @return the pointer to the element if it is in the array, NULL otherwise
 */
int *dynamic_array_search(DynamicArray *dynamic_array, int *element);

/*
 * Method that returns the maximum element in the dynamic array. 
 * Time complexity: O(N) if dynamic_array is not ordered, O(1) if ordered
 * @param dynamic_array: the pointer to the dynamic array
 * @return the pointer to the maximum element, NULL in case of error
 */
int *dynamic_array_max(DynamicArray *dynamic_array);

/*
 * Method that returns the minimum element in the dynamic array. 
 * Time complexity: O(N) if dynamic_array is not ordered, O(1) if ordered
 * @param dynamic_array: the pointer to the dynamic array
 * @return the pointer to the minimum element, NULL in case of error
 */
int *dynamic_array_min(DynamicArray *dynamic_array);

/*
 * Method that returns the predecessor of the passed element in the dynamic array. 
 * Time complexity: O(N) if dynamic_array is not ordered, O(log N) if ordered
 * @param dynamic_array: the pointer to the dynamic array
 * @param element: the pointer to the element whose predecessor we search
 * @return the pointer to the predecessor of the element, NULL in case of error
 */
int *dynamic_array_predecessor(DynamicArray *dynamic_array, int *element);

/*
 * Method that returns the successor of the passed element in the dynamic array. 
 * Time complexity: O(N) if dynamic_array is not ordered, O(log N) if ordered
 * @param dynamic_array: the pointer to the dynamic array
 * @param element: the pointer to the element whose successor we search
 * @return the pointer to the successor of the element, NULL in case of error
 */
int *dynamic_array_successor(DynamicArray *dynamic_array, int *element);

/*
 * Method that free the space occupied by the dynamic array. 
 * Time complexity: O(1)
 * @param dynamic_array: the pointer to the dynamic array
 * @return NULL 
 */
DynamicArray *dynamic_array_free(DynamicArray *dynamic_array);

/*
 * Method that returns the size of the dynamic array. 
 * Time complexity: O(1)
 * @param dynamic_array: the pointer to the dynamic array
 * @return the size of the dynamic_array, NULL in case of error.
 */
int dynamic_array_size(DynamicArray *dynamic_array);

/*
 * Method that returns whether the dynamic array is ordered or not. 
 * Time complexity: O(1)
 * @param dynamic_array: the pointer to the dynamic array
 * @return true if dynamic_array is ordered, false otherwise.
 */
int dynamic_array_is_ordered(DynamicArray *dynamic_array);

/*
 * Method that returns whether the dynamic array is empty or not. 
 * Time complexity: O(1)
 * @param dynamic_array: the pointer to the dynamic array
 * @return true if dynamic_array is empty, false otherwise.
 */
int dynamic_array_is_empty(DynamicArray *dynamic_array);

/*
 * Method that prints the dynamic array to stdout. 
 * Time complexity: O(N)
 * @param dynamic_array: the pointer to the dynamic array
 */
void dynamic_array_print(DynamicArray *dynamic_array);
#endif /* DYNAMIC_ARRAY_H */