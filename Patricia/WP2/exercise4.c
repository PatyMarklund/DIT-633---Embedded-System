#include <stdio.h> 
#include <stdlib.h> 

void display(int data);

int main() {
    int s1;
    int s2; 
    int m;
    int var_tx = 0;
    int var_rx = 0;
    s1 = 5; // 00000101
    s2 = 2; // 00000010
    m = 0;  // 00000000

    var_tx = var_tx | s1;       // 00000101   
    var_tx = var_tx | (s2<<3);  // 00010000 = 00010101
    var_tx = var_tx | (m<6);    // 00000000

    var_rx = var_tx;    

    // 10101011

    display(var_rx);
    return 0;
}

void display(int data) {
    int s1_rx = 0;
    int s2_rx = 0;
    int m_rx = 0;

    s1_rx = data & (0b00000111);  // 00010101  = 00000101
    s2_rx = (data >> 3) & (0b00000111);  // 00010101 -> 00001010 = 00000010
    m_rx = (data >> 6) & 0b00000001;  // 00010101 -> 00000000 = 00000000

    printf("s1 = %d\n", s1_rx);
    printf("s2 = %d\n", s2_rx);
    printf("m = %d\n", m_rx);
}
// 00010101
// 00000111 = 00000101 = 5

// 00010101 >> 3 = 00000010
//                 00000111 = 00000010 = 2

// 00010101 >> 6 = 00000000
//                 00000001 = 00000000 = 0
