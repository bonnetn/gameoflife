#include "rulescheckerimpl.h"
#include <cmath>

void RulesCheckerImpl::applyRules(Cell **grid, unsigned int x, unsigned int y) {
   if(m_rulesCount <= 0) {return;}
    int valueBefore = grid[x+y*m_width]->getState();
    for(unsigned short i=0; i<m_rulesCount; i++) {
        m_rules[i]->checkCell(grid, x, y, m_width, m_height);
    }
   /* if(grid[x+y*m_width]->getState() != valueBefore) {
        for(unsigned short i=0; i<m_listenersCount; i++) {
            m_listeners[i]->cellChanged(x, y, m_width, m_height, grid);
        }
    }*/
}
void RulesCheckerImpl::setOptions(Options *options){
    // On complète Rules
    m_rulesCount = options->getRulesCount();
    if(m_rulesCount) {
        m_rules = (Rule **)malloc(m_rulesCount*sizeof(Rule *));
        if(m_rules == NULL) {
            return;
        }
        for(unsigned short i=0; i<m_rulesCount; i++) {
            m_rules[i] = options->getRule(i);
        }
    }

    // On récupère la width et height
    m_width = options->getWidth();
    m_height = options->getHeight();
}
RulesCheckerImpl::~RulesCheckerImpl() {
    free(m_rules);
}

