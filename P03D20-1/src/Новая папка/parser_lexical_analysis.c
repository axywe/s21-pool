int count_tokens = 0;
char** tokens = split(input, "+-*/()sctlx", &count_tokens);
printf("%s\n", input);
for (int i = 0; i < count_tokens; ++i) printf("%s,", tokens[i]);
for (int i = 0; i < count_tokens; ++i) free(tokens[i]);
free(tokens);
}

char** split(char* input, char* seperators, int* count) {
    int length = strlen(input);
    *count = 0;

    for (int i = 0; i < length;) {
        for (; i < length;) {
            if (strchr(seperators, input[i]) == NULL) break;
            long_separetors(input, &i);
        }
        int prev_i = i;
        for (; i < length;) {
            if (strchr(seperators, input[i]) != NULL) break;
            ++i;
        }
        if (i > prev_i) ++(*count);
    }

    char** tokens = malloc(sizeof(char*) * (*count));
    char buffer[1000];
    int token_count = 0;
    for (int i = 0; i < length;) {
        for (; i < length;) {
            if (strchr(seperators, input[i]) == NULL) break;
            long_separetors(input, &i);
        }
        int j = 0;
        for (; i < length;) {
            if (strchr(seperators, input[i]) != NULL) break;
            buffer[j] = input[i];
            ++i;
            ++j;
        }
        if (j > 0) {
            buffer[j] = '\0';
            tokens[token_count] = malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(tokens[token_count], buffer);
            ++token_count;
        }
    }
    return tokens;
}
