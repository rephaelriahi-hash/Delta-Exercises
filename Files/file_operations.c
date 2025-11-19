/*------------------------------------------------------
* Filename: file_operations.c
* Description: the program gets a file and applys to it the functions below
*Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SOURCE_FILE "bla.txt"
#define TARGET_FILE "hi.txt"
#define TMP_FILE "tmp.txt"
#define STRING_TO_FIND "Hello"

void print_txt(char* file_name);
void cpy_file(char *source_file, char *target_file);
void print_stats(char* file_name);
void delete_line(char* file_name,int line);
int find_string(char* file_name,char* string);

int main() {
    print_txt(SOURCE_FILE);
    cpy_file(SOURCE_FILE,TARGET_FILE);
    print_stats(SOURCE_FILE);
    delete_line(TARGET_FILE,2);
    printf("Number the string appears: %d\n",find_string(SOURCE_FILE,STRING_TO_FIND));
    return 0;
}

/*------------------------------------------------------
* Function Name - print_txt
*
* Function Purpose - opens a file and prints its content
*
* Parameters –  file_name - the name of the file to print
*
* Return Values - void
*
* Author - Rephael Riahi
-------------------------------------------------------*/

void print_txt(char* file_name){
    FILE* fptr;
    char buffer = '\0';
    fptr = fopen(file_name,"r");
    if (fptr == NULL) {
        printf("The file is not opened.");
    }else{
        buffer = fgetc(fptr);
        while(buffer != EOF){
            printf("%c",buffer);
            buffer = fgetc(fptr);
        }
        printf("\n");
    }
    fclose(fptr);
}

/*------------------------------------------------------
* Function Name - cpy_file
*
* Function Purpose - opens a file and write its content into another
*
* Parameters –  source_file - the name of the source file 
*               target_file - the name of the target file 
*
* Return Values - void
*
* Author - Rephael Riahi
-------------------------------------------------------*/

void cpy_file(char *source_file, char *target_file){
    FILE *r_fptr, *w_fptr;
    char buffer = '\0';
    r_fptr = fopen(source_file,"r");
    w_fptr = fopen(target_file,"w");

    if (r_fptr == NULL || w_fptr == NULL) {
        printf("one of the files is not opened.");
    }else{
        buffer = fgetc(r_fptr);
        while(buffer != EOF){
            fputc(buffer,w_fptr);
            buffer = fgetc(r_fptr);
        }
    }
    fclose(r_fptr);
    fclose(w_fptr);
}

/*------------------------------------------------------
* Function Name - print_stats
*
* Function Purpose - opens a file and write its statistics
*
* Parameters –  source_file - the name of the source file 
*
* Return Values - void
*
* Author - Rephael Riahi
-------------------------------------------------------*/

void print_stats(char* file_name){
    FILE* fptr;
    int lines = 1, words = 1, letters = 0;
    //lines and words start with 1 because the last line ends with eof and not \n
    char buffer = '\0';
    fptr = fopen(file_name,"r");
    if (fptr == NULL) {
        printf("The file is not opened.");
    }else{
        buffer = fgetc(fptr);
        while(buffer != EOF){
            letters++;
            if(buffer == ' '){
                words++;
            }
            if(buffer == '\n'){
                lines++;
                words++;
            }
            buffer = fgetc(fptr);
        }
        printf("%d\n%d\n%d\n",lines,words,letters);
    }
    fclose(fptr);
}

/*------------------------------------------------------
* Function Name - delete_line
*
* Function Purpose - opens a file and delete one chosen line
*
* Parameters –  file_name - the name of the file 
*               line - the number of the line to delete
*
* Return Values - void
*
* Author - Rephael Riahi
-------------------------------------------------------*/

void delete_line(char* file_name,int line){
    
    char buffer = '\0';
    int lines = 1;//The numbers of lines starts by 1
    FILE *fptr1,*fptr2;
    cpy_file(file_name,TMP_FILE);
    fptr1 = fopen(file_name,"w");
    fptr2 = fopen(TMP_FILE,"r");
    if (fptr1 == NULL|| fptr2 == NULL) {
        printf("one of the files is not opened.1");
    }else{
        buffer = fgetc(fptr2);
        while(buffer != EOF){
            if(lines != line){
                fputc(buffer,fptr1);
            }
            if(buffer == '\n'){
                lines++;
            }
            buffer = fgetc(fptr2);
        }
    }
    fclose(fptr1);
    fclose(fptr2);
}

/*------------------------------------------------------
* Function Name - find_string
*
* Function Purpose - returns how many times a string appears in the file
*
* Parameters –  file_name - the name of the file 
*               string - the string to find
*
* Return Values - the number of times the string appears
*
* Author - Rephael Riahi
-------------------------------------------------------*/

int find_string(char* file_name,char* string){
    FILE *fptr;
    char buffer;
    int count = 0;
    int index = 0;
    int len = strlen(string);

    fptr = fopen(file_name,"r");
    if (fptr == NULL) {
        return -1;
    } else {
        while ((buffer = fgetc(fptr)) != EOF) {
            if (buffer == string[index]) {
                index++;
                if (index == len) {
                    count++;
                    index = 0;
                }
            } else {
                if (buffer == string[0]) {
                    index = 1;
                } else {
                    index = 0;
                }
            }
        }
    }
    fclose(fptr);
    return count;
}
