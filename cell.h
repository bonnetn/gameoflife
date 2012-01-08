#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

class Cell {
    public:
        virtual ~Cell() {};

        virtual int getState() const = 0;
        virtual void setState(int state) = 0;
};

#endif // CELL_H_INCLUDED
