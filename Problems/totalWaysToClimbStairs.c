#include <stdio.h>

// Recursive function to find total ways to reach the n'th stair from bottom
// when a person is allowed to take at-most m steps at a time
int totalWays(int n, int m)
{
	// base case: invalid input
	if (n < 0)
		return 0;

	// base case: 1 way (with no steps)
	if (n == 0)
		return 1;

	int count = 0;
	for (int i = 1; i <= m; i++)
		count += totalWays(n - i, m);

	return count;
}

// main function
int main(void)
{
	int n = 10, m = 5;

	printf("Total ways to reach the %d'th stair with at-most %d steps are %d",
			n, m, totalWays(n, m));

	return 0;
}