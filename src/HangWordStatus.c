#include "HangWordStatus.h"
#include <stdio.h>

int draw_hang_word_status(HangLetter *game_word)
{
    if (game_word == NULL) {
        return -1;
    }
    int win_flag = 1;
    int i = 0;
    while (game_word[i].h_letter) {
        if (game_word[i].h_flag == 0) {
            win_flag = 0;
            printf("_ ");
        } else if (game_word[i].h_flag == 1) {
            printf("%c ", game_word[i].h_letter);
        } else {
            return -1;
        }
        i++;
    }
    printf("\n");
    return win_flag;
}
