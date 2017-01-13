#include "Bombe.hh"
#include "Couteau.hh"
#include "Joueur.hh"
#include "Electeur.hh"
#include "screen.hh"
#include "Simu.hh"

using namespace std;
int main()
{
	SDL_Surface *ecran = NULL, *helico=NULL, *couteau=NULL, *votant1=NULL, *votant2=NULL, *bombe=NULL;
	SDL_Rect positionHelico;
    SDL_Event event;
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(700, 800, 16, SDL_HWSURFACE);
    SDL_WM_SetCaption("JEU", NULL);

	/*Chargement des images*/
	helico= SDL_LoadBMP("helico.bmp");
	couteau=SDL_LoadBMP("couteau.bmp");
	votant1=SDL_LoadBMP("bonhomme.bmp");
	votant2=SDL_LoadBMP("bonhomme2.bmp");
	bombe=SDL_LoadBMP("bombe.bmp");
	
	
	Simu S(3000);
	
	positionHelico.x= 100;
	positionHelico.y=1;	

	S.initialise();
	int tpsCourant=0;
	std::cout << "Début du jeu : vous 0-0 adversaire"<< std::endl; 
    while (continuer && tpsCourant<S.get_tpsSimulation()+100)
	{
		
        	tpsCourant=S.run(ecran,helico,couteau,votant1, votant2,positionHelico, event, continuer,bombe);
		
    }
	if(S.getcpt1()>S.getcpt2()){
		cout<<"***********************"<< endl <<"BRAVO ! Vous avez gagné à "<< S.getcpt1() << " contre " << S.getcpt2() << " !!" << endl << "Vous remportez les elections : vous avez tué assez d'opposants !!!" << endl; 	
	}else if(S.getcpt1()<S.getcpt2()){
		cout<<"***********************"<< endl <<"Perdu ! :'(  vous avez eu " << S.getcpt1() << " voix contre " << S.getcpt2() << endl << "Vous ne remportez pas les elections : vous n'avez pas tué assez d'opposants !" << endl;
	}
	else{
		cout<<"***********************"<< endl <<"Il y a" << S.getcpt1() << " voix contre " << S.getcpt2() << endl << "Il y a donc égalité : une première dans les élections !!" << endl;
	}
		
    SDL_Quit();
	
    return EXIT_SUCCESS;
}


