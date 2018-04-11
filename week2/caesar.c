///////////////////////////////////////////////////////////////////////////////
//
//  Caesar.c
//
//  1. accept a single command-line argument, `k`, a non-negative integer.
//  2. if command-line arg is omitted, print error message and return 1.
//  3. can assume user-provided command-line argument will be a non-negative
//     integer (e.g., 1). No need to check that it’s numeric.
//  4. Do not assume k <= 26. Your program should work for all non-negative
//     integral values of k less than 2^31 - 26
//  5. output:
//     a) "plaintext: " (without newline) & prompt user for a string
//     b) "ciphertext: " (without newline) + corresponding ciphertext
//  6. non-alphabetical characters should be outputted unchanged.
//  7. preserve case
//  8. output newline after ciphertext
//  9. return 0 from main
//
//  Tests:
//    encrypts "a" as "b" using 1 as key
//    encrypts "barfoo" as "yxocll" using 23 as key
//    encrypts "BARFOO" as "EDUIRR" using 3 as key
//    encrypts "BaRFoo" as "FeVJss" using 4 as key
//    encrypts "barfoo" as "onesbb" using 65 as key
//    encrypts "world, say hello!" as "iadxp, emk tqxxa!" using 12 as key
//    handles lack of argv[1]
//
///////////////////////////////////////////////////////////////////////////////

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


bool validInput(string str_in);
void printCypher(int key, string str);


int main(int argc, string argv[])
{
    // bail early if invalid command line args
    if (argc < 2)
    {
        printf("Usage: %s <key>\n", argv[0]);
        return 1;
    }

    // convert CLI argv[1] to long int, and mod 26 it to restrict to English alphabet
    char *endptr;
    long int input_k = strtol(argv[1], &endptr, 10);
    int mod_k = input_k % 26;

    // prompt user for input
    string str_in;
    do
    {
        str_in = get_string("plaintext: ");
    }
    while (!validInput(str_in));

    printCypher(mod_k, str_in);

    return 0;
}


/**
 * Check input validity
 * @param    {string}   str_in   Candidate string to check
 * @return   {bool}              True if string has length
*/
bool validInput(string str_in)
{
    return strlen(str_in) > 0;
}


/**
 * Print an enciphered string
 * @param    {int}      key      Cypher key
 * @param    {string}   str_in   Plaintext input string
*/
void printCypher(int key, string str_in)
{
    printf("ciphertext: ");

    // iterate over str_in, parsing plaintext chars to cyphertext chars
    for (int i = 0, n = strlen(str_in); i < n; i++)
    {
        // ignore non-alpha chars
        if (!isalpha(str_in[i]))
        {
            printf("%c", str_in[i]);
        }
        // parse alpha chars
        else
        {
            int p_ascii = (int) str_in[i];                  // get plaintext char ascii
            int offset = isupper(str_in[i]) ? 65 : 97;      // calc zero-index offset from isupper?
            int p_zero = p_ascii - offset;                  // set zero-index char value
            int c_ascii = ((p_zero + key) % 26) + offset;   // set cyphertext ascii char value
            char c_char = (char) c_ascii;                   // convert to character
            printf("%c", c_char);                           // output
        }
    }

    printf("\n");
}
