/* polynomial.c - SYSC 2006 Winter 2019 Lab 6 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "polynomial.h"

/* Print a polynomial term in the form ax^n; for example,
 * a term with coefficient 4 and exponent 5 is printed as 4x^5.
 */
void print_term(term_t *term)
{
    printf("%dx^%d", term->coeff, term->exp);
}

/* Make a polynomial term with coefficient coeff and exponent exp
 * and return the pointer to the term.
 *
 * Memory for the term is allocated from the heap.
 * Terminate the program via assert if:
 * (1) coeff is 0;
 * (2) exp is negative;
 * (3) malloc fails.
 */
term_t *make_term(int coeff, int exp)
{
    term_t *term;
    term = malloc(sizeof(term_t));
    term->coeff = coeff;
    term->exp = exp;
    return term;
}

/* Return the value of a polynomial term; i.e., return ax^n for a term with
 * coefficient a and exponent n when evaluated at x.
 * Example: if a term has coefficient 3 and exponent 2 and x is 4.0,
 * this function returns 3(4.0^2), which is 48.0.
 */
double eval_term(term_t *term, double x)
{
    return term->coeff * pow(x, term->exp);
}

/* Make a polynomial that has 0 terms and return the pointer to the polynomial.
 * The polynomial can store up to MAX_TERMS terms (see polynomial.h).
 *
 * Memory for the polynomial is allocated from the heap.
 * Terminate the program via assert if malloc fails.
 */
polynomial_t *make_polynomial(void)
{
    polynomial_t *poly = malloc(sizeof(polynomial_t));
    assert(poly != NULL);
    return poly;
}

/* Add a term to a polynomial.
 *
 * This function doesn't check if the polynomial already contains a term with the
 * same exponent as the term being added; in other words, it's the caller's
 * reponsibility to ensure that the polynomial doesn't have terms with duplicate
 * exponents.
 *
 * Terminate the program via assert if there's no room in the polynomial for
 * additional terms.
 */
void add_term(polynomial_t *poly, term_t *term)
{
    poly->terms[poly->num_terms] = term;
    assert(poly->terms[poly->num_terms] != NULL);
    poly->num_terms++;
}

/* Return the value of a polynomial when it is evaluated at x.
 *
 * Terminate the program via assert if the polynomial has 0 terms.
 */
double eval_polynomial(polynomial_t *poly, double x)
{
    // Check for 0 terms first
    assert(poly->num_terms != 0);

    double value = 0;
    for(int i = 0; i < poly->num_terms; i++) {
        value += poly->terms[i]->coeff * pow(x, poly->terms[i]->exp);
    }
    return value;
}
