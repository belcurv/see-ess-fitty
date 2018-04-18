///////////////////////////////////////////////////////////////////////////////
//
// Helper functions for music
//
// Spec:
//   `duration` - should take as input as a string a fraction (e.g., 1/4) and
//   return as an int a corresponding number of eigths (2, in this case, since
//   1/4 is equivalent to 2/8);
//
//   `frequency` - should take as input as a string a note formatted as
//     XY  (e.g., A4),  where X is any of A through G and Y is any of 0 through 8
//     XYZ (e.g., A#4), where X is any of A through G, Y is # or b, and Z is any
//       of 0 through 8,
//   and return as an int the note’s corresponding frequency, rounded to the
//   nearest integer
//
//   `is_rest` - should return true if its input, a string, represents a rest in
//   our machine-readable format, otherwise false.
//
// Music Notes -> Frequencies
//   https://pages.mtu.edu/~suits/notefreqs.html
//
///////////////////////////////////////////////////////////////////////////////

#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

#define WHOLE_STEP 2
#define HALF_STEP 1


/**
 * Converts a fraction to the equivalent number of eigths
 * @param    {string}   fraction   Fraction formatted as X/Y
 * @returns  {int}                 Equivalent number of eighths
*/
int duration(string fraction)
{
    int numerator = atoi(&fraction[0]);
    int denominator = atoi(&fraction[2]);
    return 8 / denominator * numerator;
}


/**
 * Calculates frequency, f, (in Hz) of a note
 *   f = 2 ^ (n/12) * 440
 * where `n` = number of semitones from that note to A4
 *
 * @param    {string}   note   String representation of a note (e.g., A4)
 * @returns  {int}             The note's corresponding frequency in Hz.
*/
int frequency(string note)
{
    float accidental, octave, semitone_adj;

    // calculate tone adjustment from on note letter
    switch (note[0])
    {
        case 'A':
            semitone_adj = 0;
            break;
        case 'B':
            semitone_adj = WHOLE_STEP; // +2
            break;
        case 'C':
            semitone_adj = -1 * ((4 * WHOLE_STEP) + HALF_STEP); // -9
            break;
        case 'D':
            semitone_adj = -1 * ((3 * WHOLE_STEP) + HALF_STEP); // -7
            break;
        case 'E':
            semitone_adj = -1 * ((2 * WHOLE_STEP) + HALF_STEP); // -5
            break;
        case 'F':
            semitone_adj = -2 * WHOLE_STEP; // -4
            break;
        case 'G':
            semitone_adj = -WHOLE_STEP; // -2
            break;
        default:
            semitone_adj = 0;
    }

    // get accidental (if any) and octave
    if (strlen(note) == 2)
    {
        accidental = 0;
        octave = atoi(&note[1]);
    }
    else
    {
        accidental = (note[1] == '#') ? HALF_STEP : -HALF_STEP;
        octave = atoi(&note[2]);
    }

    // calculate octave adjustment
    int oct_adjust = (octave - 4) * 12;

    // do the math! 'n' = sum of semitone_adj + accidental + oct_adjust
    return round(pow(2, ((semitone_adj + accidental + oct_adjust) / 12)) * 440);

}


/**
 * Determines whether a string represents a 'rest'
 * A 'rest' is any line ending (i.e., \n), and is parsed as "".
 * @param    {string}   s   Candidate string to check
 * @returns  {bool}         True if input string is a 'rest'
*/
bool is_rest(string s)
{
    return strcmp(s, "") == 0;
}
