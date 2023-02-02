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
 
REGTYPE* random_list(void);  // Create a linked list with random numbers
REGTYPE* add_first(REGTYPE* temp, int data);  // Add a new number number to the beginning of the linked list
REGTYPE* print_linked_list(REGTYPE* temp, REGTYPE* head, REGTYPE* old);  // Print the linked list
void print_reverse(REGTYPE* old);  // Print the linked list in reverse using the prev pointer
 
//###### Main program ####### 
int main(int argc, char *argv[]) 
{ 
    int nr=0;   // Counter
    int newEntry = 100;  // New number to be added to the list in the future
 
    // Declare the pointers to the linked list. act_post is the current
    // head is the returned top node from the functions
    // act_post_old is where we save the last node so we can use to print in reverse
    REGTYPE *act_post , *head=NULL, *act_post_old = NULL; 
 
    srand(time(0));     // Random seed  

    // Call function to create a linked list
    head = random_list();    // Return the first node (head) of the list

    //act_post = head;   // Save the current list to the head

    printf("Linked list created with random numbers:");

    /* while( act_post!=NULL){ 
            printf("\n Post nr %d : %d" , nr++, act_post->number); 
            act_post_old = act_post;    // assign to act_post_old the last node of the list
            act_post=act_post->next; 
    } */
    
    act_post_old = print_linked_list(act_post, head, act_post_old);   // Call function to print the linked list

    // Adding a new entry on the list. Call the function to add a new number
    // The return node will become the new head
    head = add_first(head, newEntry);  

    //printf("\n\n");

    //act_post = head;  // Save the current position to head 
    //nr = 0;    // Reset the counter

    printf("Linked list adding a new entry to the beggining of the list:");
    /* while( act_post!=NULL){ 
           printf("\n Post nr %d : %d" , nr++, act_post->number); 
           act_post=act_post->next; 
    } */
    print_linked_list(act_post, head, act_post_old);   // Call function to print the linked list

    //nr = 0;
    printf("Print reverse using prev pointer:");
    print_reverse(act_post_old);

    /* while (act_post_old != NULL) {
        printf("\n Post nr %d: %d", nr++, act_post_old-> number);
        act_post_old = act_post_old -> prev;
    } */
 
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

    REGTYPE *newItem;   // Create a new node that will be used in the first position
    newItem = (REGTYPE *) malloc(sizeof(REGTYPE));    // Allocate a memory for the new node
    newItem-> number = data;  // Assing the new data (number) to the first node
    temp-> prev = newItem;  // The temp node which now became the second will point the previous to the new first node
    newItem-> prev = NULL;  // The new node will assign the prev pointer to NULL as this is the first node now 
    newItem-> next = temp;  // The new node will assing the next pointer to the temp (which now became the second node)
    
    return(newItem);   // Return the new item which is now the first node
} 

// Function that prints the linked list
REGTYPE* print_linked_list(REGTYPE* temp, REGTYPE* head, REGTYPE* old) {
    int nr = 0;

    temp = head;    // Sets the temporary (current) pointer to the head of the list

    while(temp != NULL){ 
           printf("\n Post nr %d: %d", nr++, temp-> number); 
           old = temp;
           temp = temp-> next; 
    }
    printf("\n\n");

    return (old);
}

void print_reverse(REGTYPE* old) {
    int nr = 0;

    while (old != NULL) {
        printf("\n Post nr %d: %d", nr++, old-> number);
        old = old -> prev;
    }

    printf("\n\n");
}

