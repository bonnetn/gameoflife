#ifndef RULE2_H_INCLUDED
#define RULE2_H_INCLUDED

#include "../rule.h"

class RuleGameOfLife2 : public Rule {
    public:
        virtual void checkCell(Cell **grid, unsigned int x, unsigned int y, unsigned int w, unsigned int h);

    private:
        void checkNeighbours(Cell **grid, unsigned int x, unsigned int y, unsigned int w, unsigned int h, int *table);
};

#endif // RULE2_H_INCLUDED
