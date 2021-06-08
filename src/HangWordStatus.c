#include "HangWordStatus.h"
#include <stdio.h>

int draw_hang_word_status(HangLetter *game_word)
{
    if (game_word == NULL) {
        printf("ERROR! GAME_WORD IS NULL!\n");
        return -1;
    }
    int i = 0;
    while (game_word[i].h_letter) {
        if (game_word[i].h_flag == 0) {
            printf("_ ");
        } else if (game_word[i].h_flag == 1) {
            printf("%c ", game_word[i].h_letter);
        } else {
            printf("ERROR! GAME_WORD %d LETTER HAS WRONG FLAG!\n", i + 1);
            return -1;
        }
        i++;
    }
    printf("\n");
    return 0;
}
