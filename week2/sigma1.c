//////////////////////////////////////////////////////////////////////////////
//
// sigma0.c
//
// Sums a range of numbers recursively
//
//////////////////////////////////////////////////////////////////////////////

#include <cs50.h>
#include <stdio.h>

int sigma_recr(int m);

int main(void)
{
    int n;
    do
    {
        n = get_int("Positive integer: ");
    }
    while (n < 1);
    int answer = sigma_recr(n);
    printf("%i \n", answer);
}

int sigma_recr(int m)
{
    if (m <= 0)    // exit plan. Once m is 0, return 0 and stop recursing
    {
        return 0;
    }

    else
    {
        /* In effect, the following return statement says return `m` + the
           sum of everything below it.
           For ex when `m` = 3
           sigma(3) = return 3 +
           sigma(2) = return 2 +
           sigma(1) = return 1 +
           sigma(0) = return 0
        */
        return (m + sigma_recr(m - 1));
    }
}
