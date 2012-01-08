#ifndef RULE_H_INCLUDED
#define RULE_H_INCLUDED

#include "cell.h"

class Rule {
    public:
        virtual ~Rule() {};
        virtual void checkCell(Cell **grid, unsigned int x, unsigned int y, unsigned int w, unsigned int h) = 0;
};

#endif // RULE_H_INCLUDED
