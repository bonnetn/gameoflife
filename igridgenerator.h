#ifndef IGRIDGENERATOR_H_INCLUDED
#define IGRIDGENERATOR_H_INCLUDED

#include "options.h"

class IGridGenerator {
    public:
        virtual ~IGridGenerator() {};
        virtual void startGenerating(Options* options) = 0;
};

#endif // IGRIDGENERATOR_H_INCLUDED
