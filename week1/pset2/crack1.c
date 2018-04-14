///////////////////////////////////////////////////////////////////////////////
//
//  crack1.c -- a simple password hash cracker
//
//  This version will be faster for shorter passwords.
//  Refactored looping logic. This version tries all 1 character combos, then
//  all 2 char combos, then all 3 char combos, etc.
//
//  Spec per: https://docs.cs50.net/2018/x/psets/2/crack/crack.html
//  1. accept a single command-line argument: a hashed password.
//  2. if command-line arg is omitted, print error message and return 1.
//  3. crack given password, printing it in the clear, followed by \n
//     Assumptions:
//     1. passwords are hashed with C’s DES-based `crypt` function
//     2. passwords are between 1 and 5 characters
//     3. passwords are only upper and/or lowercase alphabetical characters
//  4. return 0 from `main`
//
//  http://www.gnu.org/software/libc/manual/html_node/crypt.html
//
//  Tests:
//    anushree:50xcIMJ0y.RXo  YES   (took 67878 tries)
//    brian:50mjprEcqC/ts     CA    (took 156 tries)
//    bjbrown:50GApilQSG3E2   UPenn (took 155879607 tries)
//    lloyd:50n0AAUD.pL8g     lloyd (took 283298057 tries)
//    malan:50CcfIk1QrPr6     maybe (took 289088830 tries)
//    maria:509nVI8B9VfuA     TF    (took 1045 tries)
//    natmelo:50JIIyhDORqMU   nope  (took 5737398 tries)
//    rob:50JGnXUgaafgc       ROFL  (took 2571827 tries)
//    stelios:51u8F0dkeDSbY   NO    (took 742 tries)
//    zamyla:50cI2vYkF0YU2    LOL   (took 33239 tries)
//
///////////////////////////////////////////////////////////////////////////////

#define _XOPEN_SOURCE

#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// declare function prototypes

bool isValidHash(string hash);
char *makeAlphabet(void);


