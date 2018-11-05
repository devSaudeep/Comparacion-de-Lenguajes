/*
 * my_string_fns.c
 * By Antonio F. Huertas
 * This program defines some C string functions.
 */

#include <stdio.h>  // for printf, scanf, getchar, puts, gets
#include <ctype.h>  // for toupper

// Defines some symbolic constants
#define WORD_SIZE 21
#define LINE_SIZE 81

// Declares functions using prototypes.
int my_strlen(const char *str);
int my_strcmp(const char *str1, const char *str2);
void my_strcpy(char *dst, const char *src);
void my_strcat(char *dst, const char *src);

// Starts the execution of the program.
int main(void) {
    char str1[LINE_SIZE] = "example string";
    printf("This is str1: %s\n", str1);
    printf("Its first character is %c\n", str1[0]);
    printf("Its length is %d\n\n", my_strlen(str1));

    str1[0] = toupper(str1[0]);
    printf("Now, this is str1: %s\n", str1);
    printf("Its first character is %c\n", str1[0]);
    printf("Its length is %d\n\n", my_strlen(str1));

    my_strcpy(str1, "another");
    printf("Now, this is str1: %s\n", str1);
    printf("Its first character is %c\n", str1[0]);
    printf("Its length is %d\n\n", my_strlen(str1));

    my_strcat(str1, " thing");
    printf("Now, this is str1: %s\n", str1);
    printf("Its first character is %c\n", str1[0]);
    printf("Its length is %d\n\n", my_strlen(str1));

    char str2[WORD_SIZE];
    printf("Enter a one-word string: ");
    scanf("%s", str2);

    printf("This is str2: %s\n", str2);
    printf("Its first character is %c\n", str2[0]);
    printf("Its length is %d\n\n", my_strlen(str2));

    while (getchar() != '\n');        // flush keyboard buffer

    char str3[LINE_SIZE];
    printf("Enter a line of text: ");
    gets(str3);

    printf("This is str3: %s\n", str3);
    printf("Its first character is %c\n", str3[0]);
    printf("Its length is %d\n\n", my_strlen(str3));

    int cmp = my_strcmp(str2, str3);
    if (cmp < 0)
        puts("str2 goes before str3.");
    else if (cmp > 0)
        puts("str2 goes after str3.");
    else
        puts("str2 and str3 are the same.");
    printf("\n");

    char *str4 = "read-only string";
    printf("This is str4: %s\n", str4);
    printf("Its first character is %c\n", str4[0]);
    printf("Its length is %d\n\n", my_strlen(str4));

    str4 = "another read-only";
    printf("This is str4: %s\n", str4);
    printf("Its first character is %c\n", str4[0]);
    printf("Its length is %d\n", my_strlen(str4));

    return 0;
}

// Returns the length of a string.
int my_strlen(const char *str) {
    const char *ptr = str;
    while (*ptr++ != '\0');
    return ptr - str - 1;
}

// Compares two strings lexicographically.
int my_strcmp(const char *str1, const char *str2) {
    while (*str1 == *str2 && *str1 != '\0') {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// Copies the source string to a destination string.
void my_strcpy(char *dst, const char *src) {
    while ((*dst++ = *src++) != '\0');
}

// Appends the source string to a destination string.
void my_strcat(char *dst, const char *src) {
    while (*dst != '\0')
        dst++;
    while ((*dst++ = *src++) != '\0');
}
