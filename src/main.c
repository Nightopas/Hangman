#include "HangConsoleDraw.h"
#include "HangFileRead.h"
#include "HangGameCycle.h"
#include "HangGrammarCheck.h"
#include "HangRandWord.h"
#include "HangWordCheck.h"
#include "HangWordStatus.h"
#include "HangWordStruct.h"
#include <stdio.h>
#include <stdlib.h>

HangLetter *word_initialization(char **word_array)
{
    HangLetter *rolled_word = hangman_get_randomized_word(word_array, 40);
    return rolled_word;
}

int main()
{
    char *text_file_path = "src/text/HangmanText";
    char **word_array = read_file(text_file_path, 10);
    int program_state = 1;
    while (program_state) {
        int game_state = 0;
        int game_result = 0;
        HangLetter *game_guess_word = word_initialization(word_array);
        while ((game_state >= 0) && (game_state < 7)) {
            game_result = game_cycle(game_guess_word, &game_state);
            if (game_result == 1) {
                break;
            }
        }
        system("clear");
        if (game_result == 0) {
            hangman_draw_console(game_state);
            printf("\nYOU LOSE!\n");
        } else if (game_result == 1) {
            hangman_draw_console(game_state);
            printf("\nCONGRATULATIONS!!!\n YOU WIN!\n");
        }
        printf("\nEXIT? y/n\n");
        char exit_input;
        scanf(" %c", &exit_input);
        while (program_state) {
            if (exit_input == 'y') {
                program_state = 0;
            } else if (exit_input == 'n') {
                break;
            } else {
                scanf(" %c", &exit_input);
            }
        }
    }
}
