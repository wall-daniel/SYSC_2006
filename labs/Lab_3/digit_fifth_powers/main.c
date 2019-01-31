d#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long DigitPowers(long n)
{
	long sum = 0;
	while(n > 0)
	{
		sum += pow(n % 10, 5);
		n /= 10;
		//printf("%i^4 ", n % 10);
	}
	return sum;
}

int main(void)
{
	long sum = 0;

	for(long i = 2; i < 5000000; i++)
	{
		if(DigitPowers(i) == i)
		{
			sum += i;
			printf("%i\n", i);
		}
	}

	printf("Sum is: %ld\n", sum);

	return EXIT_SUCCESS;
}
