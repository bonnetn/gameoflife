#ifndef CELLIMPL_H_INCLUDED
#define CELLIMPL_H_INCLUDED

#include "cellimpl.h"
#include "../cell.h"

enum Cell_State {DEAD =0, ALIVE, NEW, OLD};

class CellImpl : public Cell {
    public:
        CellImpl() : m_state(0) {}
        ~CellImpl();

        virtual int getState() const;
        virtual void setState(int state);
        static void checkNeighbours(Cell **grid, unsigned int x, unsigned int y, unsigned int w, unsigned int h, int *states);

    private:
        int m_state;
};


#endif // CELLIMPL_H_INCLUDED
