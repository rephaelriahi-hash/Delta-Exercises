/*------------------------------------------------------
* Filename: array_series.c
* Description: The program gets an array and prints how it is arranged.
* Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>

#define ARRAY_SIZE 15

int is_increasing(int arr[],int size);
int is_decreasing(int arr[],int size);
int is_constant(int arr[],int size);

int main() {
    float input_int_check = 0;
    int arr [ARRAY_SIZE] = {0};

    printf("array_series.exe\n");
    printf("Please enter the elements of the array:\n");

    for(int i = 0; i < ARRAY_SIZE; i++){
        if(scanf("%f", &input_int_check) != 1 || input_int_check - (int)input_int_check != 0){
            printf("Wrong input!");
            return 0;
        }
        arr[i] = (int)input_int_check;
    }

    if (is_increasing(arr,ARRAY_SIZE)){
        printf("The array is increasing\n");
    } else if (is_decreasing(arr,ARRAY_SIZE)){
        printf("The array is decreasing\n");
    }else if (is_constant(arr,ARRAY_SIZE)){
        printf("The array is constant\n");
    }else{
        printf("The array is messed up");
    }

    return 0;
}

int is_increasing(int arr[],int size){
    for(int i = 0; i < ARRAY_SIZE - 1; i++){// we go until 14 because 
    // we compare with the next, the second condition means that if they are all false we don't 
    // need to continue to check
        if(arr[i] >= arr[i+1]){
                return 0;
            }
    }
    return 1;
}

int is_decreasing(int arr[],int size){
    for(int i = 0; i < ARRAY_SIZE - 1; i++){// we go until 14 because 
    // we compare with the next, the second condition means that if they are all false we don't 
    // need to continue to check
        if(arr[i] <= arr[i+1]){
                return 0;
            }   
    }
    return 1;
}

int is_constant(int arr[],int size){
    for(int i = 0; i < ARRAY_SIZE - 1 ; i++){// we go until 14 because 
    // we compare with the next, the second condition means that if they are all false we don't 
    // need to continue to check  
        if(arr[i] != arr[i+1]){
                return 0;
            }
    }
    return 1;
}