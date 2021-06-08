#include "HangWordCheck.h"
#include "HangFileRead.h"
#include "HangWordStruct.h"
#include <stdio.h>
#include <string.h>

int hang_word_check(HangLetter *game_word, char user_input)
{
    if (game_word == NULL) {
        printf("ERROR GAME_WORD IS NULL!\n");
        return -1;
    }
    int i = 0;
    while (game_word[i].h_letter) {
        if (user_input == game_word[i].h_letter) {
            game_word[i].h_flag = 1;
        }
        i++;
    }
    return 0;
}
