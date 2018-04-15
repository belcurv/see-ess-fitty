//////////////////////////////////////////////////////////////////////////////
//
// sigma0.c
//
// Sums a range of numbers iteratively
//
//////////////////////////////////////////////////////////////////////////////

#include <cs50.h>
#include <stdio.h>

int sigma_iter(int m);

int main(void)
{
    int n;
    do
    {
        n = get_int("Positive integer: ");
    }
    while (n < 1);
    int answer = sigma_iter(n);
    printf("%i \n", answer);
}

int sigma_iter(int m)
{
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum += i;
    }
    return sum;
}
