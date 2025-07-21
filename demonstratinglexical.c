#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[10][10] = {"int", "float", "if", "else", "while", "do", "return", "for", "char", "break"};

int isKeyword(char *word) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[100], word[20];
    int i = 0, j = 0;

    printf("Enter a line of code:\n");
    fgets(input, sizeof(input), stdin);

    printf("\n--- Lexical Analysis Result ---\n");

    while (input[i] != '\0') {
        // Skip whitespace
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Word (identifier or keyword)
        if (isalpha(input[i])) {
            j = 0;
            while (isalnum(input[i])) {
                word[j++] = input[i++];
            }
            word[j] = '\0';

            if (isKeyword(word))
                printf("Keyword: %s\n", word);
            else
                printf("Identifier: %s\n", word);
        }
        // Number
        else if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i])) {
                word[j++] = input[i++];
            }
            word[j] = '\0';
            printf("Number: %s\n", word);
        }
        // Operator
        else if (strchr("+-*/=<>", input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
        }
        // Special character or punctuation
        else {
            printf("Special Character: %c\n", input[i]);
            i++;
        }
    }

    return 0;
}
