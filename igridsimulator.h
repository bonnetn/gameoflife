#ifndef IGRIDSIMULATOR_H_INCLUDED
#define IGRIDSIMULATOR_H_INCLUDED

#include "cell.h"
#include "options.h"

class IGridSimulator {
    public:
        virtual ~IGridSimulator() {};
        virtual void generate(Cell **grid, Options *options) = 0;
};

#endif // IGRIDSIMULATOR_H_INCLUDED
