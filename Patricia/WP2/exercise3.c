// The database should be stored as a binary file 

/* 1. Create a new and delete the old file. OK
   2. Add a new person to the file.         OK
   3. Search for a person in the file.      OK
   4. Print out all in the file.            OK
   5. Exit the program.  
*/

// After entered the choice the program executes the task and returns to the menu for new choices.

/* Fail Safe:
    • Checking if the file exists 
    • Checking if the list is empty  
*/
#define MAX_NAME 20
#define MAX_PNUM 13

// Include session
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <stdbool.h>  // to use with bool variable

//###### Typedefs #######

typedef struct { 
        char firstname[MAX_NAME]; 
        char famname[MAX_NAME]; 
        char pers_number[MAX_PNUM]; // yyyymmddnnnc 
} PERSON; 

//###### Function Declaration #######

PERSON input_record(void);    // Reads a person’s record. 
void write_new_file(PERSON *inrecord, FILE *fileptr, char *fileName);  // Creates a file and writes the first record
void printfile(PERSON *inrecord, char *fileName);     // Prints out all persons in the file 
void search_by_firstname(char *name, PERSON *inrecord, char *fileName); // Prints out the person if in list   
void append_file(PERSON *inrecord, char *fileName);    // appends a new person to the file 
void menu(PERSON *inrecord);

//###### Main program #######
 
int main(void){ 
    PERSON *ppost;
    //FILE* fileptr;
    //char * fileName = "exercise3.bin";

    menu(ppost);

    free(ppost);
    return(0);     
}

//###### Function Definition #######

void menu(PERSON *inrecord) {
    //PERSON *ppost;
    FILE* fileptr;
    char * fileName = "exercise3.bin";

    int menu_choice;

    printf("Welcome to our database management! \nEnter one of the options from 1-5 to manage the database: \n");
    printf("1. Create a new and delete the old file. \n"
           "2. Add a new person to the file. \n"
           "3. Search for a person in the file. \n"
           "4. Print out all in the file. \n"
           "5. Exit the program. \n");
    scanf("%d", &menu_choice);
    printf("The choice %d\n", menu_choice);

    switch (menu_choice)
    {
        case 1:   // Create a new and delete the old file.
            write_new_file(inrecord, fileptr, fileName);   // OK
            break;
        case 2:  // Add a new person to the file
            //append_file();
            break;
        case 3:  // Search for a person in the file
            search_by_firstname("Pedrita", inrecord, fileName);
            break;
        case 4:  // Print out all in the file
            printfile(inrecord, fileName);
            break;
        case 5:  // Exit the program
            exit(0);
            break;
        default:
            printf("invalid choice\n");
            break;
    }

    //free(inrecord);
}

void write_new_file(PERSON *inrecord, FILE *fileptr, char *fileName) {
    //Program creates a new file with the specified filename (hardcoded, fixed) and writes a first dummy record to 
    //the file and then close it.
    remove(fileName);
    const int total = 1;  // total of people to be entered
    inrecord = malloc(sizeof(PERSON) * total);

    strcpy(inrecord[0].famname, "Antunes");
    strcpy(inrecord[0].firstname, "Patricia");
    strcpy(inrecord[0].pers_number, "198688888888");

    fileptr = fopen(fileName, "wb");

    if (fileptr == NULL){
        printf("Error! File is empty. \n");
        exit(0);
    } 

    for (int n = 0; n < total; n++){
        fwrite(inrecord, sizeof(PERSON), total, fileptr);
        inrecord++;
    }

    /* if (fwrite(inrecord, sizeof(PERSON), total, fileptr) != total) 
        return 1; */

    printf("File written ok! \n");

    fclose(fileptr);
    
    main();
}

void append_file(PERSON *inrecord, char *fileName) {
    //Gives an opportunity to put in one new person to a temp record and then add this record in 
    //the end of the file.
    // ab
    //PERSON person;
    FILE * fileptr;
    fileptr = fopen(fileName, "ab");
    //input_record();

    if (fileptr == NULL){
        printf("Error! File is empty. \n");
        //write_new_file(&person, fileptr, fileName);
        return;
    }
    if (inrecord != NULL) {
        fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    }
    fclose(fileptr);
    
    main();
}

void search_by_firstname(char *name, PERSON *inrecord, char *fileName) {
    //Gives you an opportunity to search for all persons with either a specified first name or  
    //family name (by choice). The program prints out all persons with that name. 
    // rb
    PERSON person;
    FILE * fileptr;
    fileptr = fopen(fileName, "rb");
    char * nameToSearch;
    nameToSearch = malloc(sizeof(char) * MAX_NAME);
    printf("Enter the first name of the person you want to search: \n");
    scanf("%s", nameToSearch);

    if (fileptr == NULL){
        printf("Error! File is empty. \n");
        return;
    }
    while ((fread(&person, sizeof(PERSON), 1, fileptr) != 0)){
        if (strcmp(nameToSearch, person.firstname) == 0){
            printf("%s \n", person.famname);
            printf("%s \n", person.firstname);
            printf("%s \n", person.pers_number);
        }else {
            printf("This name doesnt exist in the database \n");
        }
    }
    free(nameToSearch);
    main();
}

void printfile(PERSON *inrecord, char *fileName) {
    //Prints out the whole list  
    FILE * fileptr;
    PERSON person;
    int n = 0;
    fileptr = fopen(fileName, "rb");

    if (fileptr == NULL){
        printf("Error! File is empty. \n");
        return;
    }

    while ((fread(&person, sizeof(PERSON), 1, fileptr) != 0)) {
        printf("%s \n", person.famname);
        printf("%s \n", person.firstname);
        printf("%s \n", person.pers_number);
        n++;
        //person++;
    }

    fclose(fileptr);
    main();
}

PERSON input_record(void) {
    //Reads a person’s record.
    PERSON* person;


}