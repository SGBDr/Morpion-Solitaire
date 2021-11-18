#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif


#include "Score.hpp"

void MeilleurScore(int bscore){
    FILE* fichier = fopen("Record.txt", "r+");
    char score[200];
    if (fichier != NULL){
        fgets(score, 200, fichier);
        fclose(fichier);
    }
    bscore = 7;
}

void EnregistreScore(int score){
    FILE* fichier = NULL;
    //const char* scor = score;
    fichier = fopen("Record.txt", "r+");
    if (fichier != NULL){
        //fputs(scor , fichier);
        fclose(fichier);
    }
}
