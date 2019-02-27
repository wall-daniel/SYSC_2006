/* main.c - SYSC 2006 Winter 2019 Lab 6 Test Harness 
 *
 * Do not modify any of the code in this file.
 */

#include <stdlib.h>  // exit, malloc, free
#include <stdio.h>   // printf
#include <math.h>    // pow
#include "sput.h"

#include "polynomial.h"

/* By default, Pelles C generates "warning #2154: Unreachable code"
   and "warning #2130: Result of comparison is constant" when the 
   macros in sput.h are used. The following pragma directive disables the
   generation of these warnings.
 */
#pragma warn(disable: 2130 2154)

static void _print(term_t term)
{
    printf("%dx^%d", term.coeff, term.exp);
}

static void test_print_term(void)
{
	term_t term;

	term = (term_t) {3, 2};
	printf("Expected output: ");
    _print(term);
    printf("\n");
    printf("Actual output:   ");
	print_term(&term);
	printf("\n\n");

	term = (term_t) {-3, 2};
	printf("Expected output: ");
    _print(term);
    printf("\n");
    printf("Actual output:   ");
	print_term(&term);
	printf("\n");
}

static void test_make_term(void)
{
    term_t expected;
    term_t *actual;

    // Test make_term(3, 2)

    expected = (term_t) {3, 2};
    actual = make_term(3, 2);

    sput_fail_unless(actual != NULL && 
                     actual->coeff == expected.coeff && 
                     actual->exp == expected.exp,
                     "term_t *actual = make_term(3, 2)");

    printf("Expected result: ");
	_print(expected);
    printf(", actual result: ");
    if (actual == NULL) {
        printf("make_term returned NULL\n");  // Check make_term: no assert after malloc,
                                              // or a bug (function returns NULL instead
                                              // of the pointer to the malloc'd term. 
    } else {
        _print(*actual);
        printf("\n");
    }


    // Test make_term(-3, 2)

    expected = (term_t) {-3, 2};
    actual = make_term(-3, 2);

    sput_fail_unless(actual != NULL && 
                     actual->coeff == expected.coeff && 
                     actual->exp == expected.exp,
                     "term_t *actual = make_term(-3, 2)");

    printf("Expected result: ");
	_print(expected);
    printf(", actual result: ");
    if (actual == NULL) {
        printf("make_term returned NULL\n");
    } else {
        _print(*actual);
        printf("\n");
    }
}

static void test_eval_term(void)
{
    term_t *term;
    double expected;
    double actual;

    // Test evaluation of 3x^2 when x = 4.0.

    term = make_term(3, 2);
    expected = 48.0;
    actual = eval_term(term, 4.0);

    sput_fail_unless(fabs(actual - expected) < 0.001,
                     "term_t *term = make_term(3, 2); actual = eval_term(term, 4.0);");  
    
    printf("Expected result: %.1f", expected);
    printf(", actual result: %.1f\n", actual);

    // Test evaluation of -3x^2 when x = 4.0.

    term = make_term(-3, 2);
    _print(*term);
    expected = -48.0;
    actual = eval_term(term, 4.0);

    sput_fail_unless(fabs(actual - expected) < 0.001,
                     "term_t *term = make_term(-3, 2); actual = eval_term(term, 4.0);"); 

    printf("Expected result: %.1f", expected);
    printf(", actual result: %.1f\n", actual);

    // Test evaluation of 3x^2 when x = -4.0.

    term = make_term(3, 2);
    _print(*term);
    expected = 48.0;
    actual = eval_term(term, -4.0);

    sput_fail_unless(fabs(actual - expected) < 0.001,
                     "term_t *term = make_term(3, 2); actual = eval_term(term, -4.0);"); 
 
    printf("Expected result: %.1f", expected);
    printf(", actual result: %.1f\n", actual);

    // Test evaluation of -3x^2 when x = -4.0.

    term = make_term(-3, 2);
    _print(*term);
    expected = -48.0;
    actual = eval_term(term, -4.0);

    sput_fail_unless(fabs(actual - expected) < 0.001,
                     "term_t *term = make_term(-3, 2); actual = eval_term(term, -4.0);");  
    
    printf("Expected result: %.1f", expected);
    printf(", actual result: %.1f\n", actual); 
}

static void test_make_polynomial(void)
{
    polynomial_t expected;
    expected.num_terms = 0;
    polynomial_t *actual = make_polynomial();

    sput_fail_unless(actual != NULL && 
                     actual->num_terms == expected.num_terms,
                     "polynomial_t *actual = make_polynomial()");

    printf("Expected result: empty polynomial with %d terms\n", expected.num_terms);
    printf("Actual result: ");
    if (actual == NULL) {  	
        printf("make_polynomial returned NULL\n"); 
        // Check make_polynomial: no assert after 
        // malloc, or a bug (function returns NULL
        // instead of the pointer to the malloc'd term.
    } else {
        printf("empty polynomial with %d terms\n", actual->num_terms);
    }
}

