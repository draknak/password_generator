/*
* Simple command line password generator
* Generates a random char array depending
* Len is determined either from user input or random number
*
* Author: Joe Thorpe
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate(int);
int random_number(int, int);

int main(int argc, char *argv[]) {

    int len;
    char *password;
    srand(time(NULL));
    //could make this a switch instead
    if (argc > 2) {
        printf("Useage: ./pswd_gen <len_of_pswd>\n");
        return 1;
    } else if (argc == 2) {
        //generates password as len supplied
        len = atoi(argv[1]);
        generate(len);
    } else {
        //generates randon len password
        len = random_number(10,20);
        generate(len);
    }
    printf("\n");
    return 0; 
}

void generate(int len) {
    char *password = (char *) malloc(len * sizeof(char));
    char val;
    for (int i = 0; i < len; i++) {
        val = random_number(48,122); 
        *(password + i) = val;
        printf("%c", password[i]);
    }
    free(password);
}

int random_number(int min, int max) {
    int num;
    num = rand()%(max-min)+min;
    return num;
}