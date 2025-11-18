/*------------------------------------------------------
* Filename: array_sort.c
* Description: the program gets an array of integers and an arry of pointers to them and sorts the array of pointers according to the integers
* Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 10

void sort(int *ptr[],int size);
void swap(int **ptr1, int **ptr2);

int main() {
    float input_int_check = 0;
    int arr_of_int [ARRAY_SIZE] = {0};
    int *arr_of_ptr [ARRAY_SIZE] = {NULL};

    for(int i = 0; i < ARRAY_SIZE; i++){
        arr_of_ptr[i] = &arr_of_int[i];
    }
    
    printf("Enter the array of integers: \n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        if(scanf("%f", &input_int_check) != 1 || input_int_check - (int)input_int_check != 0){
            printf("Wrong input!");
            return 0;
        }
        *(arr_of_int + i) = (int)input_int_check;
    }

    printf("Array before sort \n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("value: %d address: %p\n",*arr_of_ptr[i],arr_of_ptr[i]);
    }

    sort(arr_of_ptr,ARRAY_SIZE);

    printf("\nArray after sort \n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("value: %d address: %p\n",arr_of_int[i],arr_of_ptr[i]);
    }
    return 0;
}

void sort(int *ptr[],int size){
    for(int i = 0; i < size - 1; i++ ){
        for(int j = i + 1 ; j < size ; j++){
            if(*ptr[j] < *ptr[i]){
                swap(&ptr[i],&ptr[j]);
            }
        }
    }
}

void swap(int **ptr1, int **ptr2){
    int *tmp_ptr = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp_ptr;
}