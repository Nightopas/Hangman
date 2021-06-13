#include "HangRandWord.h"
#include "HangWordStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

HangLetter *hangman_get_randomized_word(char **word_array, int word_count)
{
    if (word_array == NULL) {
        return NULL;
    }
    srand(time(NULL));
    int word_number = rand() % word_count;
    if (word_array[word_number] == NULL) {
        return NULL;
    }
    int word_length = strlen(word_array[word_number]) - 1;
    HangLetter *randomized_word
            = (HangLetter *)malloc(sizeof(HangLetter) * word_length);
    int i = 0;
    for (i = 0; i < word_length; i++) {
        randomized_word[i].h_letter = word_array[word_number][i];
        randomized_word[i].h_flag = 0;
    }
    randomized_word[i].h_letter = '\0';
    return randomized_word;
}
