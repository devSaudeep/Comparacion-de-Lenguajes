/*
* time_components.c
* this program determines the components (hours, minutes, seconds)
* for the given number of elapsed seconds*/

#include <stdio.h>  //for printf, scanf

//Prototype
void get_components(int elapsed_secs, int *hrs, int *mins, int *secs);

// Starts the execution of this program
int main(void) {
    int elapsed_seconds;

    printf("Enter the number of elapsed seconds: ");
    scanf("%d", &elapsed_seconds);

    if(elapsed_seconds < 0)
        printf("Error! Negative elapsed seconds. \n");
        else {
            int hours, minutes, seconds;
            get_components(elapsed_seconds, &hours, &minutes, &seconds);
            printf("The components are %d hours, %d minutes and %d seconds.\n", hours, minutes, seconds);
        }
    return 0;
}

void get_components(int elapsed_secs, int *hrs, int *mins, int *secs) {
    const int SECS_PER_MIN = 60, SECS_PER_HOUR = 3600;

    *hrs = elapsed_secs / SECS_PER_HOUR;
    int rem_secs = elapsed_secs % SECS_PER_HOUR;
    *mins = rem_secs / SECS_PER_MIN;
    *secs = rem_secs % SECS_PER_MIN;
}
