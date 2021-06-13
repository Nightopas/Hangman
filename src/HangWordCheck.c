#include "HangWordCheck.h"
#include "HangFileRead.h"
#include <stdio.h>
#include <string.h>

int hang_word_check(HangLetter *game_word, char user_input)
{
    int result = 1;
    if (game_word == NULL) {
        return -1;
    }
    int i = 0;
    while (game_word[i].h_letter) {
        if (user_input == game_word[i].h_letter) {
            game_word[i].h_flag = 1;
            result = 0;
        }
        i++;
    }
    return result;
}
