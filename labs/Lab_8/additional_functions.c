#include "array_list.h"
#include <stdlib.h>
#include <assert.h>

/* SYSC 2006 Winter 2019 Lab 8
 *
 * additional_functions.c
 */

/* Return the index (position) of the first occurrence of an integer
 * equal to target in the list pointed to by parameter list.
 * Return -1 if target is not in the list.
 * Terminate the program via assert if list is NULL.
 */
int list_index(const list_t *list, int target)
{
    assert(list != NULL);

    for(int i = 0; i < list->size; i++) {
        if(list->elems[i] == target)
            return i;
    }

    return -1;
}

/* Count the number of integers that are equal to target, in the list
 * pointed to by parameter list, and return that number.
 * Terminate the program via assert if list is NULL.
 */
int list_count(const list_t *list, int target)
{
    assert(list != NULL);

    int count = 0;

    for(int i = 0; i < list->size; i++) {
        if(list->elems[i] == target)
            count++;
    }

    return count;
}

/* Determine if an integer in the list pointed to by parameter list
 * is equal to target.
 * Return true if target is in the list, otherwise return false.
 * Terminate the program via assert if list is NULL.
 */
_Bool list_contains(const list_t *list, int target)
{
    assert(list != NULL);

    for(int i = 0; i < list->size; i++) {
        if(list->elems[i] == target)
            return true;
    }

    return false;
}

/* Increase the capacity of the list pointed to by parameter list to
 * the specified new capacity.
 * Terminate the program via assert if new_capacity is not greater than the
 * list's current capacity, or if the memory required to increase the
 * list's capacity cannot be allocated.
 */
void increase_capacity(list_t *list, int new_capacity)
{
    assert(list != NULL);
    assert(list->capacity < new_capacity);

    // Make sure that the old list does not go out of range
    int *old_list = list->elems;

    // Allocate new memory to the list
    list->elems = malloc(new_capacity * sizeof(int));

    // Copy old array to new one
    for(int i = 0; i < list->capacity; i++) {
        list->elems[i] = old_list[i];
    }

    // Set list capacity to new one
    list->capacity = new_capacity;

    // Free old memory
    free(old_list);
}

/* Delete the integer at the specified position in the list pointed
 * to by parameter list.
 * Parameter index is the position of the integer that should be removed.
 * Terminate the program via assert if list is NULL, or if index
 * is not in the range 0 .. list_size() - 1.

 */
void list_delete(list_t *list, int index)
{
    assert(list != NULL);

    // Have all elements move back one space after index
    list->size -= 1;
    for(int i = index; i < list->size; i++) {
        list->elems[i] = list->elems[i + 1];
    }
}
