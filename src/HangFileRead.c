#include "HangFileRead.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

char **read_file(char *file_path, int max_word_length)
{
    int lines_count = 0;
    FILE *pointer_hangman_text_file = fopen(file_path, "rb");
    if (pointer_hangman_text_file == NULL) {
        printf("FOPEN ERROR\n");
        return NULL;
    }
    while (!feof(pointer_hangman_text_file)) {
        if (fgetc(pointer_hangman_text_file) == '\n')
            lines_count++;
    }
    fclose(pointer_hangman_text_file);
    pointer_hangman_text_file = fopen(file_path, "rb");
    if (pointer_hangman_text_file == NULL) {
        printf("FOPEN ERROR\n");
        return NULL;
    }
    char **hang_word_array;
    hang_word_array = (char **)malloc(lines_count * sizeof(char *));
    for (int i = 0; i < lines_count; i++) {
        hang_word_array[i] = (char *)malloc(sizeof(char) * max_word_length);
        fgets(hang_word_array[i], max_word_length, pointer_hangman_text_file);
    }
    fclose(pointer_hangman_text_file);
    return hang_word_array;
}
