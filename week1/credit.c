///////////////////////////////////////////////////////////////////////////////
//
// Per CS50x spec:
//   Program reports whether user-supplied CC number is a valid American
//   Express, MasterCard, or Visa card number.
//
// 1. Assume user input will be entirely numeric (devoid of hyphens
// 2. Do not assume that user input will fit in an int! Best to use
//    get_long_long from CS50’s library to get users' input. (Why?)
// 3. Card specifics:
//    All use decimal numbers (0-9)
//      American Express
//        * 15-digit numbers
//        * start with 34 or 37
//      MasterCard
//        * 16-digit numbers
//        * start with 51, 52, 53, 54, or 55
//      Visa
//        * 13- and 16-digit numbers
//        * start with 4
// 4. All use Luhn's algorithm for syntactic card number validation
//    * multiple every other digit by 2, starting with the number's 2nd-to-last
//      digit, and then add those products' digits together
//    * add the sum to the sum of the digits that weren't multiplied by 2
//    * if the total's last digit is 0, the number is valid (total % 10 = 0)
// 6. last line of output should be AMEX\n or MASTERCARD\n or VISA\n
//    or INVALID\n
//
// TESTS
// identifies 378282246310005 as AMEX
// identifies 371449635398431 as AMEX
// identifies 5555555555554444 as MASTERCARD
// identifies 5105105105105100 as MASTERCARD
// identifies 4111111111111111 as VISA
// identifies 4012888888881881 as VISA
// identifies 1234567890 as INVALID
// identifies 369421438430814 as INVALID
// identifies 4062901840 as INVALID
// identifies 5673598276138003 as INVALID
// identifies 4111111111111113 as INVALID
//
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <cs50.h>


// declare function protos
bool validInput(long long int input);
int countDigits(long long int number);
int getDigitByIndex(int digit, long long int ccNum, int nDigits);
int getCheckSum(long long int ccNum);


int main(void)
{

    // init local variables
    int nDigits = 0;
    long long int ccNum;

    // get input
    do
    {
        ccNum = get_long_long("Input CC Number: ");
    }
    while (!validInput(ccNum));

    // get CC num length & bail early if invalid
    nDigits = countDigits(ccNum);
    if (!(nDigits == 13 || nDigits == 15 || nDigits == 16))
    {
        printf("INVALID\n");
        return 0;
    }

    // capture 1st and 2nd digits
    int dig1 = getDigitByIndex(1, ccNum, nDigits);
    int dig2 = getDigitByIndex(2, ccNum, nDigits);

    // AMEX = 15 digits, starts with 34 or 37
    if (nDigits == 15 && dig1 == 3 && (dig2 == 4 || dig2 == 7))
    {
        if (getCheckSum(ccNum) == 0)
        {
            printf("AMEX\n");
            return 0;
        }
    }

    // VISA = 13 or 16-digit number, starts with 4
    else if ((nDigits == 13 || nDigits == 16) && dig1 == 4)
    {
        if (getCheckSum(ccNum) == 0)
        {
            printf("VISA\n");
            return 0;
        }
    }

    // MasterCard = 16-digit number, starts with 51, 52, 53, 54, or 55
    else if (nDigits == 16 && dig1 == 5 && dig2 >= 1 && dig2 <= 5)
    {
        if (getCheckSum(ccNum) == 0)
        {
            printf("MASTERCARD\n");
            return 0;
        }
    }

    printf("INVALID\n");

}


/**
 * Check for valid input value
 * @param    {long long int}   input   Candidate input
 * @returns  {boolean}                 True if non-negative number
*/
bool validInput(long long int input)
{
    return input > 0;
}


/**
 * Count number of digits in a number
 * @param    {long long int}  number   Candidate number to check
 * @returns  {int}                     Number of digits
*/
int countDigits(long long int number)
{
    int nDigits = 0;
    while (number != 0)
    {
        number /= 10;
        nDigits++;
    }
    return nDigits;
}


/**
 * Get specified digit, indexed from '1' starting from left
 * @param    {long long int}  ccNum     Candidate CC number
 * @param    {int}            digit     One-based index of desired digit
 * @param    {int}            nDigits   Number of digits in CC number
 * @returns  {int}                      First digit of CC number
*/
int getDigitByIndex(int digit, long long int ccNum, int nDigits)
{
    long d = 1;
    for (int i = 0; i < nDigits - digit; i++)
    {
        d *= 10;
    }
    return ccNum / d % 10;
}


/**
 * Calculate checksum
 * @param    {long long int}  ccNum   Candidate CC number
 * @returns  {int}                    The last digit in the checksum value
*/
int getCheckSum(long long int ccNum)
{
    int tick = 0;
    int count = countDigits(ccNum);  // 13, 15, 16
    long int sumSeries1 = 0;
    long int sumSeries2 = 0;
    for (int i = count; i > 0; i--)
    {
        if (tick % 2 == 0)
        {
            sumSeries2 += getDigitByIndex(i, ccNum, count);
        }
        else
        {
            int product = getDigitByIndex(i, ccNum, count) * 2;
            int prodDigits = countDigits(product);
            if (prodDigits > 1)
            {
                for (int j = 0; j < prodDigits; j++)
                {
                    sumSeries1 += getDigitByIndex(j + 1, product, prodDigits);
                }
            }
            else
            {
                sumSeries1 += product;
            }
        }
        tick++;
    }
    int sumLength = countDigits(sumSeries1 + sumSeries2);
    int lastDigit = getDigitByIndex(sumLength, sumSeries1 + sumSeries2, sumLength);

    return lastDigit;
}
