#ifndef GAMEOFLIFE_H_INCLUDED
#define GAMEOFLIFE_H_INCLUDED

#include "../cellularautomatonmodel.h"
#include "../cell.h"
#include "gridsimulatorimpl.h"

class GameOfLife : public CellularAutomatonModel {
    public:
        GameOfLife();
        virtual void createGrid(Options *options);
        void nextFrame();
        virtual ~GameOfLife();

    private:
        Cell** m_grid;
        Options* m_options;
        GridSimulatorImpl m_simulator;

};


#endif // GAMEOFLIFE_H_INCLUDED
