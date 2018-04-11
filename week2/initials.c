///////////////////////////////////////////////////////////////////////////////
//
//  Prints initials from a user's name
//
//  Works by selectively printing only characters that are either not spaces
//  and are located at index 0, or are not spaces and are preceded by a space.
//  Insensitive to qty of whitespace characters.
//
///////////////////////////////////////////////////////////////////////////////

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// declare functions
void printTable(string input);
bool validInput(string input);
void printInitials(string s);


int main(void)
{
    string s;

    do
    {
        s = get_string("Gimme name! ");
    }
    while(!validInput(s));

    printInitials(s);

}


/**
 * Validate inputs - should be a string of alpha and space chars and have length > 0
 * @param   {string}   input   Candidate input to check
 * @returns {boolean}          True if valid
*/
bool validInput(string input)
{
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isprint(input[i]) || isdigit(input[i]))
        {
            return false;
        }
    }
    return strlen(input) > 0;
}


/**
 * Determine and print user's initials
 * @param   {string}   s   String to convert
*/
void printInitials(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // if first letter is not a space and is printable char
        if (i == 0 && !isspace(s[i]) && isprint(s[i + 1]))
        {
            printf("%c", toupper(s[i]));
        }
        // if char is not a space and is preceded by a space
        else if (!isspace(s[i]) && isspace(s[i - 1]))
        {
            printf("%c", toupper(s[i]));
        }
    }
    printf("\n");
}
