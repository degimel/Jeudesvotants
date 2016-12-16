#include "Bombe.hh"
#include "Couteau.hh"
#include "Joueur.hh"
#include "Electeur.hh"
#include "screen.hh"

typedef struct
{
   char key[SDLK_LAST];
   int mousex,mousey;
   int mousexrel,mouseyrel;
   char mousebuttons[8];
   char quit;
} Input;



void UpdateEvents(Input* in)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            in->key[event.key.keysym.sym]=1;
            break;
        case SDL_KEYUP:
            in->key[event.key.keysym.sym]=0;
            break;
        case SDL_MOUSEMOTION:
            in->mousex=event.motion.x;
            in->mousey=event.motion.y;
            in->mousexrel=event.motion.xrel;
            in->mouseyrel=event.motion.yrel;
            break;
        case SDL_MOUSEBUTTONDOWN:
            in->mousebuttons[event.button.button]=1;
            break;
        case SDL_MOUSEBUTTONUP:
            in->mousebuttons[event.button.button]=0;
            break;
        case SDL_QUIT:
            in->quit = 1;
            break;
        default:
            break;
        }
    }
}


//int main(){
	/*Screen S(500,500);
	while(1){
		S.disc(10,470,5);
		S.line(10,490,10,470);	
		S.line(10,490,13,500);
		S.line(10,490,7,500);	
		S.line(10,480,15,480);
		S.line(10,480,5,480);
		S.flip();
	}
	return 0;*/
	
int main()
{
   Input in;
    // init SDL, chargement, tout ce que vous faites avant la boucle.
    memset(&in,0,sizeof(in));
    while(!in.key[SDLK_ESCAPE] && !in.quit)
    {
        UpdateEvents(&in);
        if (in.mousebuttons[SDL_BUTTON_LEFT])
        {
            in.mousebuttons[SDL_BUTTON_LEFT] = 0;
            // fait une seule fois.
        }       
        if (in.key[SDLK_UP] && in.key[SDLK_LEFT])
                {               // simplification de la gestion des touches

                }
    }
    return 0;
}


