///////////////////////////////////////////////////////////////////////////////
//
// Per CS50x spec:
//   Program that asks the user how much change is owed and prints the minimum
//   number of coins with which said change can be made.
//
// 1. use get_float from CS50 library
// 2. assume only available coins: quarters, dimes, nickels, pennies
// 3. assume float values with decimal points, no $ signs.
// 4. get_float ensures value is a float but not that it is non-negative
// 5. continually prompt for input if invalid input
// 6. output should be integer followed by \n
//
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>
#include <cs50.h>


// init global variables
// coins normalized to pennies
int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;


// declare functions
bool validChange(float c);


// main program
int main(void)
{
    // init locally scoped variables
    float input;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    // await valid user input
    do
    {
        input = get_float("Change owed: ");
    }
    while (!validChange(input));

    // convert float to int to avoid numeric imprecision
    int change = roundf(input * 100);

    while (change > 0)
    {
        if (change >= quarter)
        {
            while (change / quarter >= 1)
            {
                quarters++;
                change -= quarter;
            }
        }
        else if (change >= dime)
        {
            while (change / dime >= 1)
            {
                dimes++;
                change -= dime;
            }
        }
        else if (change >= nickel)
        {
            while (change / nickel >= 1)
            {
                nickels++;
                change -= nickel;
            }
        }
        else
        {
            while (change / penny >= 1)
            {
                pennies++;
                change -= penny;
            }
        }

    }

    // report!
    printf("Quarters: %i\n", quarters);
    printf("Dimes: %i\n", dimes);
    printf("Nickels: %i\n", nickels);
    printf("Pennies: %i\n", pennies);

    printf("======================\n");
    printf("Total number of coins:\n");
    printf("%i\n", quarters + dimes + nickels + pennies);

}


// is input valid
bool validChange(float c)
{
    return c >= 0.00;
}
