#include "HangGrammarCheck.h"
#include <stdio.h>
#include <string.h>

int grammar_check(char user_input)
{
    if ((user_input < 'a') || (user_input > 'z')) {
        printf("ERROR! WRONG TYPE OF INPUT! PLEASE ENTER A LETTER IN LOWER "
               "CASE ENGLISH FORMAT!\n");
        return -1;
    } else {
        return 0;
    }
}
