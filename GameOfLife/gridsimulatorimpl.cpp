#include "gridsimulatorimpl.h"
#include "../options.h"
#include "cellimpl.h"
#include <cstdio>

void GridSimulatorImpl::generate(Cell **grid, Options *options) {
        RulesCheckerImpl checker;
        checker.setOptions(options);
        for(unsigned int y=0; y<options->getHeight()-1; ++y) {
            for(unsigned int x=0; x<options->getWidth()-1; ++x) {
                checker.applyRules(grid, x, y);
            }
        }
        for(unsigned long int pos=0; pos<(options->getHeight()*options->getWidth()); pos++)  {
            switch (grid[pos]->getState() ) {
                case NEW:
                    grid[pos]->setState(ALIVE);
                    break;
                case OLD:
                    grid[pos]->setState(DEAD);
                    break;
                default:
                    break;
            }
        }
        // On appelle les  listeners
        for(unsigned short listenersCount=0; listenersCount<(options->getListenersCount()); listenersCount++) {
            options->getListener(listenersCount)->cellChanged(grid, options->getWidth(), options->getHeight());
        }
        /*unsigned int listenersCount = options->getListenersCount();
        if(listenersCount) {
            IGridListener **listeners = (IGridListener **)malloc(listenersCount*sizeof(IGridListener *));
            if(listeners == NULL) {
                return;
            }
            for(unsigned short i=0; i<listenersCount; i++) {
                listeners[i] = options->getListener(i);
            }
        }*/
}
