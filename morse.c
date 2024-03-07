#include <string.h>
#include <stdio.h>
#include "morse.h"


void text_to_morse(const char text[], char output[]) {

    char text_[150];

    for (int i = 0; i < strlen(text); i++){
        if ('a' <= text[i] && text[i] <= 'z') {
            text_[i] = (text[i] + 'A' - 'a');
        } else{
            text_[i] = text[i];
        }
    }
    text_[strlen(text)] = '\0';
    output[0] = '\0';

    for (int i=0; i<strlen(text_); i++){
        if (text_[i] == 'A'){
            strcat(output, ".-");
            strcat(output, " ");
        } else if (text_[i] == 'B'){
            strcat(output, "-...");
            strcat(output, " ");
        } else if (text_[i] == 'C'){
            strcat(output, "-.-.");
            strcat(output, " ");
        } else if (text_[i] == 'D'){
            strcat(output, "-..");
            strcat(output, " ");
        } else if (text_[i] == 'E'){
            strcat(output, ".");
            strcat(output, " ");
        } else if (text_[i] == 'F'){
            strcat(output, "..-.");
            strcat(output, " ");
        } else if (text_[i] == 'G'){
            strcat(output, "--.");
            strcat(output, " ");
        } else if (text_[i] == 'H'){
            strcat(output, "....");
            strcat(output, " ");
        } else if (text_[i] == 'I'){
            strcat(output, "..");
            strcat(output, " ");
        } else if (text_[i] == 'J'){
            strcat(output, ".---");
            strcat(output, " ");
        } else if (text_[i] == 'K'){
            strcat(output, "-.-");
            strcat(output, " ");
        } else if (text_[i] == 'L'){
            strcat(output, ".-..");
            strcat(output, " ");
        } else if (text_[i] == 'M'){
            strcat(output, "--");
            strcat(output, " ");
        } else if (text_[i] == 'N'){
            strcat(output, "-.");
            strcat(output, " ");
        } else if (text_[i] == 'O'){
            strcat(output, "---");
            strcat(output, " ");
        } else if (text_[i] == 'P'){
            strcat(output, ".--.");
            strcat(output, " ");
        } else if (text_[i] == 'Q'){
            strcat(output, "--.-");
            strcat(output, " ");
        } else if (text_[i] == 'R'){
            strcat(output, ".-.");
            strcat(output, " ");
        } else if (text_[i] == 'S'){
            strcat(output, "...");
            strcat(output, " ");
        } else if (text_[i] == 'T'){
            strcat(output, "-");
            strcat(output, " ");
        } else if (text_[i] == 'U'){
            strcat(output, "..-");
            strcat(output, " ");
        } else if (text_[i] == 'V'){
            strcat(output, "...-");
            strcat(output, " ");
        } else if (text_[i] == 'W'){
            strcat(output, ".--");
            strcat(output, " ");
        } else if (text_[i] == 'X'){
            strcat(output, "-..-");
            strcat(output, " ");
        } else if (text_[i] == 'Y'){
            strcat(output, "-.--");
            strcat(output, " ");
        } else if (text_[i] == 'Z'){
            strcat(output, "--..");
            strcat(output, " ");
        } else if (text_[i] == '1'){
            strcat(output, ".----");
            strcat(output, " ");
        } else if (text_[i] == '2'){
            strcat(output, "..---");
            strcat(output, " ");
        } else if (text_[i] == '3'){
            strcat(output, "...--");
            strcat(output, " ");
        } else if (text_[i] == '4'){
            strcat(output, "....-");
            strcat(output, " ");
        } else if (text_[i] == '5'){
            strcat(output, ".....");
            strcat(output, " ");
        } else if (text_[i] == '6'){
            strcat(output, "-....");
            strcat(output, " ");
        } else if (text_[i] == '7'){
            strcat(output, "--...");
            strcat(output, " ");
        } else if (text_[i] == '8'){
            strcat(output, "---..");
            strcat(output, " ");
        } else if (text_[i] == '9'){
            strcat(output, "----.");
            strcat(output, " ");
        } else if (text_[i] == '0'){
            strcat(output, "-----");
            strcat(output, " ");
        }
    }
    output[strlen(output)-1] = '\0';

}