int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <hash>\n", argv[0]);
        return 1;
    }

    if (!isValidHash(argv[1]))
    {
        printf("Quitting: Invalid command line argument <hash>\n");
        return 1;
    }

    string hash = argv[1];
    char salt[3] = { argv[1][0], argv[1][1], '\0' };

    string alphabet = makeAlphabet();
    int abet_len = strlen(alphabet);

    long int n_iters = 0;    // count number of iterations
    char key[6] = { '\0' };  // initialize array w/null terminator


    // test single characters
    for (int a = 0; a < abet_len; a++)
    {
        printf("\nRound %2i | %c ", a, alphabet[a]);
        key[0] = alphabet[a];
        key[1] = '\0';

        if (strcmp(crypt(key, salt), hash) == 0)
        {
            printf("\nMatch! %s (took %li tries)\n", key, n_iters);
            return 0;
        }

        n_iters++;
    }


    // test 2 characters
    for (int a = 0; a < abet_len; a++)  /* BEGIN LOOP DEPTH 0 */
    {
        printf("\nRound %2i | %c ", a, alphabet[a]);
        for (int b = 0; b < abet_len; b++)  /* BEGIN LOOP DEPTH 1 */
        {
            printf(".");

            key[0] = alphabet[a];
            key[1] = alphabet[b];
            key[2] = '\0';

            if (strcmp(crypt(key, salt), hash) == 0)
            {
                printf("\nMatch! %s (took %li tries)\n", key, n_iters);
                return 0;
            }

            n_iters++;
        }  /* END LOOP DEPTH 1 */

    }  /* END LOOP DEPTH 0 */


    // test 3 characters
    for (int a = 0; a < abet_len; a++)  /* BEGIN LOOP DEPTH 0 */
    {
        printf("\nRound %2i | %c ", a, alphabet[a]);
        for (int b = 0; b < abet_len; b++)  /* BEGIN LOOP DEPTH 1 */
        {
            printf(".");
            for (int c = 0; c < abet_len; c++)  /* BEGIN LOOP DEPTH 2 */
            {
                key[0] = alphabet[a];
                key[1] = alphabet[b];
                key[2] = alphabet[c];
                key[3] = '\0';

                if (strcmp(crypt(key, salt), hash) == 0)
                {
                    printf("\nMatch! %s (took %li tries)\n", key, n_iters);
                    return 0;
                }

                n_iters++;
            }  /* END LOOP DEPTH 2 */

        }  /* END LOOP DEPTH 1 */

    }  /* END LOOP DEPTH 0 */


    // test 4 characters
    for (int a = 0; a < abet_len; a++)  /* BEGIN LOOP DEPTH 0 */
    {
        printf("\nRound %2i | %c ", a, alphabet[a]);
        for (int b = 0; b < abet_len; b++)  /* BEGIN LOOP DEPTH 1 */
        {
            printf(".");
            for (int c = 0; c < abet_len; c++)  /* BEGIN LOOP DEPTH 2 */
            {
                for (int d = 0; d < abet_len; d++)  /* BEGIN LOOP DEPTH 3 */
                {
                    key[0] = alphabet[a];
                    key[1] = alphabet[b];
                    key[2] = alphabet[c];
                    key[3] = alphabet[d];
                    key[4] = '\0';

                    if (strcmp(crypt(key, salt), hash) == 0)
                    {
                        printf("\nMatch! %s (took %li tries)\n", key, n_iters);
                        return 0;
                    }

                    n_iters++;
                }  /* END LOOP DEPTH 3 */

            }  /* END LOOP DEPTH 2 */

        }  /* END LOOP DEPTH 1 */

    }  /* END LOOP DEPTH 0 */


    // test 5 characters
    for (int a = 0; a < abet_len; a++)  /* BEGIN LOOP DEPTH 0 */
    {
        printf("\nRound %2i | %c ", a, alphabet[a]);
        for (int b = 0; b < abet_len; b++)  /* BEGIN LOOP DEPTH 1 */
        {
            printf(".");
            for (int c = 0; c < abet_len; c++)  /* BEGIN LOOP DEPTH 2 */
            {
                for (int d = 0; d < abet_len; d++)  /* BEGIN LOOP DEPTH 3 */
                {
                    for (int e = 0; e < abet_len; e++)  /* BEGIN LOOP DEPTH 4 */
                    {
                        key[0] = alphabet[a];
                        key[1] = alphabet[b];
                        key[2] = alphabet[c];
                        key[3] = alphabet[d];
                        key[4] = alphabet[e];
                        key[5] = '\0';

                        if (strcmp(crypt(key, salt), hash) == 0)
                        {
                            printf("\nMatch! %s (took %li tries)\n", key, n_iters);
                            return 0;
                        }

                        n_iters++;

                    }  /* END LOOP DEPTH 4 */

                }  /* END LOOP DEPTH 3 */

            }  /* END LOOP DEPTH 2 */

        }  /* END LOOP DEPTH 1 */

    }  /* END LOOP DEPTH 0 */

    printf("\nNo match\n");
    return 0;
}


/**
 * Validate hash passed as command line argument
 * @param    {string}   hash   Candidate hash to check
 * @returns  {boolean}         True if 'hash' is 13 characters long
*/
bool isValidHash(string hash)
{
    if (strlen(hash) != 13)
    {
        return false;
    }
    for (int i = 0, n = strlen(hash); i < n; i++)
    {
        if (!isprint(hash[i]))
        {
            return false;
        }
    }
    return true;
}


/**
* function to generate string of all English alpha characters
* @returns   {array}   Pointer to array of upper & lowercase English characters
*/
char *makeAlphabet(void)
{
    int indx = 0;
    static char alphabet[53];

    for (int i = 65; i < 123; i++)
    {
        if (isalpha(i))
        {
            // eprintf("%c | %i \n", i, i);  // diag
            alphabet[indx] = i;
            indx++;
        }
    }

    alphabet[52] = '\0';

    return alphabet;
}
