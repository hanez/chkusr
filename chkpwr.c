/**
 * checkpwrule is a program that checks if an input string validates a
 * password rule.
 *
 * Author: Johannes Findeisen <you@hanez.org> - 2024
 * License: MIT (see LICENSE)
 */

#include "config.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Return 1 if non-ASCII characters are found, 0 if all are ASCII
int is_valid_ascii(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if ((unsigned char)str[i] > 127) {
            return 1; // Non-ASCII character detected, return 1 (indicating invalid)
        }
    }
    return 0; // All characters are ASCII
}

int is_valid(char *str) {
    int lowercase_count = 0, uppercase_count = 0, digit_count = 0, special_count = 0;
    int i;
    int length = strlen(str);

    // Check if the input contains any non-ASCII characters
    if (is_valid_ascii(str)) {
        printf("Password contains non-ASCII characters.\n");
        return 1; // Invalid input, return 1 to signal failure
    }

    // Check if the length is within the allowed range
    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password is too short! It must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 1;
    }
    if (length > MAX_PASSWORD_LENGTH) {
        printf("Password exceeds the maximum length of %d characters.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }

    // Check each character of the string and count occurrences
    for (i = 0; i < length; i++) {
        if (islower(str[i])) {
            lowercase_count++;
        } else if (isupper(str[i])) {
            uppercase_count++;
        } else if (isdigit(str[i])) {
            digit_count++;
        } else if (ispunct(str[i])) { // Checks for special characters like !, @, #, etc.
            special_count++;
        }
    }

    // Check if all counts meet the required minimums
    if (lowercase_count < MIN_LOWERCASE) {
        printf("Password needs at least %d lowercase letters.\n", MIN_LOWERCASE);
        return 1;
    }
    if (uppercase_count < MIN_UPPERCASE) {
        printf("Password needs at least %d uppercase letters.\n", MIN_UPPERCASE);
        return 1;
    }
    if (digit_count < MIN_DIGITS) {
        printf("Password needs at least %d digits.\n", MIN_DIGITS);
        return 1;
    }
    if (special_count < MIN_SPECIAL) {
        printf("Password needs at least %d special characters.\n", MIN_SPECIAL);
        return 1;
    }

    // If all conditions are met, return 0 (indicating success)
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    if (is_valid(argv[1]) == 0) {
        printf("The string is valid.\n");
        return 0; // Success
    } else {
        printf("The string is invalid. It must contain at least:\n");
        printf("- %d lowercase letters\n", MIN_LOWERCASE);
        printf("- %d uppercase letters\n", MIN_UPPERCASE);
        printf("- %d digits\n", MIN_DIGITS);
        printf("- %d special characters\n", MIN_SPECIAL);
        printf("And be between %d and %d characters long.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1; // Invalid password, return 1
    }
}

