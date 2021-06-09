#include "HangConsoleDraw.h"
#include <stdio.h>
#include <stdlib.h>

void hangman_draw_console(int game_state)
{
    if (game_state == 0) {
        printf("############\n");
        printf("############\n");
        printf("############\n");
        printf("############\n");
        printf("############\n");
        printf("############\n");
        printf("############\n");
        printf("############\n");
        printf("############\n");
    } else if (game_state == 1) {
        printf("##=========]\n");
        printf("##|########|\n");
        printf("##|########|\n");
        printf("##|########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("============\n");
    } else if (game_state == 2) {
        printf("##=========]\n");
        printf("##|########|\n");
        printf("##|########|\n");
        printf("##0########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("============\n");
    } else if (game_state == 3) {
        printf("##=========]\n");
        printf("##|########|\n");
        printf("##|########|\n");
        printf("##0########|\n");
        printf("##|########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("============\n");
    } else if (game_state == 4) {
        printf("##=========]\n");
        printf("##|########|\n");
        printf("##|########|\n");
        printf("##0########|\n");
        printf("#/|########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("============\n");
    } else if (game_state == 5) {
        printf("##=========]\n");
        printf("##|########|\n");
        printf("##|########|\n");
        printf("##0########|\n");
        printf("#/|\\#######|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("============\n");
    } else if (game_state == 6) {
        printf("##=========]\n");
        printf("##|########|\n");
        printf("##|########|\n");
        printf("##0########|\n");
        printf("#/|\\#######|\n");
        printf("#/#########|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("============\n");
    } else if (game_state == 7) {
        printf("##=========]\n");
        printf("##|########|\n");
        printf("##|########|\n");
        printf("##0########|\n");
        printf("#/|\\#######|\n");
        printf("#/#\\#######|\n");
        printf("###########|\n");
        printf("###########|\n");
        printf("============\n");
    } else {
        printf("\nGAME STATE IS WRONG!!!\n");
        return;
    }
}
