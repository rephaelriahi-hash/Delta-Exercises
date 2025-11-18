/*------------------------------------------------------
* Filename: print_value_addr.c
* Description: The program gets an array of integers and an array of characters and prints 
* the values and addresses of each
* Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>

#define ARRAY_SIZE 8

int main() {
    float input_int_check = 0;
    char input_ch_check = '\0';
    int *ptr = NULL;
    int arr_of_int [ARRAY_SIZE] = {0};
    char arr_of_ch [ARRAY_SIZE + 1] = {'\0'};
    
    printf("Enter the array of integers: \n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        if(scanf("%f", &input_int_check) != 1 || input_int_check - (int)input_int_check != 0){
            printf("Wrong input!");
            return 0;
        }
        *(arr_of_int + i) = (int)input_int_check;
    }

   printf("Enter the array of charaacters: \n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        scanf(" %c", &input_ch_check);
        if(input_ch_check >= 'A' && input_ch_check <= 'Z'||input_ch_check >= 'a' && input_ch_check <= 'z'){
        *(arr_of_ch + i) = input_ch_check;
        }else{
            printf("Wrong input!");
            return 0;
        }
    }

    printf("Array of integers printed with * \n");
    for(int i = 0, *ptr = arr_of_int; i < ARRAY_SIZE; i++){
        printf("value: %d address: %p\n",*(ptr + i),(ptr + i));
    }

    printf("\nArray of characters printed with [] \n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("value: %c address: %p\n",arr_of_ch[i],&arr_of_ch[i]);
    }
    return 0;
}

