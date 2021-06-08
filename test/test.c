#define CTEST_MAIN

#include "HangConsoleDraw.h"
#include <ctest.h>

void test_hangman_draw_console()
{
    for (int i = 0; i < 8; i++) {
        system("clear");
        hangman_draw_console(i);
    }
    system("clear");
}

int main(int argc, const char** argv)
{
    test_hangman_draw_console();
    return ctest_main(argc, argv);
}
