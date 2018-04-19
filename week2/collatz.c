///////////////////////////////////////////////////////////////////////////////
//
// collatz.c
//
// Recusive function that calculates how many steps it takes to get to 1 if
// you start from `n` and recurse as indicated below.
//
// The Collatz Conjecture applies to positive integers and speculates that it
// is always possible to get back to 1 if you follow these steps:
//   1. If n is 1, stop.
//   2. Otherwise, if n is even, repeat this process on n/2
//   3. Otherwise, if n is odd, repeat this process on 3n + 1
//
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <cs50.h>

int collatz(int n);


int main(void)
{
    int n = get_int("Gimme integer: ");
    printf("%i \n", collatz(n));
}


/**
 * Counts steps needed to "get back to" 1 from n
 * @param    {int}   n   Starting value
 * @returns  {int}       Number of steps needed
*/
int collatz(int n)
{
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        return 1 + collatz(n / 2);
    else
        return 1 + collatz(3 * n + 1);
}
