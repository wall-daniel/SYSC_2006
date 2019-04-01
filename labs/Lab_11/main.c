/* SYSC 2006 Winter 2019 Lab 11 - Test Harness. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "recursive_functions.h"

/*
 * Print then integers in array a in the form: {a[0] a[1] .. a[n-1]}.
 */
void print_array(int a[], int n)
{
    if (n < 0) {
        return;
    }

    if (n == 0) {
        printf("{}");
        return;
    }

    printf("{%d", a[0]);
    for (int i = 1; i < n; i += 1) {
        printf(" %d", a[i]);
    }
    printf("}");
}

/* Insert a new node containing data at the front of the linked list
 * pointed to by head. (If head is NULL, the linked list is empty.)
 * Return a pointer to the first node in the modified list.
 Terminate (via assert) if memory for the node cannot be allocated.
 */
node_t *push(node_t *head, int data)
{
    node_t *newnode = malloc(sizeof(node_t));
    assert(newnode != NULL);
    newnode->data = data;
    newnode->next = head;
    return newnode;
}

/* Print the linked list pointed to by head, using the format:
   value1 -> value2 -> value3 -> ... -> last_value
   Print NULL if the list is empty.
 */
void print_list(node_t *head)
{
    if (head == NULL) {
        printf("NULL");
        return;
    }

    node_t *curr;

    for (curr = head; curr->next != NULL; curr = curr->next) {
        printf("%d -> ", curr->data);
    }

    /* Print the last node. */
    printf("%d", curr->data);
}

/*------------------------------------------------------------------ */

/* Exercise the recursive power() function.
 * Display the values returned by C's pow() function and our
 * recursive power() function. If power() is correct, the two values
 * should be the same, or differ at most by a small amount.
 */
