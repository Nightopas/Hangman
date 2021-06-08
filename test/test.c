#define CTEST_MAIN

#include "HangConsoleDraw.h"
#include "HangFileRead.h"
#include "HangWordStruct.h"
#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(filenametest, Emptyfilename)
{
    char *filename = "";
    ASSERT_NULL(read_file(filename, 10));
}

void test_hangman_draw_console()
{
    for (int i = 0; i < 8; i++) {
        system("clear");
        hangman_draw_console(i);
    }
    system("clear");
}

int main(int argc, const char **argv)
{
    test_hangman_draw_console();
    return ctest_main(argc, argv);
}
