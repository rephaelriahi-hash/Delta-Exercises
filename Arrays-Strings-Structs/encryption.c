/*------------------------------------------------------
* Filename: encryption.c
* Description: The program gets an array of 26 integers hiding a message, and prints the decoded message.
* Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>

#define LEFT 0
#define RIGHT 1

void circular_cell_movement (int array_to_move[], int arr_size, int num_of_movments, int side_to_move);

int main() {
    int coded_msg [26] = {0};
    char decoded_msg [27] = {'\0'};
    printf("Dear Smurf please enter your coded message: \n");
    for(int i = 0; i < 26; i++){
        scanf("%d",&coded_msg[i]);
    }
    
    circular_cell_movement(coded_msg, 26, 13, LEFT);//switching the 2 halves

    for(int i = 1; i < 26; i++){
        coded_msg[i] -= coded_msg[i - 1]; 
    }

    circular_cell_movement(coded_msg, 26, 5, RIGHT);

    for(int i = 0; i < 26; i += 2){
        coded_msg[i] /= 7; 
    }

    circular_cell_movement(coded_msg, 26, 4, LEFT);

    for(int i = 0; i < 26; i++){
        coded_msg[i] -= 5; 
    }

    for(int i = 0; i < 26; i++){
        decoded_msg[i] = (char)coded_msg[i];
    } 
    printf("%s\n",decoded_msg);

    return 0;
}


/*-------------------------------------------------------
* Funtionname: circular_cell_movement
* Description: This function gets an array, its size, the number of cells to move, the side to move right = 1, left = 0.
* the function returns the array after the movements.
* Author: Rephael Riahi
-------------------------------------------------------*/
void circular_cell_movement (int array_to_move[], int arr_size, int num_of_movments, int side_to_move){
    int temp_arr[num_of_movments] = {};
    for(int i = 0; i < num_of_movments; i++){
        //if we move to the right we want to copy from the end to not erase the last elements
        //so we calculte the first of the last cells (arr_size - num_of_movments) and move from there by i
        //right = 1 so if we want to copy last elements it will keep the calculation
        //in left we just want the first elements so left = 0 then the calcultion won't work and we move just by i
        int cell_to_cpy = side_to_move * (arr_size - num_of_movments) + i;
        temp_arr[i] = array_to_move[cell_to_cpy];
    }

    if (side_to_move == LEFT){
        for(int i = 0; i < arr_size - num_of_movments; i++){
            array_to_move[i] = array_to_move[i + num_of_movments];
        }
        for(int i = 0;i < num_of_movments;i++){
            array_to_move[(arr_size - num_of_movments) + i] = temp_arr[i];
        }

    }else{//the -1 to calculate i is because the array starts at 0
        for(int i = arr_size - 1 ; i >= num_of_movments; i--){
            array_to_move[i] = array_to_move[i - num_of_movments];
        }
        for(int i = 0;i < num_of_movments; i++){
            array_to_move[i] = temp_arr[i];
        }
    }
}
