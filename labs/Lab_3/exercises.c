/* SYSC 2006 Winter 2019 Lab 3.

 * Incomplete implementations of the functions that will be coded during the lab.
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "exercises.h"

/* Exercise 1. */

/* Return the average magnitude of the signal represented by
 * the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_magnitude(double x[], double n)
{
    double sum = 0.0;
    for(int i = 0; i < n; i++)
    {
        sum += fabs(x[i]);
    }

    return sum / n;
}

/* Exercise 2. */

/* Return the average power of the signal represented by
 * the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_power(double x[], double n)
{
    double sum = 0.0;
    for(int i = 0; i < n; i++)
    {
        sum += x[i] * x[i];
    }

    return sum / n;
}

/* Exercise 3. */

/* Return the largest of the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double max(double arr[], int n)
{
    double max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    return max;
}

/* Exercise 4. */

/* Return the smallest of the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double min(double arr[], int n)
{
    double min = arr[0];
    for(int i = 1; i < n; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }

    return min;
}

/* Exercise 5. */

/* Normalize the n doubles in x[].
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in x[] are different.
 */
void normalize(double x[], int n)
{
    double maximum = max(x, n);
    double minimum = min(x, n);

    for(int i = 0; i < n; i++)
    {
        x[i] = (x[i] - minimum) / (maximum - minimum);
    }
}
