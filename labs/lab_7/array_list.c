/* SYSC 2006 Winter 2019 Lab 7
 *
 * array_list.c
 *
 * Prototype of a dynamically allocated, fixed-capacity list that supports a
 * subset of the operations provided by Python's list class.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array_list.h"

/* Construct a new, empty list, and return a pointer to it
 * Parameter capacity is the # of elements that can be stored in the list.
 * Terminate the program via assert if capacity is <= 0.
 * Terminate the program via assert if memory for the list cannot be
 * allocated from the heap.
 */
list_t *list_construct(int capacity)
{
    // Make sure that the capacity is not less than zero
    assert(capacity >= 0);

    // Initialize the list structure
    list_t *list = malloc(sizeof(list_t));

    // Set list variables
    list->capacity = capacity;
    list->size = 0;

    // Initialze the initial capacity of list
    list->elems = malloc(capacity * sizeof(int));
    assert(list->elems != NULL);

    return list;
}

/* Destroy the list pointed to by parameter list, deallocating all memory
 * that was allocated from the heap.
 * Terminate the program via assert if list is NULL.
 */
void list_destroy(list_t *list)
{
    assert(list != NULL);
    free(list->elems);  /* Return the array to the heap. */
    free(list);         /* Return the structure to the heap. */
}

/* Print the list pointed to by parameter list on the console.
 * Terminate the program via assert if list is NULL.
 */
void list_print(const list_t *list)
{
    assert(list != NULL);
	printf("[");
    int n = list->size;

    if (n > 0) {
        /* Print all the array elements, with a leading space before
         * all but the first element.
         */
	    printf("%d", list->elems[0]);

        for (int i = 1; i < n; i += 1) {
	        printf(" %d", list->elems[i]);
	    }
	}
	printf("]");
    printf(", capacity: %d, size: %d\n", list->capacity, list->size);
}

/* Insert element at the end of the list pointed to by list.
 * Return true if element is appended; otherwise return false
 * (which indicates that the list is full.)
 * Terminate the program via assert if list is NULL.
 */
_Bool list_append(list_t *list, int element)
{
    // Check to make sure list is not null
    assert(list != NULL);

    // Check if there is room
    if(list->size < list->capacity) {
        list->elems[list->size++] = element;
        return true;
    }
    return false;
}

/* Return the maximum number of integers that can be stored in the list
 * pointed to by parameter list.
 * Terminate the program via assert if list is NULL.
 */
int list_capacity(const list_t *list)
{
    assert(list != NULL);
    return list->capacity;
}

/* Return the number of integers in the list pointed to by parameter list.
 * Terminate the program via assert if list is NULL.
 */
int list_size(const list_t *list)
{
    assert(list != NULL);
    return list->size;
}

/* Return the element located at the specified index, in the list
 * pointed to by parameter list.
 * Terminate the program via assert if list is NULL,
 * or if index is not in the range 0 .. list_size() - 1.
 */
int list_get(const list_t *list, int index)
{
    assert(list != NULL);
    assert(list->size > index);

    return list->elems[index];
}

/* Store element at the specified index, in the list pointed to by
 * parameter list. Return the integer that was previously
 * stored at that index.
 * Terminate the program via assert if list is NULL,
 * or if index is not in the range 0 .. list_size() - 1.
 */
int list_set(list_t *list, int index, int element)
{
    assert(list != NULL);
    assert(list->size > index);

    int temp = list->elems[index];
    list->elems[index] = element;
    return temp;
}

/* Empty the list pointed to by parameter list.
 * Memory allocated to the list is not freed, so the emptied list can
 * continue to be used.
 * Terminate the program via assert if list is NULL.
 */
void list_removeall(list_t *list)
{
    assert(list != NULL);

    // Set all elements of list to 0
    for(int i = 0; i < list->size; i++) {
        list->elems[i] = 0;
    }

    list->size = 0;
}
