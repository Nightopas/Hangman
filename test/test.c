#define CTEST_MAIN

#include "HangConsoleDraw.h"
#include "HangFileRead.h"
#include "HangGrammarCheck.h"
#include "HangRandWord.h"
#include "HangWordStruct.h"
#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(filenametest, Emptyfilename)
{
    char *filename = "";
    ASSERT_NULL(read_file(filename, 10));
}

CTEST(randwordtest, Emptywordarray)
{
    int lines_count = 40;
    char *word_array = "NULL";
    ASSERT_NULL(hangman_get_randomized_word(
            read_file(word_array, 10), lines_count));
}

CTEST(randwordtest, Emptyword)
{
    int lines_count = 2;
    char **word_array = (char **)malloc(lines_count * sizeof(char *));
    word_array[0] = NULL;
    word_array[1] = NULL;
    ASSERT_NULL(hangman_get_randomized_word(word_array, lines_count));
}

CTEST(gramcheck, wrong_input1)
{
    for (int i = 0; i < 97; i++) {
        ASSERT_EQUAL(-1, grammar_check((char)i));
    }
}

CTEST(gramcheck, wrong_input2)
{
    for (int i = 123; i < 128; i++) {
        ASSERT_EQUAL(-1, grammar_check((char)i));
    }
}

CTEST(gramcheck, right_input)
{
    for (int i = 97; i < 123; i++) {
        ASSERT_EQUAL(0, grammar_check((char)i));
    }
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
