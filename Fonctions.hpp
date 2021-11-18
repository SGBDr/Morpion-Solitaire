


#ifndef def_Fonctions

#include <SDL/SDL.h>
#include <math.h>
void dessin(int carte[50][50],SDL_Surface* screen, SDL_Surface* p);
void init(int carte[50][50]);
void remplir(int carte[50][50]);
bool cinq(int carte[50][50], int c1[50][50], int c2[50][50], SDL_Rect a, SDL_Rect b);
void init1(int carte[50][50]);
void init2(int carte[50][50]);
void init3(int carte[50][50]);
void init4(int carte[50][50]);
void Pixel(int x, int y, Uint32 coul, SDL_Surface* screen);
void Ligne(SDL_Surface* screen, SDL_Rect a, SDL_Rect b);

#endif