void test_power(double x, int k)
{
    printf("Calling power(x, k) with x = %.2f, k = %d\n", x, k);
    double expected = pow(x, k);
    printf("Expected result: %.2f, ", expected);
    double actual = power(x, k);
    printf("actual result: %.2f, ", actual);
    if (fabs(actual - expected) < 0.001) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_1(void)
{
    /* Test cases that allow us to verify if power() correctly calculates 
     * 3.5 ^ 0, 3.5 ^ 1, 3.5 ^ 2, 3.5 ^ 3 and 3.5 ^ 4.
     */
    printf("*** Exercise 1: Testing power ***\n");
    test_power(3.5, 0);
    test_power(3.5, 1);
    test_power(3.5, 2);
    test_power(3.5, 3);
    test_power(3.5, 4);
    printf("\n");
}

/* Exercise the recursive count function. 
 * Display the result we expect count() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter a is the array that will be passed to count().
 * Parameter n is the number of elements in the array.
 * Parameter target is the value that count() will search for.
 * Parameter expected is the result that a correct implementation of 
 * count() will return.
 */
void test_count(int a[], int n, int target, int expected)
{
    printf("Calling count with a = ");
    print_array(a, n);
    printf(", n = %d, target = %d\n", n, target);
    printf("Expected result: %d, ", expected);
    int actual = count(a, n, target);
    printf("actual result: %d, ", actual);
    if (expected == actual) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_2(void)
{
    printf("*** Exercise 2: Testing count ***\n");
    int x[] = { 1, 3, 3, 4, 4, 5, 4, 6 };
    int n = sizeof(x) / sizeof(n);

    /* Test case: count(x, n, 1) should return 1. */
    test_count(x, n, 1, 1);

    /* Test case: count(x, n, 2) should return 0. */
    test_count(x, n, 2, 0);

    /* Test case: count(x, n, 3) should return 2. */
    test_count(x, n, 3, 2);

    /* Test case: count(x, n, 4) should return 3. */
    test_count(x, n, 4, 3);

    /* Test case: count(x, n, 5) should return 1. */
    test_count(x, n, 5, 1);

    /* Test case: count(x, n, 6) should return 1. */
    test_count(x, n, 6, 1);
    printf("\n");
}

/* Exercise the recursive occurrences function. 
 * Display the result we expect occurrences() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter head is the list that will be passed to occurrences().
 * Parameter target is the value that occurrences() will search for.
 * Parameter expected is the result that a correct implementation of 
 * occurrences() will return.
 */
void test_occurrences(node_t *head, int target, int expected)
{
    printf("Calling occurrences with list = ");
    print_list(head);
    printf(", target = %d\n", target);
    printf("Expected result: %d, ", expected);
    int actual = occurrences(head, target);
    printf("actual result: %d, ", actual);
    if (expected == actual) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_3(void)
{
    printf("*** Exercise 3: Testing occurrences ***\n");

    // Build the linked list {1, 3, 3, 4, 4, 5, 4, 6}
    node_t *list = push(NULL, 6);
    list = push(list, 4);
    list = push(list, 5);
    list = push(list, 4);
    list = push(list, 4);
    list = push(list, 3);
    list = push(list, 3);
    list = push(list, 1);

    /* Test case: occurrences(list, 1) should return 1. */
    test_occurrences(list, 1, 1);

    /* Test case: occurrences(list, 2) should return 0. */
    test_occurrences(list, 2, 0);

    /* Test case: occurrences(list, 3) should return 2. */
    test_occurrences(list, 3, 2);

    /* Test case: occurrences(list, 4) should return 3. */
    test_occurrences(list, 4, 3);

    /* Test case: occurrences(list, 5) should return 1. */
    test_occurrences(list, 5, 1);

    /* Test case: occurrences(list, 6) should return 1. */
    test_occurrences(list, 6, 1);
    printf("\n");
}

/* Exercise the recursive last function. 
 * Display the result we expect last() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter head is the list that will be passed to last().
 * Parameter expected is the result that a correct implementation of 
 * last() will return.
 */
void test_last(node_t *head, int expected)
{
    printf("Calling last with list = ");
    print_list(head);
    printf("\nExpected result: %d, ", expected);
    int actual = last(head);
    printf("actual result: %d, ", actual);
    if (expected == actual) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_4(void)
{
    printf("*** Exercise 4: Testing last ***\n");

    // Build the linked list {1}
    node_t *list = push(NULL, 1);

    /* Test case: last(list) should return 1. */
    test_last(list, 1);

    // Build the linked list {1, 2}
    list = push(push(NULL, 2), 1);

    /* Test case: last(list) should return 2. */
    test_last(list, 2);

    // Build the linked list {1, 2, 4, 4}
    list = push(push(push(push(NULL, 4), 4), 2), 1);

    /* Test case: last(list) should return 4. */
    test_last(list, 4);

    // Build the linked list {1, 2, 4, 4, 5}
    list = push(push(push(push(push(NULL, 5), 4), 4), 2), 1);

    /* Test case: last(list) should return 5. */
    test_last(list, 5);

    printf("\n");
}

/* Extra-practice exercises. */

/* Exercise the recursive num_digits() function. 
 * Display the result we expect num_digits() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter k is the argument that will be passed to num_digits().
 * Parameter expected is the result that a correct implementation of 
 * num_digits() will return.
 */
void test_num_digits(int k, int expected)
{
    printf("Calling num_digits(k) with k = %d\n", k);
    printf("Expected result: %d, ", expected);
    int actual = num_digits(k);
    printf("actual result: %d, ", actual);
    if (expected == actual) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_5(void)
{
    printf("*** Exercise 5: Testing num_digits ***\n");
    /* Test case: num_digits(5) should return 1. */
    test_num_digits(5, 1);

    /* Test case: num_digits(9) should return 1. */
    test_num_digits(9, 1);

    /* Test case: num_digits(10) should return 2. */
    test_num_digits(10, 2);

    /* Test case: num_digits(99) should return 2. */
    test_num_digits(99, 2);

    /* Test case: num_digits(100) should return 3. */
    test_num_digits(100, 3);

    /* Test case: num_digits(999) should return 3. */
    test_num_digits(999, 3);

    /* Test case: num_digits(1000) should return 4. */
    test_num_digits(1000, 4);
    printf("\n");
}

/* Exercise the recursive power2() function.
 * Display the values returned by C's pow() function and our
 * recursive power2() function. If power2() is correct, the two values
 * should be the same, or differ at most by a small amount.
 */
void test_power2(double x, int k)
{
    printf("Calling power2(x, k) with x = %.2f, k = %d\n", x, k);
    double expected = pow(x, k);
    printf("Expected result: %.2f, ", expected);
    double actual = power2(x, k);
    printf("actual result: %.2f, ", actual);
    if (fabs(actual - expected) < 0.001) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_6(void)
{
    /* Test cases that allow us to verify if power2() correctly calculates 
     * 3.5 ^ 0, 3.5 ^ 1, 3.5 ^ 2, 3.5 ^ 3 and 3.5 ^ 4.
     */
    printf("*** Exercise 6: Testing power2 ***\n");
    test_power2(3.5, 0);
    test_power2(3.5, 1);
    test_power2(3.5, 2);
    test_power2(3.5, 3);
    test_power2(3.5, 4);
    printf("\n");
}

int main(void)
{
    printf("SYSC 2006 Winter 2019 Lab 11 Test Harness\n\n");

    test_exercise_1();
    test_exercise_2();
    test_exercise_3();
    test_exercise_4();

    printf("Testing solutions to extra-practice exercises.\n\n");

    test_exercise_5();
    test_exercise_6();
    return EXIT_SUCCESS;
}
