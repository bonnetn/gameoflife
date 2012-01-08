#include "rule2.h"
#include "cellimpl.h"
#include <stdio.h>

void RuleGameOfLife2::checkCell(Cell **grid, unsigned int x, unsigned int y, unsigned int w, unsigned int h) {

    if(grid[x+y*w]->getState()  != ALIVE) {return;} // Si la cellule n'est pas vivante alors on fait rien
    int states[8];
    CellImpl::checkNeighbours(grid, x, y, w, h, states); // On récupère les voisins de la cellule dans states

    // Si on a 3 ou 2 voisins alors on reste en vie
    unsigned char nearby(0);
    for(unsigned char i=0;  i<8; i++) {
        if(states[i] == ALIVE ||states[i] == OLD) {
            nearby++;
        }
    }
    if(nearby != 3 && nearby != 2) {
        grid[x+y*w]->setState(OLD);
    }
}