void morse_to_text(const char morse[], char output[]){
    char space[] = " ";
    char *char_morse;
    char morse_[150];

    morse_[0] = '\0';
    strcat(morse_, morse);
    strcat(morse_, " ");


    output[0] = '\0';

    char_morse = strtok(morse_,space);
    while(char_morse != NULL){
        if (strcmp(char_morse, ".-")==0){
            strcat(output, "A");
        } else if (strcmp(char_morse, "-...")==0) {
            strcat(output, "B");
        } else if (strcmp(char_morse, "-.-.")==0) {
            strcat(output, "C");
        } else if (strcmp(char_morse, "-..")==0) {
            strcat(output, "D");
        } else if (strcmp(char_morse, ".")==0) {
            strcat(output, "E");
        } else if (strcmp(char_morse, "..-.")==0) {
            strcat(output, "F");
        } else if (strcmp(char_morse, "--.")==0) {
            strcat(output, "G");
        } else if (strcmp(char_morse, "....")==0) {
            strcat(output, "H");
        } else if (strcmp(char_morse, "..")==0) {
            strcat(output, "I");
        } else if (strcmp(char_morse, ".---")==0) {
            strcat(output, "J");
        } else if (strcmp(char_morse, "-.-")==0) {
            strcat(output, "K");
        } else if (strcmp(char_morse, ".-..")==0) {
            strcat(output, "L");
        } else if (strcmp(char_morse, "--")==0) {
            strcat(output, "M");
        } else if (strcmp(char_morse, "-.")==0) {
            strcat(output, "N");
        } else if (strcmp(char_morse, "---")==0) {
            strcat(output, "O");
        } else if (strcmp(char_morse, ".--.")==0) {
            strcat(output, "P");
        } else if (strcmp(char_morse, "--.-")==0) {
            strcat(output, "Q");
        } else if (strcmp(char_morse, ".-.")==0) {
            strcat(output, "R");
        } else if (strcmp(char_morse, "...")==0) {
            strcat(output, "S");
        } else if (strcmp(char_morse, "-")==0) {
            strcat(output, "T");
        } else if (strcmp(char_morse, "..-")==0) {
            strcat(output, "U");
        } else if (strcmp(char_morse, "...-")==0) {
            strcat(output, "V");
        } else if (strcmp(char_morse, ".--")==0) {
            strcat(output, "W");
        } else if (strcmp(char_morse, "-..-")==0) {
            strcat(output, "X");
        } else if (strcmp(char_morse, "-.--")==0) {
            strcat(output, "Y");
        } else if (strcmp(char_morse, "--..")==0) {
            strcat(output, "Z");
        } else if (strcmp(char_morse, ".----")==0) {
            strcat(output, "1");
        } else if (strcmp(char_morse, "..---")==0) {
            strcat(output, "2");
        } else if (strcmp(char_morse, "...--")==0) {
            strcat(output, "3");
        } else if (strcmp(char_morse, "....-")==0) {
            strcat(output, "4");
        } else if (strcmp(char_morse, ".....")==0) {
            strcat(output, "5");
        } else if (strcmp(char_morse, "-....")==0) {
            strcat(output, "6");
        } else if (strcmp(char_morse, "--...")==0) {
            strcat(output, "7");
        } else if (strcmp(char_morse, "---..")==0) {
            strcat(output, "8");
        } else if (strcmp(char_morse, "----.")==0) {
            strcat(output, "9");
        } else if (strcmp(char_morse, "-----")==0) {
            strcat(output, "0");
        }
        char_morse = strtok (NULL,space);
    }
}

int is_morse_code_valid(const char morse[]){
    char space[10] = " ";
    char *char_morse;
    char morse_[150];

    if(strlen(morse)<1){
        return 1;
    }


    for (int i = 0; i < strlen(morse); i++){
        morse_[i] = morse[i];
    }
    morse_[strlen(morse)] = '\0';

    char_morse = strtok (morse_,space);
    while(char_morse != NULL) {
        for (int i=0; i< strlen(char_morse); i++){
            if (char_morse[i] != '-' && char_morse[i] != '.'){
                char_morse[i] = '\0';
                break;
            }
        }

        if (strcmp(char_morse, ".-")==0){
            ;
        } else if (strcmp(char_morse, "-...")==0) {
            ;
        } else if (strcmp(char_morse, "-.-.")==0) {
            ;
        } else if (strcmp(char_morse, "-..")==0) {
            ;
        } else if (strcmp(char_morse, ".")==0) {
            ;
        } else if (strcmp(char_morse, "..-.")==0) {
            ;
        } else if (strcmp(char_morse, "--.")==0) {
            ;
        } else if (strcmp(char_morse, "....")==0) {
            ;
        } else if (strcmp(char_morse, "..")==0) {
            ;
        } else if (strcmp(char_morse, ".---")==0) {
            ;
        } else if (strcmp(char_morse, "-.-")==0) {
            ;
        } else if (strcmp(char_morse, ".-..")==0) {
            ;
        } else if (strcmp(char_morse, "--")==0) {
            ;
        } else if (strcmp(char_morse, "-.")==0) {
            ;
        } else if (strcmp(char_morse, "---")==0) {
            ;
        } else if (strcmp(char_morse, ".--.")==0) {
            ;
        } else if (strcmp(char_morse, "--.-")==0) {
            ;
        } else if (strcmp(char_morse, ".-.")==0) {
            ;
        } else if (strcmp(char_morse, "...")==0) {
            ;
        } else if (strcmp(char_morse, "-")==0) {
            ;
        } else if (strcmp(char_morse, "..-")==0) {
            ;
        } else if (strcmp(char_morse, "...-")==0) {
            ;
        } else if (strcmp(char_morse, ".--")==0) {
            ;
        } else if (strcmp(char_morse, "-..-")==0) {
            ;
        } else if (strcmp(char_morse, "-.--")==0) {
            ;
        } else if (strcmp(char_morse, "--..")==0) {
            ;
        } else if (strcmp(char_morse, ".----")==0) {
            ;
        } else if (strcmp(char_morse, "..---")==0) {
            ;
        } else if (strcmp(char_morse, "...--")==0) {
            ;
        } else if (strcmp(char_morse, "....-")==0) {
            ;
        } else if (strcmp(char_morse, ".....")==0) {
            ;
        } else if (strcmp(char_morse, "-....")==0) {
            ;
        } else if (strcmp(char_morse, "--...")==0) {
            ;
        } else if (strcmp(char_morse, "---..")==0) {
            ;
        } else if (strcmp(char_morse, "----.")==0) {
            ;
        } else if (strcmp(char_morse, "-----")==0) {
            ;
        } else {
            return 0;
        }
        char_morse = strtok (NULL,space);
    }
    return 1;
}