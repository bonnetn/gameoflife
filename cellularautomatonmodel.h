#ifndef CELLULARAUTOMATONMODEL_H_INCLUDED
#define CELLULARAUTOMATONMODEL_H_INCLUDED

#include "options.h"

class CellularAutomatonModel {
    public:
        virtual ~CellularAutomatonModel() {}
        virtual void createGrid(Options *options) = 0;
};

#endif // CELLULARAUTOMATONMODEL_H_INCLUDED
