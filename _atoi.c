#include "shell.h"

/**
 * checkIfInteractive - Check if the shell is in interactive mode.
 * @info: A pointer to a struct that contains shell information.
 *
 * Return: 1 if in interactive mode, 0 otherwise.
 */
int checkIfInteractive(info_t *info) {
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * isDelimiter - Check if a character is a delimiter.
 * @character: The character to check.
 * @delimiters: A string of delimiters.
 * Return: 1 if true, 0 if false.
 */
int isDelimiter(char character, char *delimiters) {
    while (*delimiters) {
        if (*delimiters++ == character) {
            return 1;
        }
    }
    return 0;
}

/**
 * isAlphabetic - Check if a character is alphabetic.
 * @character: The character to check.
 * Return: 1 if it's alphabetic, 0 otherwise.
 */
int isAlphabetic(int character) {
    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * stringToInteger - Convert a string to an integer.
 * @str: The string to be converted.
 * Return: 0 if there are no numbers in the string, the converted number otherwise.
 */
int stringToInteger(char *str) {
    int index, sign = 1, parsingFlag = 0, result;
    unsigned int integerValue = 0;

    for (index = 0; str[index] != '\0' && parsingFlag != 2; index++) {
        if (str[index] == '-') {
            sign *= -1;
        }

        if (str[index] >= '0' && str[index] <= '9') {
            parsingFlag = 1;
            integerValue *= 10;
            integerValue += (str[index] - '0');
        } else if (parsingFlag == 1) {
            parsingFlag = 2;
        }
    }

    if (sign == -1) {
        result = -integerValue;
    } else {
        result = integerValue;
    }

    return result;
}
