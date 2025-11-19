/*------------------------------------------------------
* Filename: remove_dup.c
* Description: the program takes a sorted array with duplicates and removes the duplicates using 
* 3 different function
* Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>
#include "stdlib.h"

#define ARRAY_SIZE 10

void print_arr(int* arr,int size);
int* remove_dup1(int *arr,int *size);
int remove_dup2(int *arr, int size,int **reduced_arr);
void remove_dup3(int **arr, int *size);

int main() {
    int size1 = ARRAY_SIZE, size2 = ARRAY_SIZE, size3 = ARRAY_SIZE ;
    int arr [ARRAY_SIZE] = {1,1,1,2,2,3,3,4,4,4}; 
    int *reduced_arr1,*reduced_arr2,*reduced_arr3;

    printf("Before removing:\n");
    print_arr(arr,ARRAY_SIZE);

    reduced_arr1 = remove_dup1(arr,&size1);
    if(!reduced_arr1){
        return -1;
    }
    size2 = remove_dup2(arr,size2,&reduced_arr2);
    if(!reduced_arr2){
        return -1;
    }
    reduced_arr3 = arr;
    remove_dup3(&reduced_arr3,&size3);
    if(!arr){
        return -1;
    }
    
    printf("After removing:\n");
    print_arr(reduced_arr1,size1);
    print_arr(reduced_arr2,size2);
    print_arr(reduced_arr3,size3);

    free(reduced_arr1);
    free(reduced_arr2);
    free(reduced_arr3);
    return 0;
}

void print_arr(int* arr,int size){
    for(int i = 0; i < size; i++){
        printf("%d ",*(arr +i));
    }
    printf("\n");
}

int* remove_dup1(int *arr,int *size){
    int new_size = 0;
    int *reduced_arr = (int*)malloc(*size * sizeof(int));
    if(reduced_arr == NULL){
        return NULL;
    }

    for(int i = 0;i < *size; i++){
        if(i == 0 ||arr[i] != reduced_arr[new_size - 1]){
            *(reduced_arr + new_size++) = arr[i];
        }
    }
    *size = new_size;
    reduced_arr = (int*)realloc(reduced_arr, new_size* sizeof(int));
    return reduced_arr;
}

int remove_dup2(int *arr, int size,int **reduced_arr){
    int new_size = 0;
    *reduced_arr = (int*)malloc(size * sizeof(int));
    if(!*reduced_arr){
        return -1;
    }

    for(int i = 0;i < size; i++){
        if(i == 0 ||arr[i] != *(*reduced_arr + new_size - 1)){
            *(*reduced_arr + new_size++) = arr[i];
        }
    }
    *reduced_arr = (int*)realloc(*reduced_arr, new_size* sizeof(int));
    return new_size;
}

void remove_dup3(int **arr, int *size){
    int new_size = 0;
    int *reduced_arr = (int*)malloc(*size * sizeof(int));
    if(reduced_arr){
        for(int i = 0;i < *size; i++){
            if(i == 0 ||*(*arr + i) != *(reduced_arr + new_size - 1)){
                *(reduced_arr + new_size++) = *(*arr + i);
            }
        }
        *size = new_size; 
        *arr = (int*)realloc(reduced_arr, new_size* sizeof(int));
    }
}