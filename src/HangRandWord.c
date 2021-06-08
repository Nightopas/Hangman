#include "HangRandWord.h"
#include "HangWordStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

HangLetter *hangman_get_randomized_word(char **word_array, int word_count)
{
    if (word_array == NULL) {
        printf("ERROR WORD_ARRAY POINTER IS NULL!");
        return NULL;
    }
    srand(time(NULL));
    int word_number = rand() % word_count;
    if (word_array[word_number] == NULL) {
        printf("ERROR WORD POINTER IS NULL OR WORD_NUMBER IS OUT OF BOUNDS!");
        return NULL;
    }
    int word_length = strlen(word_array[word_number]);
    HangLetter *randomized_word
            = (HangLetter *)malloc(sizeof(HangLetter) * word_length);
    for (int i = 0; i < word_length; i++) {
        randomized_word[i].h_letter = word_array[word_number][i];
        randomized_word[i].h_flag = 0;
    }
    return randomized_word;
}
