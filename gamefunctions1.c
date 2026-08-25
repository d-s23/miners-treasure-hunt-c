//

#include "gamefunctions1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


// Selects a difficulty level and returns a difficulty Multiplier which is applied on probability of diamond
void difficultyLevel(int *difficulty){
    printf("What level of Difficulty would you like: \n1) Easy \n2) Medium \n3) Hard \n");
    scanf("%d", &(*difficulty));

    if (*difficulty == 1){
        (*difficulty = 2); // becomes a multiplier
        printf("You have picked the easy level!\n");
    }

    else if (*difficulty == 2){
        (*difficulty = 1); // becomes a multiplier
        printf("You have picked the medium level!\n");
    }

    else if (*difficulty == 3){
        (*difficulty = 0.5); // becomes a multiplier
        printf("You have picked the Hard level!\n");
    }

    else{
        (*difficulty = 1); // becomes a multiplier
        printf("You didn't pick a level therefore you have been automatically selected for the medium level.\n ");
    }
}


// Resource function there to randomly give you a mineral when you mine.
void resource(int *picklvl, int *stone, int *silver,  int *gold, int *diamond, int *iStone, int *iSilver,  int *iGold, int *iDiamond, int *difficulty){
    int random;

    random = rand() %110;
    //printf("%d\n", random);

    if ((random < 10 * (*difficulty)) && (*picklvl > 2)){
        (*diamond)++;
        (*iDiamond)++;

    }

    else if ((random < 30) && (*picklvl > 1 )){
        (*gold)++;
        (*iGold)++;
    }

    else if (random < 60){
        (*silver)++;
        (*iSilver)++;
    }

    else {
        (*stone)++;
        (*iStone)++;
    }

    //printf("Total Stone: %d, Silver: %d, Gold:%d, Diamond: %d", *stone, *silver, *gold, *diamond);

}

void backtrack(int x, int y, int xVisited[], int yVisited[], int *numVisited, int *flag){
    for (int i = 0; i < (*numVisited); i++){
        if ((xVisited[i] == x) && (yVisited[i] == y)) {
            ((*flag) = 1) ;// if coordinates found
        }
    }
    // Flag remains zero when coordinates aren't found
}

void updateVisit(int *x, int *y, int xVisited[], int yVisited[], int *numVisited){
    xVisited[*numVisited] = *x;
    yVisited[*numVisited] = *y;
    (*numVisited)++;

//    printf("Updated Visited Coordinates:\n");
//    for (int i = 0; i < *numVisited; i++) {
//        printf("(%d, %d)\n", xVisited[i], yVisited[i]);
//    }
}


// Mine function, Checks whether you can mine i.e. Pickaxe health / reach a border.
// Also updates location and pickaxe Health
void mine(int *x, int *y, int *pickHealth, int *picklvl, int *stone, int *silver,  int *gold, int *diamond, int *iStone, int *iSilver,  int *iGold, int *iDiamond, int *difficulty, int xVisited[], int yVisited[], int *numVisited) {
    // The * infront of the variable allows for the pass by reference
    char direction;
    int flag = 0;

    // Checks if it is possible to mine
    if (*pickHealth < 1){
        printf("Go to shop and buy a new Pickaxe \n");
        return; // exits back to Main function
    }

    // Gives a limit to how much of certain elements the user can hold
    // Rarer elements way more
    else if (((*iStone) > 12) || ((*iSilver) > 10) || ((*iGold) > 8)) {
        printf("You have reached your Storage limit in your inventory for one of your Resources \n");
        printf("Go to shop to empty your inventory\n");
        return; // exits back to Main function
    }

    else {

        printf("What direction would you like to mine in?\n");
        printf("Use w(Up), s(down), a(left), d(right)\n");
        scanf(" %c", &direction);

        if (direction == 'w') {
            printf("Up \n");

            // Upper limit border of mining area
            if ((*y + 1) >= 0) {
                printf("This above the ground, this is not mineable!\n");
            }
            else {
                (*y)++;
                backtrack(*x, *y, xVisited, yVisited, numVisited, &flag);
                if (flag == 1){
                    printf("This coordinate has already been mined");
                }
                else{
                    // Update Pickaxe Health and leads to resource function for mineral
                    (*pickHealth)--;
                    resource(picklvl, stone, silver, gold, diamond, iStone, iSilver, iGold, iDiamond, difficulty);
                    //Update the updateVisit function
                    updateVisit(x, y, xVisited, yVisited, numVisited);
                }

            }
        }
        else if (direction == 's') {
            printf("Down \n");

            // lower limit border of mining area
            if ((*y - 1) < -13) {
                printf("This Bedrock, this is not mineable!\n");
            }
            else {
                // Update position
                (*y)--;
                backtrack(*x, *y, xVisited, yVisited, numVisited, &flag);
                if (flag == 1){
                    printf("This coordinate has already been mined");
                }
                else{
                    // Update Pickaxe Health and leads to resource function for mineral
                    (*pickHealth)--;
                    resource(picklvl, stone, silver, gold, diamond, iStone, iSilver, iGold, iDiamond, difficulty);
                    //Update the updateVisit function
                    updateVisit(x, y, xVisited, yVisited, numVisited);
                }
            }
        }
        else if (direction == 'a') {
            printf("Left \n");

            // Left limit border of mining area
            if ((*x - 1) <= 0) {
                printf("This Bedrock, this is not mineable!\n");
            }
            else {
                // Update position
                (*x)--;
                backtrack(*x, *y, xVisited, yVisited, numVisited, &flag);
                if (flag == 1){
                    printf("This coordinate has already been mined");
                }
                else{
                    // Update Pickaxe Health and leads to resource function for mineral
                    (*pickHealth)--;
                    resource(picklvl, stone, silver, gold, diamond, iStone, iSilver, iGold, iDiamond, difficulty);
                    //Update the updateVisit function
                    updateVisit(x, y, xVisited, yVisited, numVisited);
                }
            }
        }
        else if (direction == 'd') {
            printf("Right \n");

            // Right limit border of mining area
            if ((*x + 1) >= 13) {
                printf("This Bedrock, this is not mineable!\n");
            }
            else {
                // Update of position, Pickaxe Health and leads to resource function for mineral
                (*x)++;
                backtrack(*x, *y, xVisited, yVisited, numVisited, &flag);
                if (flag == 1){
                    printf("This coordinate has already been mined");
                }
                else{
                    // Update Pickaxe Health and leads to resource function for mineral
                    (*pickHealth)--;
                    resource(picklvl, stone, silver, gold, diamond, iStone, iSilver, iGold, iDiamond, difficulty);
                    //Update the updateVisit function
                    updateVisit(x, y, xVisited, yVisited, numVisited);
                }
            }
        }
        else {
            printf("This an invalid direction\n");
        }
    }
}


