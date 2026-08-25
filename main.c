#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamefunctions1.h"
// In header files, it has to be in ""

//Initialisation of Global Variables, so they can be passed through by reference into multiple functions
int x, y, pickHealth, picklvl, stone, silver, gold, diamond, coins, iStone, iSilver, iGold, iDiamond;
int diamondSold = 0;
int a = 2;
int difficulty = 1;
int xVisited[144] = {6};
int yVisited[144] = {-1};
int numVisited = 1;


int main() {
    x = 6;
    y = -1;
    pickHealth = 10;
    picklvl = 1;

    stone = 0;
    silver = 0;
    gold = 0;
    diamond = 0;

    iStone = 0;
    iSilver = 0;
    iGold = 0;
    iDiamond = 0;

    coins = 0;
    difficultyLevel(&difficulty);
    //Selects difficulty

    srand(time(NULL));
    // Random intalised here so when called there is more chance of a random number than any repetition when speed playing

    while (diamondSold < 1) {
        while ((a >= 1) && (a <= 3)) {
            printf("\nCurrent coordinate is (%d,%d)\n", x, y);

            printf("What would you like to do?\n 1. Mine\n 2. Shop\n 3. Check Inventory\n");
            scanf("%d", &a);

            printf("%d\n", a);

            if (a == 1) {
                printf("Picked option: 1. Mine\n");
                mine(&x, &y, &pickHealth, &picklvl, &stone, &silver, &gold, &diamond, &iStone, &iSilver, &iGold, &iDiamond, &difficulty, xVisited, yVisited, &numVisited);
                // & infront of variable allows for it to be passed through by reference
                // this allows for the value to change
            }

            else if (a == 2){
                printf("Picked option: 2. Shop\n");
                shop(&pickHealth, &picklvl, &iStone, &iSilver, &iGold, &iDiamond, &coins, &diamondSold, &a);
            }

            else if (a == 3){
                printf("Picked option: 3. Inventory\n");
                inventory(&pickHealth, &picklvl, &coins, &iStone, &iSilver, &iGold, &iDiamond);
            }
            else {
                printf("Invalid option. Please enter a valid option (1, 2, or 3).\n");
                // Optionally clear the input buffer to prevent infinite loop due to non-integer input
            }
        }

    }
    printf("You won you managed to find, mine and sell a diamond!\n");
    printf("Total Stone: %d, Silver: %d, Gold:%d, Diamond: %d", stone, silver, gold, diamond);
    return 0;
}