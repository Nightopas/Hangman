#include "HangWordCheck.h"
#include "HangFileRead.h"
#include <stdio.h>
#include <string.h>

int hang_word_check(HangLetter *game_word, char user_input)
{
    int result = -1;
    if (game_word == NULL) {
        printf("ERROR GAME_WORD IS NULL!\n");
        return result;
    }
    int i = 0;
    while (game_word[i].h_letter) {
        if (user_input == game_word[i].h_letter) {
            game_word[i].h_flag = 1;
            result = 0;
        }
        i++;
    }
    if (result == 0) {
        return result;
    } else {
        result = 1;
        return result;
    }
}
