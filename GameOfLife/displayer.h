#ifndef DISPLAYER_H_INCLUDED
#define DISPLAYER_H_INCLUDED

#include "../IGridListener.h"
#include <SDL.h>

class Displayer : public IGridListener {
    public:
        Displayer() :
            m_state(false),
            m_screen(NULL),
            m_grid(NULL)
        {};
        virtual void cellChanged(Cell **grid, unsigned int w, unsigned int h);

        void openDisplay();
        void closeDisplay();
        void clear();
        void setCell(unsigned int x, unsigned int y, int state, unsigned int w, unsigned int h);

    private:
        void setPixel(SDL_Surface *surface, unsigned int x, unsigned int y, Uint32 pixel);

        bool m_state;
        SDL_Surface *m_screen;
        Cell** m_grid;
};

#endif // DISPLAYER_H_INCLUDED
