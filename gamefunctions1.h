//

#ifndef MAIN_C_GAMEFUNCTIONS1_H
#define MAIN_C_GAMEFUNCTIONS1_H


// Declared functions from main.c
void difficultyLevel(int *difficulty);
void resource(int *picklvl, int *stone, int *silver,  int *gold, int *diamond, int *iStone, int *iSilver,  int *iGold, int *iDiamond, int *difficulty);
void backtrack(int x, int y, int xVisited[], int yVisited[], int *numVisited, int *flag);
void updateVisit(int *x, int *y, int xVisited[], int yVisited[], int *numVisited);
void mine(int *x, int *y, int *pickHealth, int *picklvl, int *stone, int *silver,  int *gold, int *diamond, int *iStone, int *iSilver,  int *iGold, int *iDiamond, int *difficulty, int xVisited[], int yVisited[], int *numVisited);
void shop(int *pickHealth, int *picklvl, int *iStone, int *iSilver,  int *iGold, int *iDiamond, int *coins, int *diamondSold, int*a);
void inventory(int *pickHealth, int *picklvl, int *coins, int *iStone, int *iSilver,  int *iGold, int *iDiamond);


#endif //MAIN_C_GAMEFUNCTIONS1_H
