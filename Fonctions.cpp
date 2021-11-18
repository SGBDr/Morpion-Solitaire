#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif


#include "Fonctions.hpp"


void Ligne(SDL_Surface* screen, SDL_Rect a, SDL_Rect b){
    double x = b.x - a.x;
    double y = b.y - a.y;
    double length = sqrt( x*x + y*y );

    double addx = x / length;
    double addy = y / length;

    x = a.x;
    y = a.y;

    for(double i = 0; i < length; i += 1){
      Pixel( (int)x, (int)y, SDL_MapRGB(screen->format, 45, 100, 250), screen);
      x += addx;
      y += addy;
    }
}

void Pixel(int x, int y, Uint32 coul, SDL_Surface* screen){
    if(x>=0 && y>=0)
  *((Uint32*)(screen->pixels) + x + y * screen->w) = coul;
}


bool cinq(int carte[50][50], int c1[50][50], int c2[50][50], SDL_Rect a, SDL_Rect b){
    bool cinq = false;
    if(abs(a.x - b.x) == 4 && b.y == a.y && c2[a.x][a.y] != 0 && c2[b.x][b.y] != 0){
        if(a.x > b.x){
            bool r = true;
            int i = 0, j = 0;
            for(i = 0 ; i < 5 ; i++){
                if(carte[b.x + i][b.y] == 0){
                    j++;
                    if(j > 1)r = false;
                }
            }
            if(r && j == 1){
                i = 0, j = 0;
                cinq = true;
                for(i = 0 ; i < 5 ; i++){
                    carte[b.x + i][b.y] = 1234;
                    c2[b.x + i][b.y] = 0;
                }

            }
        }else{
            bool r = true;
            int i = 0, j = 0;
            for(i = 0 ; i < 5 ; i++){
                if(carte[a.x + i][a.y] == 0){
                    j++;
                    if(j > 1)r = false;
                }
            }
            if(r && j == 1){
                i = 0, j = 0;
                cinq = true;
                for(i = 0 ; i < 5 ; i++){
                    carte[a.x + i][a.y] = 1234;
                    c2[a.x + i][a.y] = 0;
                }
            }
        }
    }else if(abs(a.y - b.y) == 4 && a.x == b.x && c1[a.x][a.y] != 0 && c1[b.x][b.y] != 0){
        if(a.y > b.y){
            bool r = true;
            int i = 0, j = 0;
            for(i = 0 ; i < 5 ; i++){
                if(carte[b.x][b.y + i] == 0){
                    j++;
                    if(j > 1)r = false;
                }
            }
            if(r && j == 1){
                i = 0, j = 0;
                cinq = true;
                for(i = 0 ; i < 5 ; i++){
                    carte[b.x][b.y + i] = 1234;
                    c1[b.x][b.y + i] = 0;
                }
            }
        }else{
            bool r = true;
            int i = 0, j = 0;
            for(i = 0 ; i < 5 ; i++){
                if(carte[a.x][a.y + i] == 0){
                    j++;
                    if(j > 1)r = false;
                }
            }
            if(r && j == 1){
                i = 0, j = 0;
                cinq = true;
                for(i = 0 ; i < 5 ; i++){
                    carte[a.x][a.y + i] = 1234;
                    c1[a.x][a.y + i] = 0;
                }
            }
        }
    }
    return cinq;
}


void dessin(int carte[50][50],SDL_Surface* screen, SDL_Surface* p){
    int i = 0 , j = 0;
    for(i = 0 ; i < 50 ; i++){
        for(j = 0 ; j < 50 ; j++){
            if(carte[i][j] == 1234){
                SDL_Rect a;
                a.x = i*10 - 5;
                a.y = j*10 - 5;
                SDL_BlitSurface(p, NULL, screen, &a);
                SDL_Flip(screen);
                SDL_Delay(10);
            }
        }
    }
}

void init(int carte[50][50]){
    int i = 0 , j = 0;
    for(i = 0 ; i < 50 ; i++){
        for(j = 0 ; j < 50 ; j++){
            carte[i][j] = 0;
        }
    }
}

void init1(int carte[50][50]){
    int i = 0 , j = 0;
    for(i = 0 ; i < 50 ; i++){
        for(j = 0 ; j < 50 ; j++){
            carte[i][j] = 1;
        }
    }
}
void init2(int carte[50][50]){
    int i = 0 , j = 0;
    for(i = 0 ; i < 50 ; i++){
        for(j = 0 ; j < 50 ; j++){
            carte[i][j] = 2;
        }
    }
}
void init3(int carte[50][50]){
    int i = 0 , j = 0;
    for(i = 0 ; i < 50 ; i++){
        for(j = 0 ; j < 50 ; j++){
            carte[i][j] = 3;
        }
    }
}
void init4(int carte[50][50]){
    int i = 0 , j = 0;
    for(i = 0 ; i < 50 ; i++){
        for(j = 0 ; j < 50 ; j++){
            carte[i][j] = 4;
        }
    }
}

void remplir(int carte[50][50]){
    carte[21][17] = 1234;
    carte[22][17] = 1234;
    carte[23][17] = 1234;
    carte[24][17] = 1234;
    carte[24][18] = 1234;
    carte[24][19] = 1234;
    carte[24][20] = 1234;
    carte[25][20] = 1234;
    carte[26][20] = 1234;
    carte[27][20] = 1234;
    carte[27][21] = 1234;
    carte[27][22] = 1234;
    carte[27][23] = 1234;
    carte[26][23] = 1234;
    carte[25][23] = 1234;
    carte[24][23] = 1234;
    carte[24][24] = 1234;
    carte[24][25] = 1234;
    carte[24][26] = 1234;
    carte[23][26] = 1234;
    carte[22][26] = 1234;
    carte[21][26] = 1234;
    carte[21][25] = 1234;
    carte[21][24] = 1234;
    carte[21][23] = 1234;
    carte[20][23] = 1234;
    carte[19][23] = 1234;
    carte[18][23] = 1234;
    carte[18][22] = 1234;
    carte[18][21] = 1234;
    carte[18][20] = 1234;
    carte[19][20] = 1234;
    carte[20][20] = 1234;
    carte[21][20] = 1234;
    carte[21][19] = 1234;
    carte[21][18] = 1234;
}
