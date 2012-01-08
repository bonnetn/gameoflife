#include "displayer.h"
#include "cellimpl.h"
#include <cmath>

void Displayer::cellChanged(Cell **grid, unsigned int w, unsigned int h) {
    if(m_state) {
        SDL_LockSurface(m_screen);
        if(m_grid != grid) {
            clear();
            m_grid = grid;
        }
        for(unsigned int y=0; y<h; y++) {
            for(unsigned int x=0; x<w; x++) {
                setCell((unsigned int) x, y, grid[x+y*w]->getState(), w, h);
            }
        }
        SDL_UnlockSurface(m_screen);
        SDL_Flip(m_screen);
    }
}
void Displayer::openDisplay() {
    if(!m_state) { // Si l'écran n'est pas déjà ouvert
        if (SDL_Init(SDL_INIT_VIDEO) == -1) {
            fprintf(stderr, "Erreur d'initialisation de la SDL");
            return;
        }
        m_screen = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE);
        if(m_screen == NULL) {
            fprintf(stderr, "Impossible de charger le mode vidéo %s\n", SDL_GetError());
            return;
        }
        SDL_WM_SetCaption("Game of life", NULL);
        m_state = true;

    }
}
void Displayer::closeDisplay() {
    if(m_state) {
        SDL_Quit();
    }
}
void Displayer::setPixel(SDL_Surface *surface, unsigned int x, unsigned int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    default:
        // do nuthing :>
        break;
    }
}
void Displayer::setCell(unsigned int x, unsigned int y, int state, unsigned int w, unsigned int h) {
    // nombre de cases à remplir = m_screen->h / h
    // position des cases = nombre de cases*y
    unsigned int cellW = (unsigned int) floor(m_screen->w / w); // 640/200 = 3.2
    unsigned int cellH = (unsigned int) floor(m_screen->h / h); // 480/200  = 2.4

    unsigned int startPosX =m_screen->w*x / w;
    unsigned int startPosY= m_screen->h*y / h;
    unsigned int posX;
    unsigned int posY;

    for (posY = 0; posY<cellH; posY++) {
        for(posX = 0; posX<cellW; posX++) {
            Uint32 color;
            switch(state) {
                case DEAD:
                    color = 0x555555;
                    break;
                case ALIVE:
                    color = 0x000000;
                    break;
                case NEW:
                    color = 0x000000;
                    break;
                case OLD:
                    color = 0x555555;
                    break;
                default:
                    color = 0xFF0000;
                    break;
            }
            setPixel(m_screen, startPosX + posX, startPosY + posY, color);
        }
    }
}
void Displayer::clear() {
    if(m_state) {
        SDL_LockSurface(m_screen);
        for(unsigned int x=0; x<(unsigned int)m_screen->w; x++) {
            for(unsigned int y=0; y<(unsigned int)m_screen->h; y++) {
                setPixel(m_screen, x, y, 0x555555);
            }
        }
        SDL_UnlockSurface(m_screen);
            SDL_Flip(m_screen);
    }

}

