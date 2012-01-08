#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>


#include "GameOfLife/gameoflife.h"
#include "GameOfLife/optionsimpl.h"
#include "GameOfLife/displayer.h"

int main(int argc, char *argv[])
{
    Displayer sdlDisplayer;
        sdlDisplayer.openDisplay();

    OptionsImpl options;
        options.addListener(&sdlDisplayer);
        options.setHeight(50);
        options.setWidth(50);

    GameOfLife game;
        game.createGrid(&options);

     SDL_Event event;
    while(event.type != SDL_QUIT) {
        SDL_Delay(100);
        SDL_PollEvent(&event);
        game.nextFrame();
    }

    return 0;
}
