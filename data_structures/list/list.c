#include "list.h"

struct _Node {
  int *key;
  Node *next;
};

struct _List {
  Node *head;
  Node *tail;
  int is_ordered;  
  int is_circular;
};

List *list_create(int is_ordered, int is_circular)
{
  if(is_ordered != 0 && is_ordered != 1) {
    fprintf(stderr, "%s\n", "list_create: is_ordered must be a boolean value");
    return NULL;
  }

  if(is_circular != 0 && is_circular != 1) {
    fprintf(stderr, "%s\n", "list_create: is_circular must be a boolean value");
    return NULL;
  }

  List *list = (List*)malloc(sizeof(List));
  if(list == NULL) {
    fprintf(stderr, "%s\n", "list_create: unable to allocate space for the list");
    return NULL; 
  }

  list->is_ordered = is_ordered;
  list->is_circular = is_circular;
  list->head = NULL; // at the beginning the list is empty
  list->tail = NULL; // at the beginning the list is empty
  return list;
}

int list_is_empty(List *list)
{
  if(list == NULL)
    return 0;

  return list->head == NULL;
}

int list_is_ordered(List *list)
{
  if(list == NULL)
    return 0;

  return list->is_ordered;
}

int list_is_circular(List *list)
{
  if(list == NULL)
    return 0;

  return list->is_circular;
}

int *list_insert_head(List *list, int *element)
{
  if(list == NULL) {
    fprintf(stderr, "%s\n", "list_insert_head: list cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "list_insert_head: element cannot be NULL");
    return NULL;
  }

  if(list->is_ordered) {
    fprintf(stderr, "%s\n", "list_insert_head: cannot perform head insertion in an ordered list");
    return NULL;
  }

  Node *new_node = (Node*)malloc(sizeof(Node));
  if(new_node == NULL) {
    fprintf(stderr, "%s\n", "list_insert_head: unable to allocate space for the new node");
    return NULL;
  }

  new_node->key = element;
  new_node->next = list->head;
  list->head = new_node;

  if(list->tail == NULL) // the list was empty, we have to upgrade also the tail
    list->tail = new_node;

  // if the list is circular, we have to upgrade the pointer of the tail to the new head
  if(list->is_circular)
      list->tail->next = list->head;
  
  return element;
}

int *list_insert_ordered(List *list, int *element)
{
  if(list == NULL) {
    fprintf(stderr, "%s\n", "list_insert_ordered: list cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "list_insert_ordered: element cannot be NULL");
    return NULL;
  }

  if(!list->is_ordered) {
    fprintf(stderr, "%s\n", "list_insert_ordered: cannot perform ordered insertion in a disordered list");
    return NULL;
  }

  Node *new_node = (Node*)malloc(sizeof(Node));
  if(new_node == NULL) {
    fprintf(stderr, "%s\n", "list_insert_head: unable to allocate space for the new node");
    return NULL;
  }

  new_node->key = element;
  new_node->next = NULL;

  if(list->head == NULL) {
    // the list is empty, we have to upgrade head and tail
    list->head = new_node;
    list->tail = new_node;
  }
  else {
    // searching the correct place for the element to insert
    Node *curr = list->head;
    Node *prev = NULL;
    while(curr != list->tail && *(curr->key) < *element) {
      prev = curr;
      curr = curr->next;
    }

    if(*(curr->key) >= *element) {
      // we have to insert the element between two already existing
      if(prev == NULL) {
        // the element is to be inserted as the new head
        new_node->next = list->head;
        list->head = new_node;
      }
      else {
        // we have to insert the element between prev and curr
        prev->next = new_node;
        new_node->next = curr;
      }
    }
    else {
      // we arrived at the tail of the list
      if(*(list->tail->key) >= *element) {
        // element goes before tail
        prev->next = new_node;
        new_node->next = curr; 
      }
      else {
        // element becomes the new tail
        list->tail->next = new_node;
        list->tail = new_node;
      }
    }
  }

  // if the list is circular, we have to upgrade the pointer of the tail to the new head
  if(list->is_circular)
      list->tail->next = list->head;

  return element;
}

List *list_free(List *list)
{
  if(list != NULL) {
    Node *node = list->head; // non va quando head = tail
    while(node != NULL) { // in this way, it works also for circular lists
      Node *tmp = node;

      if(node == list->tail)
        node = NULL; // way to exit from this loop if the list is circular
      else
        node = node->next;
      
      free(tmp);
    }
    free(list);
  }

  return NULL;
}

int *list_search(List *list, int *key)
{
  if(list == NULL) {
    fprintf(stderr, "%s\n", "list_search: list cannot be NULL");
    return NULL;
  }

  if(key == NULL) {
    fprintf(stderr, "%s\n", "list_search: key cannot be NULL");
    return NULL;
  }

  Node *x = list->head;
  while(x != list->tail && x->key != key)
    x = x->next;

  if(x->key == key)
    return x->key;

  return NULL;
}

void list_print(List *list)
{
  if(list == NULL) {
    printf("List is NULL\n");
  }
  int count = 0;

  printf("Printing the list:\n\t");
  Node *x = list->head;
  while(x != list->tail) {
    if(count > 13) {
      printf("\n\t");
      count = 0;
    }
    printf("[%i] -> ", *(x->key));
    x = x->next;
    count++;
  }

  printf("[%i]\n", *(x->key));
}

int *list_delete(List *list, int *element)
{
  if(list == NULL) {
    fprintf(stderr, "%s\n", "list_delete: list cannot be NULL");
    return NULL;
  }

  if(element == NULL) {
    fprintf(stderr, "%s\n", "list_delete: element cannot be NULL");
    return NULL;
  }

  // searching the node to be removed
  Node *curr = list->head;
  Node *prev = NULL;
  while(curr != list->tail && curr->key != element) {
    prev = curr;
    curr = curr->next;
  }

  if(curr->key == element) {
    // found the element to be removed
    if(prev == NULL) {
      // the element to be removed is the head of the list
      list->head = list->head->next;

      // if the list is circular, update the tail pointer to the head
      if(list->is_circular)
        list->tail->next = list->head;
    }
    else {
      prev->next = curr->next;
      // it's ok also for a circular list and for an ordered list
    }
    
    free(curr);
    return element;
  }
  else {
    fprintf(stderr, "%s\n", "list_delete: the element to be removed is not present in the list");
    return NULL;
  }
}