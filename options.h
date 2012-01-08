#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include "rule.h"
#include "igridlistener.h"

class Options {
    public:
        virtual ~Options() {};

        virtual unsigned short getRulesCount() const = 0;
        virtual Rule* getRule(unsigned short number) = 0;
        //virtual void addRule(Rule* rule) = 0;

        virtual unsigned short getListenersCount() const = 0;
        virtual IGridListener* getListener(unsigned short number) = 0;
        //virtual void addListener(IGridListener*listener) = 0;

        virtual unsigned int getWidth() const = 0;
        //virtual void setWidth(unsigned int w) = 0;

        virtual unsigned int getHeight() const = 0;
        //virtual void setHeight(unsigned int h) = 0;

};

#endif // OPTIONS_H_INCLUDED
