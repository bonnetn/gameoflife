#ifndef GRIDSIMULATORIMPL_H_INCLUDED
#define GRIDSIMULATORIMPL_H_INCLUDED

#include "../igridsimulator.h"
#include "../igridlistener.h"
#include "rulescheckerimpl.h"

class GridSimulatorImpl : public IGridSimulator {
    public:
        virtual void generate(Cell **grid, Options *options);

    private:

};

#endif // GRIDSIMULATORIMPL_H_INCLUDED
