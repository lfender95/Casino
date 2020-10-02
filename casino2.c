#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//global constants
#define SLOTS 1
#define SCRATCH 2
#define BLACKJACK 3

//function prototypes
void welcomeScreen();
void clearScreen();
int playSlots();
int playScratchOffs();
int playBlackJack();
char randomSymbol();

int main()
{
    int game;
    int cash = 1000;
    srand(time(0));

    welcomeScreen();
    clearScreen();
    game = displayMenu();
    clearScreen();

     switch(game)
     {
         case 1:
            cash = playSlots(cash);
            break;

            case 2:
        cash = playScratchOffs(cash);
        break;

    case 3:
        cash = playBlackjack(cash);
        break;


    }
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
        printf("Select your game:\n 1. SLOTS\n 2. SCRATCH\n 3. BLACKJACK\n");

        scanf("%d", &select);
    } while(select < SLOTS || select > BLACKJACK );

    return select;
}
//playSlots
int playSlots(int cash)
{
    const int bet = 5;
    const int match_two = 5;
    const int match_three = 50;
    int play = 1;
    char symOne;
    char symTwo;
    char symThree;

    printf("Bet costs %d. If you match two you win %d. If you match three you win %d.\n", bet, match_two, match_three);


    if (cash >= bet)
    {
        while (play == 1)
        {
            cash = cash - bet;
            printf("Slots are spinning\n");

            symOne = randomSymbol();
            symTwo = randomSymbol();
            symThree = randomSymbol();
            printf("%c %c %c\n", symOne, symTwo, symThree);

            if (symOne == symTwo && symOne == symThree)
            {
                printf("All three symbols match! You win $%d!\n", match_three);

                cash = cash + match_three;
            }
            else if (symOne == symTwo || symOne == symThree || symTwo == symThree)
            {
                printf("Two symbols match. You win $%d.\n", match_two);

                cash = cash + match_two;
            }
            else
            {
                printf("No symbols match.\n");

            }

            printf("Your current cash is now %d.\n", cash);


            if (cash >= bet)
            {
                printf("Would you like to spin again? Press 1 to play again or 0 to return to main menu.\n");
                scanf("%d", &play);
            }
            else
            {
                printf("Not enough cash to continue, returning to main menu.\n");

                break;
            }
        }
        printf("Thanks for playing. Current cash amount is %d\n",cash);

        return cash;
    }
    else
    {
        play = 0;
    }
}

char randomSymbol()
{
    const int symbolCount = 6;
    const char symbols [] = "$" "%" "&" "#" "@" "!";
    char randomSymbol;
    int randomNumber;

    randomNumber = rand() % 5 + 0;

    switch(randomNumber)
     {
         case 0:
            randomSymbol = symbols[0];
            break;
         case 1:
            randomSymbol = symbols[1];
            break;
         case 2:
            randomSymbol = symbols[2];
            break;
         case 3:
            randomSymbol = symbols[3];
            break;
         case 4:
            randomSymbol = symbols[4];
            break;
         case 5:
            randomSymbol = symbols[5];
            break;
    }
    return randomSymbol;
}
int playScratchOffs()
    { int cash;
     printf("You are playing a scratchoff game!");
     return cash;
     }

     int playBlackjack()
     { int cash;
         printf("You are playing blackjack game!");
         return cash; }
