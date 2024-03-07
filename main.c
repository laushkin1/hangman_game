#include <time.h>
#include <stdio.h>

#include <stdlib.h>
#include <ctype.h>
#include "hangman.h"

#include "morse.h"


//#include "morse.c"
//#include "hangman.c"
#include "string.h"

int main(){

    char secret[30];
    srand(time(NULL));
    get_word(secret);
    hangman(secret);

    char morse_code[] = ".... . .-.. .-.. ---";
    char res[150];
    char res1[150];
    if (is_morse_code_valid(morse_code)){
        morse_to_text(morse_code, res);
        printf("Morse code '%s' mean: %s\n", morse_code, res);

    } else{
        printf("Morse code '%s' is invaide\n", morse_code);
    }

    char h[] = "Hello";
    text_to_morse(h, res1);
    printf("'%s' to morze: %s\n",h,  res1);
    return 0;
}
