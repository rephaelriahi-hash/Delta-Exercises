/*------------------------------------------------------
* Filename: max.c
* Description: The program creates 2 variables and prints the biggest
* Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    int x = 7;
    int y = 5;
    int z = (x >= y) ? x : y;
    printf("The bigger number is : %d\n",z); 
    return 0;
}
