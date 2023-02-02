// EXERCISE 3: BINARY FILES

// Includes the standard library headers for input/output and string operations
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Program constants
#define FILE_NAME "persons.bin" // Fixed file name for the binary file
#define MAX_NAME 20             // Maximum length for first name and family name
#define MAX_PNUM 13             // Maximum length for personal number (SSN)
#define ERROR_MSG "Error: Please enter a valid name (max 20 characters)\n"

// Typedefs ---------------------------------------------------------------------------
typedef struct // A record is defined as a structure that contains three fields
{
    char firstname[MAX_NAME];   // First name
    char famname[MAX_NAME];     // Family name
    char pers_number[MAX_PNUM]; // Personal number (SSN)
} PERSON;

// Function declaration----------------------------------------------------------------
PERSON input_record(void);             // Reads a person’s record from user input
void write_new_file(PERSON *inrecord); // Creates a new binary file and writes the first record
void printfile(void);                  // Prints out all persons stored in the binary file
void search_name();                    // Searches for a person in the binary file by name
void search_by_firstname(char *name);  // Prints out the person if in list
void search_by_famname(char *name);    // Prints out the person if in list
void append_file(PERSON *inrecord);    // Appends a new person's information to the binary file
unsigned int enterChoice(void);        // Reads user's menu choice for different operations

// Main Program------------------------------------------------------------------------
int main(void)
{
    PERSON person; // Declare a variable of type PERSON and a file pointer for the binary file
    FILE *filePtr; // filePtr = persons.dat file pointer

    unsigned int choice; // User's menu choice

    // Loop that allows user to choose between different operations
    while ((choice = enterChoice()) != 5)
    {
        switch (choice)
        {
        case 1:
            // Add dummy person when creating file
            strcpy(person.firstname, "Anna");
            strcpy(person.famname, "Andersson");
            strcpy(person.pers_number, "200012311777");

            filePtr = fopen(FILE_NAME, "wb");
            if (!filePtr)
            {
                puts("File could not be opened.");
                return 1;
            }
            // Create a new binary file and discard the old contents
            write_new_file(&person);
            break;
        case 2:
            // Add a new person's information to the binary file
            person = input_record();
            append_file(&person);
            break;
        case 3:
            // Search for a person in the binary file
            search_name();
            break;
        case 4:
            // Print all the persons' information stored in the binary file
            printfile();
            break;
        case 5:
            // Close the file and exit the program
            fclose(filePtr);
            exit(0); // indicates successful termination
        default:
            printf("Invalid choice. Try again\n");
            break;
        }
    }
    fclose(filePtr); // Closes the file
    return 0;        // Indicates successful termination
}
// All functions---------------------------------------------------------------------

// Reads a person's record
PERSON input_record(void)
{
    PERSON p;
    printf("Enter first name: ");
    scanf("%s", p.firstname);

    // input validation, accoring predefined max lenght
    while (strlen(p.firstname) > MAX_NAME - 1)
    {
        printf(ERROR_MSG); // Print predefined error message
        scanf("%s", p.firstname);
    }
    printf("Enter family name: ");
    scanf("%s", p.famname);

    // input validation, accoring pre.defined max lenght
    while (strlen(p.famname) > MAX_NAME - 1)
    {
        printf(ERROR_MSG); // Print predefined error message
        scanf("%s", p.famname);
    }
    printf("Enter personal number (YYYYMMDDNNN): ");
    scanf("%s", p.pers_number);

    // input validation, accoring pre.defined max lenght
    while (strlen(p.pers_number) != MAX_PNUM - 1)
    {
        printf("Error, please enter a valid number (YYYYMMDDNNN): ");
        scanf("%s", p.pers_number);
    }
    return p;
}

// Creates a file and writes the first record
void write_new_file(PERSON *inrecord)
{
    FILE *filePtr;

    // Open the binary file in write mode and discard the old contents
    filePtr = fopen(FILE_NAME, "wb");
    if (!filePtr)
    {
        // Exit program if unable to create file
        puts("File could not be opened.");
        exit(1);
    }

    // Write the dummy record to the binary file
    fwrite(inrecord, sizeof(PERSON), 1, filePtr);

    // Close the file
    fclose(filePtr);
    printf("File created successfully\n");  // Print success message
}


