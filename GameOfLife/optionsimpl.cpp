#include "optionsimpl.h"
#include "rule1.h"
#include "rule2.h"

OptionsImpl::OptionsImpl() : m_width(0),
                                                   m_height(0) {
    m_rules[0] = new RuleGameOfLife1 ;
    m_rules[1] = new RuleGameOfLife2 ;
}
unsigned short OptionsImpl::getRulesCount() const {
    return 2;
}
Rule* OptionsImpl::getRule(unsigned short number) {
    return m_rules[number];
}
/*void OptionsImpl::addRule(Rule* rule) {
    m_rules[getRulesCount()] = rule;
}*/
unsigned short OptionsImpl::getListenersCount() const {
    return (unsigned short) m_listeners.size();
}
IGridListener* OptionsImpl::getListener(unsigned short number) {
    return m_listeners[number];
}
void OptionsImpl::addListener(IGridListener*listener) {
    m_listeners[getListenersCount()] = listener;
}
unsigned int OptionsImpl::getWidth() const {
    return m_width;
}
void OptionsImpl::setWidth(unsigned int w) {
    m_width = w;
}
unsigned int OptionsImpl::getHeight() const {
    return m_height;
}
void OptionsImpl::setHeight(unsigned int h) {
    m_height = h;
}
OptionsImpl::~OptionsImpl() {
    delete m_rules[0];
    delete m_rules[1];
}
