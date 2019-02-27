/* polynomial.h - SYSC 2006 Winter 2019 Lab 6 */

typedef struct {
    int coeff;   // a term's coefficient
    int exp;     // a term's exponent
} term_t;

/* A polynomial consists of between 1 and MAX_TERMS terms. 
   Pointers to the terms are stored in array terms.
   num_terms keeps track of the number of terms in the polynomial.
 */

#define MAX_TERMS 10

typedef struct {
    term_t *terms[MAX_TERMS];
    int num_terms;
} polynomial_t;

term_t *make_term(int coeff, int exp);
void print_term(term_t *term);
double eval_term(term_t *term, double x);

polynomial_t *make_polynomial(void);
void add_term(polynomial_t *poly, term_t *term);
double eval_polynomial(polynomial_t *poly, double x);