static void test_add_term(void)
{
    term_t term1 = (term_t) {2, 3};
    term_t term2 = (term_t) {-1, 4};

    polynomial_t *poly = make_polynomial();
    term_t *term_3 = make_term(2, 3);
    add_term(poly, term_3);

    sput_fail_unless(poly->num_terms == 1 &&
                     poly->terms[0] == term_3 &&
                     poly->terms[0]->coeff == term1.coeff &&
                     poly->terms[0]->exp == term1.exp,
                     "polynomial_t *poly = make_polynomial();"
                     " add_term(poly, make_term(2, 3));");

    printf("Expected result: poly->num_terms == 1\n");
    printf("Expected result: poly->terms[0] points to: ");
    _print(term1);
    printf("\n");

    printf("Actual result: poly->num_terms == %d\n", poly->num_terms);

    if (poly->terms[0] != term_3) {  	
        printf("Actual result: poly->terms[0] doesn't point to the first term\n"); 
    } else {
        printf("Actual result: poly->terms[0] points to: ");
        _print(*poly->terms[0]);
        printf("\n");
    }

    /* Add the second term only if the first one was added successfully. */
    if (__sput.suite.nok == 0) {
        term_t *term_4 = make_term(-1, 4);
        add_term(poly, term_4);

        sput_fail_unless(poly->num_terms == 2 && 
                         poly->terms[0] == term_3 &&
                         poly->terms[1] == term_4 &&
                         poly->terms[0]->coeff == term1.coeff &&
                         poly->terms[0]->exp == term1.exp &&
                         poly->terms[1]->coeff == term2.coeff &&
                         poly->terms[1]->exp == term2.exp,
                         "add_term(poly, make_term(-1, 4));");

        printf("Expected result: poly->num_terms == 2\n");
        printf("Expected result: poly->terms[0] points to: ");
        _print(term1);
        printf("\n");
        printf("Expected result: poly->terms[1] points to: ");
        _print(term2);
        printf("\n");

        printf("Actual result: poly->num_terms == %d\n", poly->num_terms);

        if (poly->terms[0] != term_3) {  	
            printf("Actual result: poly->terms[0] doesn't point to the first term\n"); 
        } else {
            printf("Actual result: poly->terms[0] points to: ");
            _print(*poly->terms[0]);
            printf("\n");
        }

        if (poly->terms[1] != term_4) {  	
            printf("Actual result: poly->terms[1] doesn't point to the second term\n"); 
        } else {
            printf("Actual result: poly->terms[1] points to: ");
            _print(*poly->terms[1]);
            printf("\n");
        }
    }
}

static void test_eval_polynomial(void)
{
    double expected;
    double actual;

    polynomial_t *poly = make_polynomial();
    add_term(poly, make_term(3, 2));
    expected = 12.0;
    actual = eval_polynomial(poly, 2.0);

    sput_fail_unless(fabs(actual - expected) < 0.001,
                     "Evaluate 3x^2 when x = 2.0");

    printf("Expected result: %.1f", expected);
    printf(", actual result: %.1f\n", actual);    
    
    add_term(poly, make_term(4, 1));
    expected = 20.0;
    actual = eval_polynomial(poly, 2.0);

    sput_fail_unless(fabs(actual - expected) < 0.001,
                     "Evaluate 3x^2 + 4x when x = 2.0");

    printf("Expected result: %.1f", expected);
    printf(", actual result: %.1f\n", actual); 

    add_term(poly, make_term(5, 0));
    expected = 25.0;
    actual = eval_polynomial(poly, 2.0);

    sput_fail_unless(fabs(actual - expected) < 0.001,
                     "Evaluate 3x^2 + 4x + 5 when x = 2.0");

    printf("Expected result: %.1f", expected);
    printf(", actual result: %.1f\n", actual); 
}

int main(void)
{
    printf("Running test harness for SYSC 2006 Winter 2019 Lab 6\n");

    sput_start_testing();

    sput_enter_suite("Exercise 1: print_term()");
    sput_run_test(test_print_term);

    sput_enter_suite("Exercise 2: make_term()");
    sput_run_test(test_make_term);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for remaining exercises won't be run until make_term "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 3: eval_term()");
    sput_run_test(test_eval_term);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for remaining exercises won't be run until eval_term "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 4: make_polynomial()");
    sput_run_test(test_make_polynomial);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for remaining exercises won't be run until make_polynomial "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 5: add_term()");
    sput_run_test(test_add_term);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for remaining exercises won't be run until add_term "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 6: eval_polynomial()");
    sput_run_test(test_eval_polynomial);
    sput_leave_suite();

    sput_finish_testing();
    return sput_get_return_value();
}
