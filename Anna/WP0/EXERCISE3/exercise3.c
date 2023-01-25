// the "stdio.h" header file, (standard input/output)
#include <stdio.h>
// the "string.h" header file, (string operations) e.g comparison
#include <string.h>

int main(int argc, char *argv[])
{
    // check for less or more argument than 2
    if (argc != 2)
    {
        printf("Error: Only provide one argument.\nEnter -h for more information");
    }
    // strcmp - compare (two strings) arvg[1] with "-h"
    // strcmp returns 0 if the two strings are identical
    else if (strcmp(argv[1], "-h") == 0)
    {
        // print message in the console
        printf("Only enter one argument\n");
    }
    else
        // print message with <argument> in the console
        printf("\n Hello World! - I'm %s!", argv[1]);

    // program was executed successfully
    return 0;
}
