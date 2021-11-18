
#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include "main.hpp"


int main ( int argc, char** argv ){
    SDL_Init( SDL_INIT_VIDEO );
    SDL_Surface* screen = SDL_SetVideoMode(500, 500, 16,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_Surface *aide = SDL_LoadBMP("images/aide.bmp");
    SDL_Surface *aide1 = SDL_LoadBMP("images/aide1.bmp");
    SDL_WM_SetCaption("Morpion Solitaire De Kengoum Gassam et Satsa Ivan", NULL);
    SDL_Rect c;
    c.x = 0;
    c.y = 0;
    int i = 0;
    bool done = false;
    while (!done){
        if(i == 0){
            SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
            SDL_BlitSurface(aide, NULL, screen, &c);
            SDL_Flip(screen);
            SDL_Delay(100);
            i = 1;
        }else{
            SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
            SDL_BlitSurface(aide1, NULL, screen, &c);
            SDL_Flip(screen);
            SDL_Delay(100);
            i = 0;
        }
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            switch (event.type){
            case SDL_QUIT: case SDLK_ESCAPE:
                done = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                int x = event.button.x, y = event.button.y;
                if( x < 440 && x > 340 && y < 300 && y > 280){
                    jouer(screen);
                    done = true;
                }
                break;
            }
        }
    }

    return 0;
}


