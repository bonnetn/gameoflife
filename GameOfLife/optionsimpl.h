#ifndef OPTIONSIMPL_H_INCLUDED
#define OPTIONSIMPL_H_INCLUDED

#include <map>
#include "../options.h"


class OptionsImpl : public Options {
    public:
        OptionsImpl();
        virtual ~OptionsImpl();

        virtual unsigned short getRulesCount() const;
        virtual Rule* getRule(unsigned short number);
        //virtual void addRule(Rule* rule);

        virtual unsigned short getListenersCount() const;
        virtual IGridListener* getListener(unsigned short number);
        virtual void addListener(IGridListener*listener);

        virtual unsigned int getWidth() const;
        virtual void setWidth(unsigned int w);

        virtual unsigned int getHeight() const;
        virtual void setHeight(unsigned int h);

    private:
        Rule *m_rules[2];
        std::map<unsigned short, IGridListener *> m_listeners;
        unsigned int m_width;
        unsigned int m_height;
};

#endif // OPTIONSIMPL_H_INCLUDED
