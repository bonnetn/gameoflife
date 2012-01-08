#ifndef IRULESCHECKER_H_INCLUDED
#define IRULESCHECKER_H_INCLUDED

#include "cell.h"
#include "options.h"

class IRulesChecker {
    public:
        virtual ~IRulesChecker() {};
        virtual void applyRules(Cell **grid, unsigned int x, unsigned int y) = 0;
        virtual void setOptions(Options *options) = 0;
};

#endif // IRULESCHECKER_H_INCLUDED
