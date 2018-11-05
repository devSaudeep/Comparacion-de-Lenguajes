/*  Saulo Almeda Nieves
 *  841-13-0170
 *  10/10/2015
 *  rock_paper_scissors.c
 *  Este programa simula el juego de piedra, papel y tijera.
 */

 #include <stdio.h>     // for printf, scanf
 #include <stdlib.h>    //for srandom
 #include <time.h>      //for random

 //Prototipos de las funciones
 int computerTurn(int sel, int wGames);

 //Ejecuccion del programa (main)
 int main(void) {
     int selection;
     double wonPercentage, numOfGames = 0, wonGames = 0, per100 = 100;
     char playAgainToken;

     do {
        printf("Enter your selection (0=Rock, 1=Paper, 2=Scissors): ");
        scanf(" %d", &selection);

        if(selection != 0 && selection != 1 && selection != 2) {
            printf("Selection not available. Enter your selection again (0=Rock, 1=Paper, 2=Scissors): ");
            scanf(" %d", &selection);
        }

        wonGames = computerTurn(selection, wonGames);

        numOfGames++;

        printf("Do you want to play again (y/n)? ");
        scanf(" %c", &playAgainToken);

        if(playAgainToken != 'y' && playAgainToken != 'Y' && playAgainToken != 'n' && playAgainToken != 'N') {
            printf("Unrecognized character. Select (y) to pay again or (n) to stop playing: ");
            scanf(" %c", &playAgainToken);
        }
     } while(playAgainToken == 'y' || playAgainToken == 'Y');

     wonPercentage = (wonGames / numOfGames) * per100;
     printf("Thanks for playing. You won %.2f of the games.", wonPercentage);
     return 0;
 }

 int computerTurn(int sel, int wGames) {
     time_t t;
     srand((unsigned) time(&t));
     int computerSelection = rand() % 3;

     if(computerSelection == 0) {
        printf("My selection was %d=Rock. ", computerSelection);
        if(sel == 0)
            printf("It's a tie!\n");
        else if(sel == 1) {
            printf("You won!\n");
            wGames++;
        }
        else
            printf("You lost!\n");

     }
     else if(computerSelection == 1) {
        printf("My selection was %d=Paper. ", computerSelection);
        if(sel == 0)
            printf("You lost!\n");
        else if(sel == 1)
            printf("It's a tie!\n");
        else {
            printf("You won!\n");
            wGames++;
        }
     }
     else {
        printf("My selection was %d=Scissors. ", computerSelection);
        if(sel == 0) {
            printf("You won!\n");
            wGames++;
        }
        else if(sel == 1)
            printf("You lost!\n");
        else
            printf("It's a tie!\n");
     }

     return wGames;
 }
