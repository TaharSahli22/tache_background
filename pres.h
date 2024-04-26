#ifndef PERS_H_INCLUDED
#define PERS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>//bibilo_sdl
#include <SDL/SDL_image.h>//  biblio _image
#include <SDL/SDL_mixer.h>// biblio_audio
#include <SDL/SDL_ttf.h>//bibilo_text font 



//strcture de personnage
typedef struct
{
  	SDL_Surface *image_p; 
  	SDL_Rect pos_perso; //pos de perso contient x,y,w,h
}Personne;


//-------//initialiser le perso----------------------------
void initialiserperso(Personne *perso);

//--------------//fonction pour faire d'eplacement d'un perso-----------
void deplacer_perso(Personne *perso,SDL_Event event);

//----------- //affichage d'un perso----------
void afficher_perso(SDL_Surface *screen,Personne perso);

//---------------//liberation d'un perso---------------------
void free_perso(Personne perso);










#endif
