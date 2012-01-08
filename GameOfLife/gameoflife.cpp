#include "gameoflife.h"
#include "cellimpl.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath> //TODO REMOVE THAT
GameOfLife::GameOfLife() :
                                              m_grid(NULL),
                                              m_options(NULL)
                                              {}
void GameOfLife::createGrid(Options *options) {
    srand(time(NULL));
    m_grid = (Cell**) malloc(sizeof(Cell *) *(options->getWidth() * options->getHeight()));
    for(unsigned long int i =0; i<(options->getWidth()*options->getHeight()); i++) {
        m_grid[i] = new CellImpl;
        if(fmod(rand(),2)-1) {
           m_grid[i]->setState(ALIVE);
        }
    }

    int states[8];
    CellImpl::checkNeighbours(m_grid, 5, 1, options->getWidth(), options->getHeight(), states);
    m_options = options;
    for(unsigned short i=0; i<m_options->getListenersCount(); i++) {
        m_options->getListener(i)->cellChanged(m_grid, options->getWidth(), options->getHeight());
    }
}
void GameOfLife::nextFrame() {
    m_simulator.generate(m_grid, m_options);
}
GameOfLife::~GameOfLife() {
    free(m_grid);
}

