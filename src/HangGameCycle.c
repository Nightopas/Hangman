#include "HangGameCycle.h"
#include "HangConsoleDraw.h"
#include "HangGrammarCheck.h"
#include "HangWordCheck.h"
#include "HangWordStatus.h"
#include <stdio.h>
#include <stdlib.h>

int game_cycle(HangLetter *game_guess_word, int *game_state)
{
    if (game_guess_word == NULL) {
        printf("ERROR GAME_GUESS_WORD POINTER IS NULL!\n");
        return -1;
    }
    if (((*game_state) < 0) || ((*game_state) > 7)) {
        printf("ERROR GAME_STATE IS WRONG!\n");
        return -1;
    }
    char user_input;
    system("clear");
    hangman_draw_console(*game_state);
    if ((draw_hang_word_status(game_guess_word)) == 1) {
        return 1;
    }
    printf("\nPlease enter the letter:");
    scanf(" %c", &user_input);
    if (!(grammar_check(user_input))) {
        if ((hang_word_check(game_guess_word, user_input)) == 1) {
            *game_state += 1;
        }
    }
    printf("\n%d\n", *game_state);
    return 0;
}
