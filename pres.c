#include "pres.h"
//---------------//initialisation d'un perso ----------------------
void initialiserperso(Personne *perso)
{	
	perso->image_p=IMG_Load("perso.bmp");
	perso->pos_perso.x=0;
	perso->pos_perso.y=300;
	perso->pos_perso.w=120; //largeur
	perso->pos_perso.h=120; //hauteur 
	
//photo en position  y=300 et x=0
}

//----------------------//affichage d'un perso ------------------

void afficher_perso(SDL_Surface *screen,Personne perso)
{	
	SDL_BlitSurface(perso.image_p,NULL,screen,&perso.pos_perso);
}

//---------------deplacement d'un personnage ------------------------

void deplacer_perso(Personne *perso,SDL_Event event)
{	

         switch(event.type)
            {
                case SDL_KEYDOWN:                     //clavier 
                       switch(event.key.keysym.sym)
                        {
                        
     
                       case SDLK_UP:     	//fleche foukani 
                       
                       
if(perso->pos_perso.y>0){
                            perso->pos_perso.y = perso->pos_perso.y-2; 
           /*affichage*/  printf("la pos  de perso  de perso est y=%d et x=%d\n",perso->pos_perso.y,perso->pos_perso.x);
}
                            break;
                        case SDLK_DOWN:   //fleche lutani                   
if(perso->pos_perso.y<430){
                            perso->pos_perso.y=perso->pos_perso.y+2;  
      /*affichage*/       printf("la pos de perso  est y=%d et x=%d\n",perso->pos_perso.y,perso->pos_perso.x);
}
                            break;
                        case SDLK_RIGHT: //fleche ali min   
if(perso->pos_perso.x<870){
                            perso->pos_perso.x=perso->pos_perso.x+2;
                     /*affichage*/ printf("la pos de perso  est y=%d et x=%d\n",perso->pos_perso.y,perso->pos_perso.x);
}
                            break;
                        case SDLK_LEFT: //flech alii sar 
if(perso->pos_perso.x>0){
                            perso->pos_perso.x=perso->pos_perso.x-2; 
                           
        /*affichage*/  printf("la pos de perso  est y=%d et x=%d\n",perso->pos_perso.y,perso->pos_perso.x);
}
                            break;
                        }
                 break;
             }
}

//-------------------------liberation de perso------------------------------
void free_perso(Personne perso)
{
	SDL_FreeSurface(perso.image_p);
}















