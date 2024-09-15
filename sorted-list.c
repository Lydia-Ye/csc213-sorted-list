#include "sorted-list.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Initialize a sorted list.
 *
 * \param lst This is a pointer to space that should be initialized as a sorted list. The caller of
 * this function retains ownership of the memory that lst points to (meaning the caller must free it
 * if the pointer was returned from malloc)
 */
void sorted_list_init(sorted_list_t* lst) {
  // an empty sorted list
  lst->head = NULL;
}

/**
 * Destroy a sorted list. Free any memory allocated to store the list, but not the list itself.
 *
 * \param lst This is a pointer to the space that holds the list being destroyred. This function
 * should free any memory used to represent the list, but the caller retains ownership of the lst
 * pointer itself.
 */
void sorted_list_destroy(sorted_list_t* lst) {
  node_t * current = lst->head;
  node_t * next = current->next;

  // free each node in the sorted list
  while (current != NULL) {
    free(current);
    current = next;
    next = current->next;
  }

  // reinitializa the empty sorted list
  lst->head = NULL;
}

/**
 * Add an element to a sorted list, maintaining the lowest-to-highest sorted order.
 *
 * \param lst   The list that is being inserted to
 * \param value The value being inserted
 */
void sorted_list_insert(sorted_list_t* lst, int value) {
  // create and initialize a new node
  node_t * newNode = malloc(sizeof(node_t));
  newNode->value = value;
  newNode->next = NULL;

  // insert the new node to an empty sorted list
  if (lst->head == NULL) {
    lst->head = newNode;
    return;
  }

  // if lst is not empty, find the position to insert the new node
  node_t * current = lst->head;
  node_t * prev = NULL;

  while (current->value <= newNode->value) {
    prev = current;
    current = current->next;
  }

  prev->next = newNode;
  newNode->next = current;
}

/**
 * Count how many times a value appears in a sorted list.
 *
 * \param lst The list being searched
 * \param value The value being counted
 * \returns the number of times value appears in lst
 */
size_t sorted_list_count(sorted_list_t* lst, int value) {
  size_t count = 0;
  node_t * current = lst->head;

  // loop through each node in the list to count the appearance of value
  while (current != NULL) {
    if (current->value == value) {
      count++;
    } 
    current = current->next;
  }
  
  return count;
}

/**
 * Print the values in a sorted list in ascending order, separated by spaces and followed by a
 * newline.
 *
 * \param lst The list to print
 */
void sorted_list_print(sorted_list_t* lst) {
  node_t * current = lst->head;

  // loop through each node in the list to count the appearance of value
  while (current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }
}
