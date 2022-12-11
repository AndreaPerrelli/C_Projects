// Program to print the Fibonacci series using iteration

#include <stdio.h>

int main()
{
    // Initialize variables for the first two terms of the series
    int a = 0, b = 1;

    // Print the first two terms
    printf("%d %d ", a, b);

    // Iterate over the remaining terms of the series
    for (int i = 0; i < 10; i++)
    {
        // Calculate the next term in the series using the formula
        // f(n) = f(n-1) + f(n-2)
        int c = a + b;

        // Print the next term
        printf("%d ", c);

        // Shift the previous terms
        a = b;
        b = c;
    }

    return 0;
}
