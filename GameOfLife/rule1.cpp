#include "rule1.h"
#include "cellimpl.h"
#include <stdio.h>

void RuleGameOfLife1::checkCell(Cell **grid, unsigned int x, unsigned int y, unsigned int w, unsigned int h) {

    if(grid[x+y*w]->getState()  != DEAD) {return;} // Si la cellule n'est pas morte alors on fait rien
    int states[8];
    CellImpl::checkNeighbours(grid, x, y, w, h, states); // On récupère les voisins de la cellule dans states

    // Si on a 3 voisins alors on nait
    unsigned char nearby(0);
    for(unsigned char i=0;  i<8; i++) {
        if(states[i] == ALIVE ||states[i] == OLD) {
            nearby++;
        }
    }
    if(nearby == 3) {
        grid[x+y*w]->setState(NEW);
    }
}
