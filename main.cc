#include "Bombe.hh"
#include "Couteau.hh"
#include "Joueur.hh"
#include "Electeur.hh"
#include "screen.hh"
#include "Simu.hh"

using namespace std;
int main()
{
	SDL_Surface *ecran = NULL, *zozor = NULL, *helico=NULL, *couteau=NULL, *votant1=NULL, *votant2=NULL;
	SDL_Rect positionHelico;
    SDL_Event event;
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(700, 800, 16, SDL_HWSURFACE /*| SDL_DOUBLEBUF*/); /* Double Buffering */
    SDL_WM_SetCaption("JEU", NULL);

	helico= SDL_LoadBMP("helico.bmp");
	couteau=SDL_LoadBMP("couteau.bmp");
	votant1=SDL_LoadBMP("bonhomme.bmp");
	votant2=SDL_LoadBMP("bonhomme2.bmp");
	
	
	Simu S(3000);
	
	positionHelico.x= 100;
	positionHelico.y=1;	

	S.initialise();
	int tpsCourant=0;
    while (continuer && tpsCourant<S.get_tpsSimulation()+100)
	{
		
        	tpsCourant=S.run(ecran,helico,couteau,votant1, votant2,positionHelico, event, continuer);
		
    }
	if(S.getcpt1()>S.getcpt2()){
		cout<<"***********************"<< endl <<"BRAVO ! Vous avez gagné à "<< S.getcpt1() << "contre " << S.getcpt2() <<endl; 	
	}else{
		cout<<"***********************"<< endl <<"Perdu ! :(  vous avez eu" << S.getcpt1() << "voix contre " << S.getcpt2() << endl;
	}
		
    SDL_FreeSurface(zozor);
    SDL_Quit();
	
    return EXIT_SUCCESS;
}


