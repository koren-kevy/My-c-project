#include <stdio.h>
#include <ctype.h>

/*
 * This program takes text from the user or a file and does these changes:
 * Turns the first letter of a sentence into an upper case.
 * Turns every letter between quotation marks into an upper case.
 * In any other place, turns any letter into a lower case.
 * Numbers will not be printed, they will be skipped.
 * Every other character will be printed with no change.
*/

int main()
{
    int c; /* A character used for getting the next char as input. */
    int in_quotes = 0; /* A variable used for checking if we are in quotes. */
    int start_sentence = 1; /* A variable used for checking if we are at the start of a sentence. */

    printf("Enter text\n");

    while((c = getchar()) != EOF)
        /* A while loop that keeps getting input as long as we don't reach EOF,
        and keeps the character in the variable 'c'. */
    {
       if(isdigit(c))
           continue; /* We skip on numbers. */

       if(c == '"')
       {
           /* If the character is " we print it, and turn the variable 'in_quotes' to have a true value. */

           putchar(c);
           in_quotes = !in_quotes;
           continue;
       }

       if(in_quotes)
           putchar(toupper(c)); /* We turn text between quotation marks to upper case. */

       else
       {
           if(start_sentence && isalpha(c))
           {
               putchar(toupper(c)); /* We are at the start of a sentence so we print that letter in upper case. */
               start_sentence = 0; /* We mark no longer being in the start of a sentence. */
           }

           else if(isupper(c))
               putchar(tolower(c)); /* We lower case c. */

           else
               putchar(c); /* We print unchanged. */

           if(c == '.') /* We check if c is a '.' so we know it's the end of a sentence. */
               start_sentence = 1; /* We update the variable 'start_sentence' to have a true value. */

           else if(!isspace(c))
               start_sentence = 0; /* We update the variable 'start_sentence' to have a false value. */
       }

       if(c == '\n')
           putchar(c); /* We print a new line. */
    }
    return 0;
}
