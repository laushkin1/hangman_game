#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "hangman.h"
#include "string.h"


int main(){

    char secret[30];
    srand(time(NULL));
    get_word(secret);
    hangman("secret");

    return 0;
}
