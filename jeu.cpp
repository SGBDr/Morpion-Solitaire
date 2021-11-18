#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL_mixer.h>

#include "jeu.hpp"


void jouer(SDL_Surface* screen){
    int bscore = 0;
    MeilleurScore(bscore);
    int carte[50][50], score = 0, clk = 0;
    int c1[50][50], c2[50][50], c3[50][50], c4[50][50];
    char rps[100];
    SDL_Surface *bg = SDL_LoadBMP("images/bg.bmp");
    SDL_Surface *p = SDL_LoadBMP("images/point.bmp");
    SDL_SetColorKey(p, SDL_SRCCOLORKEY, SDL_MapRGB(p->format, 255,255,255));
    sprintf(rps, "Score %d pts. Definir le Premier point . Meilleur Score %d", score, bscore);
    SDL_WM_SetCaption(rps, NULL);
    SDL_Rect a,b;
    a.x = 0;
    a.y = 0;
    bool bp = false;
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_BlitSurface(bg, NULL, screen, &a);
    SDL_Flip(screen);

    init1(c1);
    init2(c2);
    init(carte);
    remplir(carte);
    dessin(carte,screen,p);

    bool done = false;
    while(!done){
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            switch (event.type){
            case SDL_QUIT:
                if(bp)EnregistreScore(score);
                done = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                int x = event.button.x, y = event.button.y;
                if(clk == 0){
                    a.x = x/10;
                    a.y = y/10;
                    sprintf(rps, "Score %d pts. Definir le Deuxieme point", score);
                    SDL_WM_SetCaption(rps, NULL);
                    clk = 1;
                }else{
                    b.x = x/10;
                    b.y = y/10;
                    bool coup = cinq(carte,c1,c2,a,b);
                    if(coup){
                        dessin(carte,screen,p);
                        a.x *= 10;
                        b.x *= 10;
                        a.y *= 10;
                        b.y *= 10;
                        //Ligne(screen,a,b);
                        SDL_Flip(screen);
                        score++;
                    }
                    sprintf(rps, "Score %d pts. Definir le Premier point", score);
                    SDL_WM_SetCaption(rps, NULL);
                    clk = 0;
                }
                break;
            }
            if(score > bscore && !bp){
                sprintf(rps, "Bravo, vous avez a present le meilleur score : %d", score);
                SDL_WM_SetCaption(rps, NULL);
                bp = true;
            }
        }
    }

}
