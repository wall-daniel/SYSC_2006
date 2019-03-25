/* SYSC 2006 Winter 2019 Lab 8
 *
 * array_list.h 
 *
 * Header file for a prototype of a dynamically allocated, fixed-capacity 
 * list that supports a subset of the operations provided by Python's 
 * list class.
 */ 

#include <stdbool.h>

typedef struct {
    int     *elems;    // Pointer to backing array.
    int     capacity;  // Maximum number of elements in the list.
    int     size; 	   // Current number of elements in the list.
} list_t;

list_t  *list_construct(int capacity);
void    list_destroy(list_t *list);

int     list_size(const list_t *list);
int     list_capacity(const list_t *list);

_Bool   list_append(list_t *list, int element);
int     list_get(const list_t *list, int index);
int     list_set(list_t *list, int index, int element);
void    list_removeall(list_t *list);

void    list_print(const list_t *list);

/* Additional functions for Lab 8. */

int list_index(const list_t *list, int target);
int list_count(const list_t *list, int target);
_Bool list_contains(const list_t *list, int target);
void increase_capacity(list_t *list, int new_capacity);

void list_delete(list_t *list, int index);



