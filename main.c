#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include "background.h"
#include "pres.h"
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

int main(void)
{	
	int nbr_de_pas=1;
	
	int aller=1;
	SDL_Surface *screen=NULL;
	background bg;
	int score=0;
	Personne perso;
	SDL_Event event;
        
        
	
	
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	screen=SDL_SetVideoMode(1360,1200,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode:%s\n",SDL_GetError());
		return 1;
	}
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

           
	initBack2(&bg);//initialisation de back
	

	initialiserperso(&perso);


	while (aller)
	{		
		deplacer_perso(&perso,event);
		
		SDL_PollEvent(&event);
     	switch(event.type)
        {
            case SDL_QUIT:
                aller = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
			case SDLK_RIGHT: //kif nmchy all imin 
 if(bg.camera2.x<458){
printf("main la pos est y=%d et x=%d\n",bg.camera2.y,bg.camera2.x);
				scrolling(&bg,0,nbr_de_pas);}	//scrolling;	

		
					
                        break;
  
                        case SDLK_LEFT: //ki nemchi all isar
 
                   
      if(bg.camera2.x>0){
				scrolling(&bg,1,nbr_de_pas);}//scrollling gauche 


		 
                        break;
			 case SDLK_UP://all iminn 
                            printf("main la pos est y=%d et x=%d\n",bg.camera2.y,bg.camera2.x);
			 
 if(bg.camera2.y>254){
					scrolling(&bg,2,nbr_de_pas);} //all imin
	

                        break;
                        
 	case SDLK_DOWN: 
 	//aall isar 
 	
 		if(bg.camera2.y<465){

					scrolling(&bg,3,nbr_de_pas);}	//all isar 	
                        break;	
      		 }
      		 	
            break;

       
       
  
 	}  


               		animerBackground(&bg);	
			afficheBack2(bg,screen);


			afficher_perso(screen,perso);	
                 
			SDL_Flip(screen);
	}



	
	SDL_Quit();
	 Mix_FreeMusic (bg.son1);
      Mix_FreeMusic (bg.son);
     
 Mix_CloseAudio();

	return 1;
}