void append_file(PERSON *inrecord)
{
    FILE *filePtr;                    // filePtr = persons.dat file pointer
    filePtr = fopen(FILE_NAME, "ab"); // ab = open file for writing at the eof (binary)

    // If the file cannot be opened, print an error message and return
    if (filePtr == NULL)
    {
        printf("Error: Cannot open file\n");
        return;
    }
    // If there is data to be written to the file, write the data
    if (inrecord != NULL)
    {
        // Use the fwrite() function to write the data
        // int fwrite (const void *ptr, size_T size, size_t n, FILE *stream)
        fwrite(inrecord, sizeof(PERSON), 1, filePtr);
    }
    fclose(filePtr); // Close the file stream
    printf("Record added successfully\n");
}

void search_name()
{
    char name[MAX_NAME];        // variable to store name for searching
    unsigned int search_choice; // variable to store user's choice for search criteria

    printf("Enter 1: for first name or 2: for family name: ");

    scanf("%d", &search_choice); // Read user's search choice
    printf("Enter name to search for: ");
    scanf("%s", name);
    if (search_choice == 1)
    {
        search_by_firstname(name); // call function to search by first name
    }
    else if (search_choice == 2)
    {
        search_by_famname(name); // call function to search by family name
    }
    else
    {
        printf("Invalid search choice\n"); // handle case where user inputs an invalid
    }
}

void search_by_firstname(char *name)
{
    FILE *filePtr;                    // Declare a file pointer filePtr to access the file.
    PERSON p;                      // Create a person struct to store data read from the file
    filePtr = fopen(FILE_NAME, "rb"); // rb = Open an existing file for reading (binary)

    // Check if the file was successfully opened or if it's empty
    if (filePtr == NULL)
    {
        printf("Error opening file or file is empty!\n");
        return;
    }
    // Read a single person's data from the file
    while (fread(&p, sizeof(PERSON), 1, filePtr) == 1)
    {
        // Compare the name from the file to the name to search for
        if (strcmp(p.firstname, name) == 0)
        {
            // Print the person's information if the name matches
            printf("%s %s %s\n", p.firstname, p.famname, p.pers_number);

            // Close the file and return
            fclose(filePtr);
            return;
        }
    }
    // If the person was not found, print an error message
    printf("Person not found\n");

    // Close the file
    fclose(filePtr);
}

void search_by_famname(char *name)
{
    FILE *filePtr;                    // Declare a file pointer filePtr to access the file.
    PERSON p;                      // Create a person struct to store data read from the file
    filePtr = fopen(FILE_NAME, "rb"); // rb = Open an existing file for reading (binary)

    // Check if the file was successfully opened or if it's empty
    if (filePtr == NULL)
    {
        printf("Error opening file or file is empty!\n");
        return;
    }
    // Read a single person's data from the file
    while (fread(&p, sizeof(PERSON), 1, filePtr) == 1)
    {
        // Compare the name from the file to the name to search for
        if (strcmp(p.famname, name) == 0)
        {
            // Print the person's information if the name matches
            printf("%s %s %s\n", p.firstname, p.famname, p.pers_number);

            // Close the file and return
            fclose(filePtr);
            return;
        }
    }
    // If the person was not found, print an error message
    printf("Person not found\n");

    // Close the file
    fclose(filePtr);
}

// Function to print all records in the file
void printfile()
{
    FILE *filePtr;                    // Declare a file pointer filePtr to access the file.
    PERSON p;                      // Declare a `PERSON` struct to store data read from the file.
    filePtr = fopen(FILE_NAME, "rb"); // rb = Open an existing file for reading (binary)
    if (filePtr == NULL)
    {
        // If the file could not be opened, print an error message.
        printf("Error opening file or file is empty!\n");
        return;
    }
    while (fread(&p, sizeof(PERSON), 1, filePtr) == 1)
    {
        // Print the firstname, famname, and pers_number of each person read from the file.
        printf("%s %s %s\n", p.firstname, p.famname, p.pers_number);
    }
    // Close the file.
    fclose(filePtr);
}

// Displays the menu options to the user
// and receives their choice as input.
unsigned int enterChoice(void)
{
    // Display available menu options
    printf("%s", "\nEnter your choice: \n"
                 "1. Create a new and delete the old file.\n"
                 "2. Add a new person to the file.\n"
                 "3. Search for a person in the file.\n"
                 "4. Print out all in the file.\n"
                 "5. Exit the program.\n");
    unsigned int menuChoice;  // Variable to store user's choice
    scanf("%u", &menuChoice); // Receive choice from user

    return menuChoice;
}