//Shop Function: exchanges minerals to coins, updates inventory; when a diamond check; and Pickaxe upgrade.
void shop(int *pickHealth, int *picklvl, int *iStone, int *iSilver,  int *iGold, int *iDiamond, int *coins, int *diamondSold, int *a) {
    char new = 'y';
    int price = 10;
    printf("Welcome to the Shop\n");

    //Coins Conversion from minerals mined
    *coins = (*coins + (*iStone) + ((*iSilver) * 3) + ((*iGold) * 5));
    printf("Your coin balance is: %d \n", *coins);

    //Clears Inventory of all resources
    // Total number resources is being accumulated in the Resources function
    // This resets so there is no infinite coin glitch
    *iStone = 0;
    *iSilver = 0;
    *iGold = 0;

    //Checks if it is possible to sell diamond
    *diamondSold += (*iDiamond);

    //Buy a new pickaxe plus levels it up (Unlocks more minerals)
    printf("Would you like to buy a new Pickaxe?\n Answer with 'y' for yes, and 'n' for no: \n");
    scanf(" %c", &new);

    // update 'a' to break while loop this way diamondSold can also be updated
    if ((*diamondSold) > 0){
        *a = 4;
    }

    else{

        if (new == 'y') {
            price = (price * (*picklvl));
            printf("Price of a new pickaxe = %d \n", price);

            if ((*coins) >= price) {
                *coins = ((*coins) - price);
                //sorts out coin balance
                (*picklvl)++;
                *pickHealth = ((*pickHealth) + price);
                // THis way pickaxe Health only adds on top
                // Price is used as a fair increment for pickaxe health as the more expensive pickaxe == more health

                printf("Your Pickaxe has been upgraded to level %d \n", *picklvl);
                printf("Your Pickaxe Health is now: %d \n", *pickHealth);
                printf("Your NEW coin balance is: %d \n", *coins);

                // Notify User of their upgrade abilities
                if ((*picklvl) == 2) {
                    printf("You can now mine gold! \n");
                } else if ((*picklvl) == 3) {
                    printf("You can now mine Diamond! \n");
                }

            } else {
                printf("You have insufficient coin funds!\n Go mine some more minerals!\n");
            }
        }
    }
}



//What current player holds in their inventory: Pickaxe lvl + hp, coins balance and resources
void inventory(int *pickHealth, int *picklvl, int *coins, int *iStone, int *iSilver,  int *iGold, int *iDiamond) {
    printf("Your Inventory Contains:\n");

    printf(" - level %d Pickaxe ", *picklvl);
    printf(" (Pickaxe Health is %d) \n", *pickHealth);

    printf(" -  %d coins \n", *coins);

    printf(" - Stone: %d\n - Silver: %d\n - Gold:%d\n - Diamond: %d\n", *iStone, *iSilver, *iGold, *iDiamond);

}
