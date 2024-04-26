#include "background.h"
#include "pres.h"
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

void initBack2 (background *b)
{
//background2
b->imgback=IMG_Load("back.png");
b->posback2.x=0;
b->posback2.y=0;
// pour camera2  de scrolling  
b->camera2.x=0;
b->camera2.y=400;
b->camera2.w=SCREEN_W; 
b->camera2.h=SCREEN_H;
// a propos musique

        b->son1=Mix_LoadMUS("son.mp3"); //Chargement de la musique 2
        b->son=Mix_LoadMUS("musique.mp3"); //Chargement de la musique 1
        
	b->image_bats=IMG_Load("bats.png");   
	
	b->pos_image_bats.x=500;
	b->pos_image_bats.y=100;
	

	b->single_bats.w=100;
	b->single_bats.h=100;
		
	b->single_bats.x=0; 
	b->single_bats.y=0;
	

	b->bats_f=0; 


}


//---------------affichage background ------------------
void afficheBack2(background b, SDL_Surface *ecran)
{
 

//-------------Jouer infiniment la musique---------------------------------
if(b.camera2.x<300)
{
Mix_PlayMusic(b.son, -1); 
}

else if(300<b.camera2.x<400) 
{
Mix_PlayMusic(b.son1, -1); 
}
SDL_BlitSurface(b.imgback,&b.camera2,ecran,&b.posback2);
displaybats(b,ecran);

}
//--------------permet d'afficher une partie du backg-------
void scrolling (background *b,int direction,int pas) 
{

if (direction ==0){//a droite du back1  


	b->camera2.x+= pas;
	
        }
else if (direction ==1){//a gauche du back1          


	b->camera2.x-=pas;  
	}

else if (direction ==2){


         b->camera2.y-= pas; 
	}
else if (direction ==3){       


	 b->camera2.y+= pas;
	 }

}


//affichage 
void displaybats(background b,SDL_Surface *ecran){

 		
 		SDL_BlitSurface(b.image_bats,&(b.single_bats), ecran, &b.pos_image_bats);
}






void animerBackground(background *b){   
		
			
	if (b->bats_f >=0 && b->bats_f <6) {
	b->single_bats.x=  b->bats_f * b->single_bats.w; 
	b->bats_f++; 
	}
	
	if ( b->bats_f == 6) {
	b->single_bats.x=b->bats_f * b->single_bats.w;
	b->bats_f=0; 
	}
 
	 
}







 

