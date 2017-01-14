#include <SDL.h> //Bibliothèque graphique
#include <iostream>
#include <ctime>
#include "Bombe.hh"
#include "Couteau.hh"
#include "Joueur.hh"
#include "Electeur.hh"
#include "Simu.hh"


using namespace std;
int main()
{
	/*Réinitialisation de la graine*/
	srand(time(NULL)); // initialisation de rand

	/*Déclaration de l'écran et des images*/
	SDL_Surface *ecran = NULL, *helico=NULL, *couteau=NULL, *votant1=NULL, *votant2=NULL, *bombe=NULL, *MAIN4=NULL;
	SDL_Rect positionHelico;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(700, 600, 16, SDL_HWSURFACE);
    SDL_WM_SetCaption("JEU DES VOTANTS", NULL);

	/*booléen qui va permettre de quitter une partie en cours en appuyant sur la touche echap*/
    int continuer = 1;

	/*Chargement des images*/
	helico= SDL_LoadBMP("helico.bmp");
	couteau=SDL_LoadBMP("couteau.bmp");
	votant1=SDL_LoadBMP("bonhomme.bmp");
	votant2=SDL_LoadBMP("bonhomme2.bmp");
	bombe=SDL_LoadBMP("bombe.bmp");
	MAIN4=SDL_LoadBMP("MAIN4.bmp");
	
	/*Initialement, l'hélicoptère se trouve dans le coin gauche de la fenêtre*/
	positionHelico.x= 100;
	positionHelico.y=1;	
	
	/*Déclaration et initialisation de la simulation*/
	Simu S(3000);	
	S.initialise();
	int tpsCourant=0;
	std::cout << "Début du jeu : vous 0-0 adversaire"<< std::endl; 
	
	/*Tant que la simulation n'est pas finie, on met à jour l'interface graphique*/
    while (continuer && (tpsCourant<S.get_tpsSimulation() || S.getListElecteur1().size()!=0 || S.getListElecteur2().size()!=0))
	{
        tpsCourant=S.run(ecran,helico,couteau,bombe,MAIN4,votant1, votant2,positionHelico, event, continuer);
    }
    
    /*Affichage des scores à la fin de la simulation*/
    if(continuer){
		if(S.getcpt1()>S.getcpt2()){
			cout<<"***********************"<< endl <<"BRAVO ! Vous avez gagné à "<< S.getcpt1() << " contre " << S.getcpt2() << " !!" << endl << "Vous remportez les élections : vous avez tué assez d'opposants !!!" << endl; 	
		}else if(S.getcpt1()<S.getcpt2()){
			cout<<"***********************"<< endl <<"Perdu ! :'(  vous avez eu " << S.getcpt1() << " voix contre " << S.getcpt2() << endl << "Vous ne remportez pas les élections : vous n'avez pas tué assez d'opposants !" << endl;
		}
		else{
			cout<<"***********************"<< endl <<"Il y a " << S.getcpt1() << " voix contre " << S.getcpt2() << endl << "Il y a donc égalité : une première dans les élections !!" << endl;
		}
	}
	else{
		cout << "***********************"<< endl << "Vous avez abandonné la partie" << endl;
	}
	
	/*On quitte la SDL*/
    SDL_Quit();
    return EXIT_SUCCESS;
}


