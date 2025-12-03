#include <stdio.h>
#include <string.h>
char *find_max(char *t);

char *find_max(char *t) {
    char *max_word = NULL;
    int max_len = 0;
    char *word = strtok(t, " ,.");
    while (word != NULL) {
        int len = strlen(word);
        if (len > max_len){
            max_len = len;
            max_word = word;
        }
        word = strtok(NULL, " ,.");
    }
    return max_word;
}
int main(void) {
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq";
    char *max_word = find_max(text);
    if (max_word != NULL) {
        printf("Самое длинное слово: %s\n", max_word);
        int len = strlen(max_word);
        char new_array[len + 1];
        for (int i = 0; i < len; i++) {
            new_array[i] = 'x';
        }
        new_array[len] = '\0';
        printf("Слово с заменой: %s\n", new_array);
    }
}