#include "HangGrammarCheck.h"
#include <stdio.h>
#include <string.h>

int grammar_check(char user_input)
{
    if (strlen(user_input) > 1) {
        printf("ERROR! MORE THAN ONE LETTER! PLEASE ENTER ONLY ONE LETTER AT "
               "TIME!");
        return -1;
    }
    if ((user_input < 'a') || (user_input > 'z')) {
        printf("ERROR! WRONG TYPE OF INPUT! PLEASE ENTER A LETTER IN LOWER "
               "CASE ENGLISH FORMAT!");
        return -1;
    } else {
        return 0;
    }
}
