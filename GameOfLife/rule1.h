#ifndef RULE1_H_INCLUDED
#define RULE1_H_INCLUDED

#include "../rule.h"

class RuleGameOfLife1 : public Rule {
    public:
        virtual void checkCell(Cell **grid, unsigned int x, unsigned int y, unsigned int w, unsigned int h);

    private:
        void checkNeighbours(Cell **grid, unsigned int x, unsigned int y, unsigned int w, unsigned int h, int *table);
};

#endif // RULE1_H_INCLUDED
