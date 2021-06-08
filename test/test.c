#define CTEST_MAIN

#include "HangConsoleDraw.h"
#include "HangFileRead.h"
#include "HangRandWord.h"
#include "HangWordCheck.h"
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

CTEST(gamewordtest, Wrongguess)
{
    HangLetter *test_word = (HangLetter *)malloc(sizeof(HangLetter) * 6);
    test_word[0].h_letter = 'a';
    test_word[1].h_letter = 'a';
    test_word[2].h_letter = 'a';
    test_word[3].h_letter = 'a';
    test_word[4].h_letter = 'a';
    test_word[5].h_letter = 'a';
    ASSERT_EQUAL(1, hang_word_check(test_word, 'b'));
}

CTEST(gamewordtest, Rightguess)
{
    HangLetter *test_word = (HangLetter *)malloc(sizeof(HangLetter) * 6);
    test_word[0].h_letter = 'a';
    test_word[1].h_letter = 'a';
    test_word[2].h_letter = 'a';
    test_word[3].h_letter = 'a';
    test_word[4].h_letter = 'a';
    test_word[5].h_letter = 'a';
    ASSERT_EQUAL(0, hang_word_check(test_word, 'a'));
}

CTEST(gamewordtest, Rightguessflag1)
{
    int word_length = 6;
    HangLetter *test_word
            = (HangLetter *)malloc(sizeof(HangLetter) * word_length);
    test_word[0].h_letter = 'a';
    test_word[1].h_letter = 'a';
    test_word[2].h_letter = 'a';
    test_word[3].h_letter = 'a';
    test_word[4].h_letter = 'a';
    test_word[5].h_letter = 'a';
    hang_word_check(test_word, 'a');
    for (int i = 0; i < word_length; i++) {
        ASSERT_EQUAL(1, test_word[i].h_flag);
    }
}

CTEST(gamewordtest, Rightguessflag2)
{
    int word_length = 6;
    HangLetter *test_word
            = (HangLetter *)malloc(sizeof(HangLetter) * word_length);
    test_word[0].h_letter = 'a';
    test_word[1].h_letter = 'b';
    test_word[2].h_letter = 'a';
    test_word[3].h_letter = 'c';
    test_word[4].h_letter = 'a';
    test_word[5].h_letter = 'z';
    hang_word_check(test_word, 'a');
    for (int i = 0; i < word_length; i += 2) {
        ASSERT_EQUAL(1, test_word[i].h_flag);
    }
    for (int i = 1; i < word_length; i += 2) {
        ASSERT_EQUAL(0, test_word[i].h_flag);
    }
}

CTEST(gamewordtest, Emptyword)
{
    HangLetter *test_word = NULL;
    ASSERT_EQUAL(-1, hang_word_check(test_word, 'a'));
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
