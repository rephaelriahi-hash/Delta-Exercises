/*------------------------------------------------------
* Filename: array_series.c
* Description: The program gets an array and prints how it is arranged.
* Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    int arr [15] = {0};
    int increase = 1, decrease = 1, constant = 1; // using them like boolean values 

    printf("array_series.exe\n");
    printf("Please enter the elements of the array:\n");

    for(int i = 0; i < 15; i++){
            scanf("%d", &arr[i]);
    }

    for(int i = 0; i < 14 && (increase || decrease || constant); i++){// we go until 14 because \
    // we compare with the next, the second condition means that if they are all false we don't 
    // need to continue to check
        if(arr[i] >= arr[i+1]){
                increase = 0;
            }
        if(arr[i] <= arr[i+1]){
                decrease = 0;
            }   
        if(arr[i] != arr[i+1]){
                constant = 0;
            }
    }

    if (increase){
        printf("The array is increasing\n");
    } else if (decrease){
        printf("The array is decreasing\n");
    }else if (constant){
        printf("The array is constant\n");
    }else{
        printf("The array is messed up");
    }

    return 0;
}
