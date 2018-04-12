///////////////////////////////////////////////////////////////////////////////
//
//  Vigenere.c
//
//  1. accept single command-line argument, `k`, a string of only alpha chars
//  2. if command-line arg is omitted, print error message and return 1.
//  3. if more than one command-line argument is submitted, error and return 1.
//  4. if command-line arg contains not alpha chars, error and return 1.
//  5. prompt user for `p`, "plaintext: " (without newline), a string
//  6. encrypt according to Vigenère’s cipher with `k`
//     * non-alphabetical characters should be outputted unchanged.
//     * preserve case.
//  7. print "ciphertext: " (without newline) + corresponding ciphertext
//  8. output newline after ciphertext
//  9. return 0 from main
//
//  Tests:
//    encrypts "a" as "a" using "a" as keyword
//    encrypts "barfoo" as "caqgon" using "baz" as keyword
//    encrypts "BaRFoo" as "CaQGon" using "BaZ" as keyword
//    encrypts "BARFOO" as "CAQGON" using "BAZ" as keyword
//    encrypts "world!$?" as "xoqmd!$?" using "baz" as keyword
//    encrypts "hello, world!" as "iekmo, vprke!" using "baz" as keyword
//    handles lack of argv[1]
//    handles argc > 2
//    rejects "Hax0r2" as keyword
//
///////////////////////////////////////////////////////////////////////////////

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


bool isValidKey(string input_k);
int getOffset(char c);
void printCypher(string k, string str_in);


int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: %s <key>\n", argv[0]);
        return 1;
    }

    if (!isValidKey(argv[1]))
    {
        printf("Quitting: Command line argument <key> must consist of alpha characters\n");
        return 1;
    }

    string k = argv[1];

    // prompt user for input
    string str_in;
    do
    {
        str_in = get_string("plaintext: ");
    }
    while (strlen(str_in) < 1);

    printCypher(k, str_in);

    return 0;
}


/**
 * Validate key passed as command line argument
 * @param    {string}   key   Candidate key to check
 * @returns  {boolean}        True if 'key' consisted only of alpha chars
*/
bool isValidKey(string key)
{
    if (strlen(key) < 1)
    {
        return false;
    }
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}


/**
 * Get ascii -> 0-based numeric offset value
 * @param    {char}   c   Upper or lower case character
 * @returns  {int}        Numeric offset to apply to get 0-base
*/
int getOffset(char c)
{
    return isupper(c) ? 65 : 97;
}


/**
 * Print an enciphered string
 * @param   {string}   k        Cypher key
 * @param   {string}   str_in   Plaintext input string
*/
void printCypher(string k, string str_in)
{
    printf("ciphertext: ");

    // track key char iterations
    int k_counter = 0;

    // iterate over str_in, parsing plaintext chars to cyphertext chars
    for (int i = 0, n = strlen(str_in); i < n; i++)
    {
        // ignore non-alpha chars & do NOT increment k_counter
        if (!isalpha(str_in[i]))
        {
            printf("%c", str_in[i]);
        }
        // encypher alphas & incrment k_counter
        else
        {
            char k_char = k[k_counter % strlen(k)];            // get key char @ counter ind, mod k length
            int k_ascii = (int) k_char;                        // get ascii # of key char
            int p_ascii = (int) str_in[i];                     // get plaintext char ascii
            int p_offset = getOffset(str_in[i]);               // calc zero-index offset for plaintext
            int k_offset = getOffset(k_char);                  // calc zero-index offset for key char
            int p_zero = p_ascii - p_offset;                   // get zero-index char value
            int k_zero = k_ascii - k_offset;                   // get zero-index key value
            int c_ascii = ((p_zero + k_zero) % 26) + p_offset; // get cyphertext ascii char value
            char c_char = (char) c_ascii;                      // convert back to text char

            printf("%c", c_char);
            k_counter++;
        }
    }
    printf("\n");
}
