#include <stdio.h>
#include <stdlib.h>

//global constants
#define SLOTS 1
#define SCRATCH 2
#define BLACKJACK 3

//function prototypes
void welcomeScreen();
void clearScreen();

int main()
{
    int game;

    welcomeScreen();
    clearScreen();
 //   game = displayMenu();

    return 0;
}
//opening text statement
void welcomeScreen()
{
    printf("       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n       X      !!!HIGH STAKES GAMES!!!      X\n       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
}
//clears the screen
void clearScreen()
{
    char enter;
    printf("           Press the enter to continue!\n");

    scanf("%c", &enter);
    //windows clear
    system("cls");
    //linux clear
    //system("clear");
}
//displays the menu options, player selects numeral 1-3
int displayMenu()
{
    int select;

    do
    {
        printf("Select your game:\n 1. SLOTS\n 2. SCRATCH\n 3.BLACKJACK\n");

        scanf("%d", &select);
    } while(select < SLOTS || select > BLACKJACK );

    return select;
}
