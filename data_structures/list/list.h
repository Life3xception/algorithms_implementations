#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct _List List;
typedef struct _Node Node;
// VEDERE SE VANNO BENE

/*
 * Method that creates the list. 
 * Time complexity: O(1)
 * @param is_ordered: boolean, 1 if the list is ordered, 0 otherwise
 * @param is_circular: boolean, 1 if the list is circular, 0 otherwise
 * @return the pointer to the list
 */
List *list_create(int is_ordered, int is_circular);

/*
 * Method that returns whether the list is empty or not. 
 * Time complexity: O(1)
 * @param list: the pointer to the list
 * @return true if list is empty, false otherwise.
 */
int list_is_empty(List *list);

/*
 * Method that returns whether the list is ordered or not. 
 * Time complexity: O(1)
 * @param list: the pointer to the list
 * @return true if list is ordered, false otherwise.
 */
int list_is_ordered(List *list);

/*
 * Method that returns whether the list is circular or not. 
 * Time complexity: O(1)
 * @param list: the pointer to the list
 * @return true if list is circular, false otherwise.
 */
int list_is_circular(List *list);

/*
 * Method that inserts a node with the element from the head of the list
 * Time complexity: O(1)
 * @param list: pointer to the list in which the node has to be inserted
 * @param element: pointer to the element that has to be the key of the new node
 * @return the pointer to the element if successful, NULL in case of error
 */
int *list_insert_head(List *list, int *element);

/*
 * Method that inserts a node with the element in an ordered list
 * Time complexity: O(N)
 * @param list: pointer to the list in which the node has to be inserted
 * @param element: pointer to the element that has to be the key of the new node
 * @return the pointer to the element if successful, NULL in case of error
 */
int *list_insert_ordered(List *list, int *element);

/*
 * Method that frees the space allocated by the list
 * Time complexity: O(1)
 * @param list: pointer to the list we want to free
 * @return NULL
 */
List *list_free(List *list);

/*
 * Method that searches the key in the list
 * Time complexity: O(N)
 * @param list: pointer to the list in which we have to search the key
 * @param key: pointer to the key that we want to search
 * @return the pointer to the key if successful, NULL in case of error
 */
int *list_search(List *list, int *key);

/*
 * Method that prints the list
 * Time complexity: O(N)
 * @param list: pointer to the list we want to print
 */
void list_print(List *list);

/*
 * Method that removes the element from the list, if present; if duplicated
 * values are present, it removes only the first occurrence found.
 * Time complexity: O(N)
 * @param list: pointer to the list from which we have to remove the element
 * @param element: pointer to the element that we want to remove
 * @return the pointer to the element if successful, NULL in case of error
 */
int *list_delete(List *list, int *element);

#endif /* LIST_H */