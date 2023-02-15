#include <stdio.h>
#include <stdlib.h>

int search_number(int number, int tab[], int size);
void sort (int number, int tab []);
void print_sorted(int tab[], int size);

int main () {

    int n = 3;
    int test[] = {1,2,34,5,67,3,23,12,13,10};
    int size = sizeof(test) / sizeof(test[0]);
    printf("%d \n", size);
    int index = search_number(n, test, size);
    printf("%d \n", index);

    sort(size, test);

    print_sorted(test, size);

    return 0;
}

int search_number(int number, int tab[], int size){
    
    int counter = 0;

    for(int i = 0; i < size; i++) {
        if (number == tab[i]){
            return i;
        }
    }
    return -1;
}



//My code. It works but when i becomes bigges than j it doesnt stop fully
void sort (int number, int tab []) {
    //int length = sizeof(tab) / sizeof(tab[0]);
    int temp = 0;

    for(int i = 0; i < number - 1; i++) {
        for(int j = i; j < number - i - 1; j++) {
            /*if(i > j){
                break;*/
            if (tab[j] > tab[j + 1]){
                temp = tab[j + 1];
                tab[j + 1] = tab[j];
                tab[j] = temp; 
            }else {
                continue;
            }
        }
    }
}

void print_sorted(int tab[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d \t", tab[i]);
    }
    printf("\n");
}

//code from AI. Need to debug to understand
/*void sort(int number, int tab[]) {
    int temp;
    for (int i = 0; i < number - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < number; j++) {
            if (tab[j] < tab[min_index]) {
                min_index = j;
            }else {
                continue;
            }
        }
        temp = tab[min_index];
        tab[min_index] = tab[i];
        tab[i] = temp;
    }
}*/