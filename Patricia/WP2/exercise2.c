// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 2
// Exercise 2
// Submission code: xxxxx (provided by your TA-s)

//#### Include session ####
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
//#### Constants ##### 
#define MAX 5   
 
// ##### typedefs #### 
typedef struct q{ 
        int number; 
        struct q *next; 
        struct q *prev; 
} REGTYPE; 
 
// ##### Function declarations ##### 
 
REGTYPE* random_list(void); 
REGTYPE* add_first(REGTYPE* temp, int data); 
void print_linked_list(REGTYPE* temp, REGTYPE* head);
void print_reverse(REGTYPE* temp, REGTYPE* head);
 
//###### Main program ####### 
int main(int argc, char *argv[]) 
{ 
    int nr=0; 
    int newEntry = 100;
 
    REGTYPE *act_post , *head=NULL; 
 
    srand(time(0));     // Random seed  
    head = random_list();    // Call function to create a linked list
    
    printf("Linked list created with random numbers:");
    print_linked_list(act_post, head);   // Call function to print the linked list

    //Adding a new entry on the list
    head = add_first(head, newEntry);

    printf("Linked list adding a new entry to the beggining of the list:");
    print_linked_list(act_post, head);   // Call function to print the linked list

    printf("\n");
    print_reverse(act_post, head);
 
 // --- Free the allocated memory  --- 
 
  while((act_post=head)!=NULL){ 
     head=act_post->next; 
     free(act_post); 
  } 
   
  return 0; 
} 
 
// ====     End of main   ====================================== 

//###### Function Definition #######
 
REGTYPE* random_list(void ){ 
    int i = 0;   
    /* Initialize 3 pointers to the REGTYPE list. Top is the head, old is the last item added to the list
    and item is the current element being added to the list */
    REGTYPE *top = NULL, *old = NULL, *item;    
    
    for(i = 0; i < MAX; i++) {   // Iterate through the MAX number of times
        item = (REGTYPE *) malloc(sizeof(REGTYPE));   // Allocate memory for the new elemet
        item->number = rand() % (100 + 1);      // Generate a random number from 0-100 and sabe in the value number
        item->next = NULL;        // Sets the pointer next to NULL
        if(top == NULL) {  // Checks if the linked list is empty.
            item->prev = NULL;   // Sets the previous pointer to NUll as this is the first element on the list
            top = item;    // If it is make the current element to become the first element of the list
            old = item;    // Make the current element also to be the last element of the list
        }else {   // If the list is not empty
            item->prev = old;   // Sets the previous pointer of the new element to the old element 
            old->next = item;   // Sets the next pointer of the old element to the current element
            old = item;     // Sets the current element as the old element of the list
        }
    }
    return(top); 
} 
 
//==========================================================                 
 
/*That adds a new record to the first position of the list and assign the field numbers the value of data. 
The function must return a pointer to the new first entry in the list. Extend main() so that this 
function is tested.*/
REGTYPE* add_first(REGTYPE* temp, int data){ 

    REGTYPE *newItem;
    newItem = (REGTYPE *) malloc(sizeof(REGTYPE));
    newItem-> number = data;
    newItem-> next = temp;
    
    return(newItem);
} 

// Function that prints the linked list
void print_linked_list(REGTYPE* temp, REGTYPE* head) {
    int nr = 0;

    temp = head;    // Sets the temporary pointer to the head of the list

    while(temp != NULL){ 
           printf("\n Post nr %d: %d", nr++, temp-> number); 
           temp = temp-> next; 
    }
    printf("\n");
}

void print_reverse(REGTYPE* temp, REGTYPE* head) {
    int nr = 0;

    temp = head;

    while (temp != NULL) {
        printf("\n Post nr %d: %d", nr--, temp-> number);
        temp = temp -> prev;
    }
    printf("\n");
}

