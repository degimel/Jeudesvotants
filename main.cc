#include "Bombe.hh"
#include "Couteau.hh"
#include "Joueur.hh"
#include "Electeur.hh"
#include "screen.hh"

int main()
{
	SDL_Surface *ecran = NULL, *zozor = NULL, *helico=NULL;
    SDL_Rect positionZozor;
	SDL_Rect positionHelico;
    SDL_Event event;
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(700, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); /* Double Buffering */
    SDL_WM_SetCaption("Gestion des évènements en SDL", NULL);
    
	zozor = SDL_LoadBMP("bonhomme.bmp");
	helico= SDL_LoadBMP("helico.bmp");
    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));

    positionZozor.x = 0;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;

	positionHelico.x= 100;
	positionHelico.y=5;	
    SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */
    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
//						case SDLK_UP:
//                      positionZozor.y--;
//                      break;
//                    case SDLK_DOWN:
//                       positionZozor.y++;
//                        break;
                    case SDLK_RIGHT:
                        positionHelico.x++;
                        break;
                    case SDLK_LEFT:
                        positionHelico.x--;
                        break;
					default : 
						break;
                }
                break;
        }
		positionZozor.x++;
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
		SDL_BlitSurface(helico, NULL, ecran, &positionHelico);
        SDL_Flip(ecran);
    }
    SDL_FreeSurface(zozor);
    SDL_Quit();
    return EXIT_SUCCESS;
}


