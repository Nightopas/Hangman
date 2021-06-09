#include "HangFileRead.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

char **read_file(char *file_path, int max_word_length)
{
    max_word_length += 1;
    int lines_count = 0;
    FILE *pointer_hangman_text_file = fopen(file_path, "rb");
    if (pointer_hangman_text_file == NULL) {
        printf("FOPEN ERROR\n");
        return NULL;
    }
    char *current_char = (char *)malloc(sizeof(char) * 2);
    while ((!feof(pointer_hangman_text_file))
           && (!ferror(pointer_hangman_text_file))) {
        *current_char
                = fgetc(pointer_hangman_text_file); // malloc(): invalid next
                                                    // size (unsorted)
        if (*current_char == '\n') {
            lines_count++;
        }
    }
    fseek(pointer_hangman_text_file, 0, SEEK_SET);
    char **hang_word_array;
    hang_word_array = (char **)malloc(lines_count * sizeof(char *));
    for (int i = 0; i < lines_count; i++) {
        hang_word_array[i] = (char *)malloc(sizeof(char) * max_word_length);
        fgets(hang_word_array[i], max_word_length, pointer_hangman_text_file);
    }
    fclose(pointer_hangman_text_file);
    return hang_word_array;
}
