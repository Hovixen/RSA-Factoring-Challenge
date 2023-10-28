#include "main.h"

/**
 * commonDivisor - function computes greatest common divisor(GCD) of integers
 * @a: integer a
 * @b: integer b
 * Return: returns the GCD of two integers
 */

int commonDivisor(int a, int b)
{
	if (b == 0)
		return (a);
	return (commonDivisor(b, a % b));
}

/**
 * defactor - function factorizes a number using polland roh's algorithm
 * @n: integer argument
 * Return: returns the factorized number
 */

int defactor(int n)
{
	int a, b, c, d;

	if (n <= 1)
		return (0);
	if (n % 2 == 0)
		return (2);
	a = rand() % (n - 1) + 1;
	b = a;
	c = rand() % (n - 1) + 1;
	d = 1;
	while (d == 1)
	{
		a = (a * a + c) % n;
		b = (b * b + c) % n;
		b = (b * b + c) % n;
		d = commonDivisor(abs(a - b), n);
	}
	if (d == n)
		return (0);
	return (d);
}
