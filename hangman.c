#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include "hangman.h"


int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}


int is_word_guessed(const char secret[], const char letters_guessed[]){
    int i;
    int i1;
    int len_secret = strlen(secret);
    char secret_[len_secret];

    for (i=0; i<strlen(letters_guessed); i++){
        for(i1=0; i1<strlen(secret); i1++){
            if(letters_guessed[i] == secret[i1]){
                secret_[i1] = secret[i1];
            }
        }
    }
    secret_[len_secret] = '\0';

    if(strcmp(secret, secret_) == 0){
        return 1;
    }
    return 0;
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
    int i;
    int i1;

    guessed_word[strlen(secret)] = '\0';
    for(i=0; i< strlen(secret); i++){
        guessed_word[i] = '_';
    }

    for (i=0; i<strlen(letters_guessed); i++){
        for(i1=0; i1<strlen(secret); i1++){
            if(letters_guessed[i] == secret[i1]){
                guessed_word[i1] = secret[i1];
            }
        }
    }
}


void get_available_letters(const char letters_guessed[], char available_letters[]){
    available_letters[0] = '\0';
    int i;
    int i1;
    int i2;
    char letters[] = "abcdefghijklmnopqrstuvwxyz";

    for (i=0; i<strlen(letters_guessed); i++){
        for(i1=0; i1<strlen(letters); i1++){
            if(letters_guessed[i] == letters[i1]){
                // remove char {i1}
                for (i2 = i1; i2 < strlen(letters); i2++){
                    letters[i2] = letters[i2+1];
                }
            }
        }
    }
    strcat(available_letters, letters);
    printf("%s\n", available_letters);
}

void hangman(const char secret[]){
    int attempt = 8;
    char input[30] = "";
    char value[30];
    char result[30];
    char letters[30] = "";
    char outputpr[30];


    result[0] = '\0';

    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %lu letters long.\n", strlen(secret));
    printf("-------------\n");

    while (attempt){
        outputpr[0] = '\0';
        int is_flag = 1;
        int is_letter_flag = 0;

        printf("You have %d guesses left.\n", attempt);
        printf("Available letters: ");
        get_available_letters(input, letters);
        printf("Please guess a letter: ");
        scanf("%s", value);

        for (int i=0; i< strlen(value); i++){
            if ('A' <= value[i] && value[i] <= 'Z') {
                value[i] = (value[i] + 'a' - 'A');
            }
        }

        if(strcmp(value, secret) == 0){
            printf("Congratulations, you won!\n");
            break;
        }

        value[1] = '\0';

        if (strchr("abcdefghijklmnopqrstuvwxyz", *value) == NULL){
            get_guessed_word(secret, input, result);

            result[strlen(secret)] = '\0';


            for (int i = 0; i < strlen(result); i++){
                char resi[] = {result[i], '\0'};
                strcat(outputpr, resi);
                strcat(outputpr, " ");
            }

            outputpr[strlen(outputpr)-1] = '\0';
            printf("Oops! '%c' is not a valid letter: %s\n", *value, outputpr);

            is_flag = 0;
        } else {


            if (strchr(input, value[0]) == NULL) {
                strcat(input, value);
            } else {
                is_letter_flag = 1;
            }


            for (int i = 0; i < strlen(secret); i++) {
                if (secret[i] == *value) {
                    is_flag = 0;
                }
            }

            if (is_flag) {
                if (is_letter_flag) {
                    get_guessed_word(secret, input, result);

                    result[strlen(secret)] = '\0';

                    for (int i = 0; i < strlen(result); i++){
                        char resi[] = {result[i], '\0'};
                        strcat(outputpr, resi);
                        strcat(outputpr, " ");
                    }

                    outputpr[strlen(outputpr)-1] = '\0';

                    printf("Oops! You've already guessed that letter: %s\n", outputpr);
                } else {
                    get_guessed_word(secret, input, result);

                    result[strlen(secret)] = '\0';

                    for (int i = 0; i < strlen(result); i++){
                        char resi[] = {result[i], '\0'};
                        strcat(outputpr, resi);
                        strcat(outputpr, " ");
                    }

                    outputpr[strlen(outputpr)-1] = '\0';

                    printf("Oops! That letter is not in my word: %s\n", outputpr);
                }
            } else {
                if (is_letter_flag) {
                    get_guessed_word(secret, input, result);

                    result[strlen(secret)] = '\0';

                    for (int i = 0; i < strlen(result); i++){
                        char resi[] = {result[i], '\0'};
                        strcat(outputpr, resi);
                        strcat(outputpr, " ");
                    }

                    outputpr[strlen(outputpr)-1] = '\0';

                    printf("Oops! You've already guessed that letter: %s\n", outputpr);
                } else {
                    get_guessed_word(secret, input, result);

                    result[strlen(secret)] = '\0';

                    for (int i = 0; i < (strlen(result)+1); i++){
                        char resi[] = {result[i], '\0'};
                        strcat(outputpr, resi);
                        strcat(outputpr, " ");
                    }

                    outputpr[strlen(outputpr)-2] = '\0';

                    printf("Good guess: %s\n", outputpr);
                }
            }
        }

        printf("-------------\n");

        if(is_word_guessed(secret, input)){
            printf("Congratulations, you won!\n");
            break;
        }

        if(is_flag){
            if (!is_letter_flag){
                attempt--;
            }

        }

        if (attempt == 0){
            printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
            break;
        }
    }
}