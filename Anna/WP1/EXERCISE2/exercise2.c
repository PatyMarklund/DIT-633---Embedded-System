// EXERCISE 2: ENCRYPTION

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // check for 2 arguments (program name and key)
    if (argc == 2)
    {
        // store key validity
        bool valid_key = false;

        // check validity of the key
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            // check key agrument to be a number
            if (isdigit(argv[1][i]))
            {
                valid_key = true;
            }
            // display usage and terminate the program
            else
            {
                printf("Error: Key needs to be a number:\nUsage ./exercise2 key\n");
                printf("Usage ./exercise2 key\n");
                return 1;
            }
        }

        /* convert key to int
        atoi() function converts string data type to int */
        int key = atoi(argv[1]);

        // check for upper and lower case letters and apply the
        // Caesar Cipher encryption formula
        if (valid_key == true)
        {
            char input[300];
            // do loop execution until EOF is reached
            do
            {
                printf("Text: ");
                if (fgets(input, sizeof(input), stdin) == NULL)
                {
                    break;
                }

                for (int i = 0; i < strlen(input); i++)
                {
                    if (isupper(input[i]))
                    {
                        input[i] = ((input[i] - 65 + key) % 26) + 65;
                    }
                    else if (islower(input[i]))
                    {
                        input[i] = ((input[i] - 97 + key) % 26) + 97;
                    }
                }
                printf("Encrypted text: %s", input);
            } while (1);
        }
    }
    // display error message if not enough arguments provided
    else
    {
        printf("Error: Provide argument: Usage ./exercise2 key\n");
        // terminate the program
        return 1;
    }
}
