
/*
 * string_demo.c
 * By Antonio F. Huertas
 * This program demonstrates some functions for C strings.
 */

#include <stdio.h>  // for printf, scanf, getchar, puts, gets
#include <string.h> // for strlen, strcpy, strcmp, strcat
#include <ctype.h>  // for toupper

// Defines some symbolic constants
#define WORD_SIZE 21
#define LINE_SIZE 81

// Starts the execution of the program.
int main(void) {
    char str1[LINE_SIZE] = "example string";
    printf("This is str1: %s\n", str1);
    printf("Its first character is %c\n", str1[0]);
    printf("Its length is %d\n\n", strlen(str1));

    str1[0] = toupper(str1[0]);
    printf("Now, this is str1: %s\n", str1);
    printf("Its first character is %c\n", str1[0]);
    printf("Its length is %d\n\n", strlen(str1));

    strcpy(str1, "another");
    printf("Now, this is str1: %s\n", str1);
    printf("Its first character is %c\n", str1[0]);
    printf("Its length is %d\n\n", strlen(str1));

    strcat(str1, " thing");
    printf("Now, this is str1: %s\n", str1);
    printf("Its first character is %c\n", str1[0]);
    printf("Its length is %d\n\n", strlen(str1));

    char str2[WORD_SIZE];
    printf("Enter a one-word string: ");
    scanf("%s", str2);

    printf("This is str2: %s\n", str2);
    printf("Its first character is %c\n", str2[0]);
    printf("Its length is %d\n\n", strlen(str2));

    while (getchar() != '\n');        // flush keyboard buffer

    char str3[LINE_SIZE];
    printf("Enter a line of text: ");
    gets(str3);

    printf("This is str3: %s\n", str3);
    printf("Its first character is %c\n", str3[0]);
    printf("Its length is %d\n\n", strlen(str3));

    int cmp = strcmp(str2, str3);
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
    printf("Its length is %d\n\n", strlen(str4));

    str4 = "another read-only";
    printf("This is str4: %s\n", str4);
    printf("Its first character is %c\n", str4[0]);
    printf("Its length is %d\n", strlen(str4));

    return 0;
}
