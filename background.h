#ifndef BACKGROUND_H_INCLUDE
#define BACKGROUND_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "pres.h"
#define SCREEN_W 1360 
#define SCREEN_H 765

typedef struct
{
	SDL_Surface *imgback; 
	SDL_Rect posback2; 
	
	
	SDL_Rect camera2;
	Mix_Music *son1; 
	Mix_Music *son; 
	
 
	SDL_Surface *image_bats;  
	
	SDL_Rect single_bats;	 
	SDL_Rect pos_image_bats;
	
	int bats_f; 
}background;


// pour initialiser une back-----------------
void initBack2(background *b); 

//pour afficher une back --------------------
void afficheBack2 (background b, SDL_Surface *ecran);

//srolling permet de deplacer------------
void scrolling (background *b,int direction,int pas);

//animation 
void animerBackground(background *b);

void displaybats(background b,SDL_Surface *ecran);
void afficher(background b,SDL_Surface *ecran);


#endif  
