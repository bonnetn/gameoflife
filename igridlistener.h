#ifndef IGRIDLISTENER_H_INCLUDED
#define IGRIDLISTENER_H_INCLUDED

#include "cell.h"

class IGridListener {
    public:
        virtual ~IGridListener() {};
        virtual void cellChanged(Cell **grid, unsigned int w, unsigned int h) = 0;
};

#endif // IGRIDLISTENER_H_INCLUDED
