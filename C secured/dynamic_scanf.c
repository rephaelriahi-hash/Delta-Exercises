/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: the program gets a string from the user and prints it
* Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_BUFFER  21 //20 character + \0
#define END_OF_INPUT(c) ((c) == '\n' || (c) == EOF || (c) == '\0')

char* dyn_scanf(void);

int main() {
    char *str = dyn_scanf();
    printf_s("%s\n",str);
    free(str);
    return 0;
}

/*------------------------------------------------------
* Function Name - dyn_scanf
*
* Function Purpose - creates an array of char in the size of the user's input and gets a string from the user
*
* Parameters –  void
*
* Return Values - the user's input
*
* Author - Rephael Riahi
-------------------------------------------------------*/

char* dyn_scanf(void){
    int ch_input = 0;
    char *input = (char*)malloc(DEFAULT_BUFFER * sizeof(char));
    int counter = 0;
    memset(input,'\0',DEFAULT_BUFFER);
    ch_input = fgetc(stdin);
    do{
        int i = 0;
        for(;i < (DEFAULT_BUFFER - 1) && !END_OF_INPUT(ch_input) ;i++){//BUFFER_size - 1 to keep place for '\0'
            *(input + counter++) = ch_input;
            ch_input = fgetc(stdin);
        }
        if(!END_OF_INPUT(ch_input)){
            char *tmp = (char*)realloc(input,(counter + 1) * sizeof(char));
            if (!tmp) {
                free(input);
                return NULL;
            }
            input = (char*)malloc((DEFAULT_BUFFER + counter) * sizeof(char));
            memset(input,'\0',(DEFAULT_BUFFER + counter));
            memcpy(input,tmp,(counter));
            free(tmp);
        }else if(i ==(DEFAULT_BUFFER - 1) ){
            input = (char*)realloc(input,(counter + 1) * sizeof(char));
        }
        }while(!END_OF_INPUT(ch_input));
    return input;
}

