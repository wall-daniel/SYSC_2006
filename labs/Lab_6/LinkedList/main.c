#include <stdio.h>
#include <stdlib.h>


typedef struct item {
    struct item *next, *before;
    int value = 0;
} item_t;

typedef struct stack {
    item_t *top, *bottom;
    int size = 0;
} stack_t;

*item_t push(stack_t *s, int value) {
    item_t *i = malloc(sizeof(item_t));
    i->value = value;

    i->next = s->top;
    s->top = i->next;

    return i;
}

*item pop(stack_t *s) {
    item_t *i = s->bottom;
    s->bottom = i->before;
    return s->bottom;
}

int main()
{
    stack_t s;

    return 0;
}
