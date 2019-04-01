/* SYSC 2006 Winter 2019 Lab 11. */

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "recursive_functions.h"

/* Return x raised to the power n for n >= 0. */
double power(double x, int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return x;

    return x * power(x, n - 1);
}

/* Return the count of the number of times target occurs in the first
 * n elements of array a.
 */
int count(int a[], int n, int target)
{
    if(n == 0) {
        if(a[n] == target)
            return 1;
        else
            return 0;
    } else {
        if(a[n] == target)
            return 1 + count(a, n - 1, target);
        else
            return count(a, n - 1, target);
    }
}

/* Return the count of the number of times target occurs in the
 * linked list pointed to by head.
 */
int occurrences(node_t *head, int target)
{
    if(head->next == NULL) {
        if(head->data == target)
            return 1;
        else
            return 0;
    } else {
        if(head->data == target)
            return 1 + occurrences(head->next, target);
        else
            return occurrences(head->next, target);
    }
}

/* Return the last element in the linked list pointed to by head.
 * Terminate (via assert) if the list is empty.
 */
int last(node_t *head)
{
    if(head->next != NULL)
        return last(head->next);

    return head->data;
}

/* Extra-practice exercises. */

/* Return the number of digits in integer n, n >= 0. */
int num_digits(int n)
{
    if(n < 10)
        return 1;
    return 1 + num_digits(n / 10);
}

/* Return x raised to the power n for n >= 0. */
double power2(double x, int n)
{
    if(n == 0)
        return 1.0;
    if(n % 2 == 0)
        return power2(x, n/2) * power2(x, n/2);

    return x * power2(x, n/2) * power2(x, n/2);
}
