char** letterCombinations(char* digits, int* returnSize) {
    // Define the mapping of digits to letters.
    char* mappings[] = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    // If the input is empty, return an empty result.
    if (digits == NULL || *digits == '\0') {
        *returnSize = 0;
        return NULL;
    }

    int len = strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Calculate the number of combinations.
    int combinations = 1;
    for (int i = 0; i < len; i++) {
        int digit = digits[i] - '2';
        combinations *= strlen(mappings[digit]);
    }

    // Allocate memory for the result.
    char** result = (char**)malloc(combinations * sizeof(char*));
    for (int i = 0; i < combinations; i++) {
        result[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    // Generate the combinations using nested loops with conditionals.
    int index = 0;
    for (int i = 0; i < strlen(mappings[digits[0] - '2']); i++) {
        if (len > 1) {
            for (int j = 0; j < strlen(mappings[digits[1] - '2']); j++) {
                if (len > 2) {
                    for (int k = 0; k < strlen(mappings[digits[2] - '2']); k++) {
                        if (len > 3) {
                            for (int l = 0; l < strlen(mappings[digits[3] - '2']); l++) {
                                result[index][0] = mappings[digits[0] - '2'][i];
                                result[index][1] = mappings[digits[1] - '2'][j];
                                result[index][2] = mappings[digits[2] - '2'][k];
                                result[index][3] = mappings[digits[3] - '2'][l];
                                result[index][4] = '\0';
                                index++;
                            }
                        } else {
                            result[index][0] = mappings[digits[0] - '2'][i];
                            result[index][1] = mappings[digits[1] - '2'][j];
                            result[index][2] = mappings[digits[2] - '2'][k];
                            result[index][3] = '\0';
                            index++;
                        }
                    }
                } else {
                    result[index][0] = mappings[digits[0] - '2'][i];
                    result[index][1] = mappings[digits[1] - '2'][j];
                    result[index][2] = '\0';
                    index++;
                }
            }
        } else {
            result[index][0] = mappings[digits[0] - '2'][i];
            result[index][1] = '\0';
            index++;
        }
    }

    *returnSize = combinations;
    return result;
}
