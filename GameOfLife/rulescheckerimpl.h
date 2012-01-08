#ifndef RULESCHECKERIMPL_H_INCLUDED
#define RULESCHECKERIMPL_H_INCLUDED

#include "../iruleschecker.h"

#include <cstdlib>

class RulesCheckerImpl : public IRulesChecker {
    public:
        RulesCheckerImpl() :m_rules(NULL),
                                             m_rulesCount(0),
                                             m_width(0),
                                             m_height(0) {}

        virtual void applyRules(Cell **grid, unsigned int x, unsigned int y);
        virtual void setOptions(Options *options);
        ~RulesCheckerImpl();
    private:
        Rule** m_rules;
        unsigned short m_rulesCount;
        unsigned int m_width, m_height;

};
#endif // RULESCHECKERIMPL_H_INCLUDED
