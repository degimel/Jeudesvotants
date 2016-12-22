#pragma once
#include "Electeur.hh"
#include "Joueur.hh"
#include "Bombe.hh"
#include "Couteau.hh"
#include <list>
#include <vector>
#define NBTOTALVOTANT1 5
#define NBTOTALVOTANT2 5
class Simu{
	
	private :
		int _tpsCourant;
		int _tpsSimulation;
		int cpt_vote_pour_1;
		int cpt_vote_pour_2;
		Joueur joueur1;
		Joueur joueur2;
		//std::list<Joueur> _listJoueurs;
		std::vector<Projectile*> _listProjectiles; //à mettre à jour à chaque pas de temps
		std::vector<Electeur> _listElecteur1; //votent pour 1
		std::vector<Electeur> _listElecteur2; //votent pour 2
	public:
		void supprimer_bonhomme1();
		void supprimer_bonhomme2();
		Simu(int tpsSimulation): _tpsSimulation(tpsSimulation){cpt_vote_pour_1=0; cpt_vote_pour_2=0;_tpsCourant=0;};
		~Simu(){};
		void initialise();
		int getcpt1(){ return cpt_vote_pour_1;;};
		int getcpt2(){ return cpt_vote_pour_2;};
		int get_tpsSimulation(){ return _tpsSimulation;};
		int run(SDL_Surface *ecran,SDL_Surface* helico,SDL_Surface *couteau,SDL_Surface *votant1,SDL_Surface *votant2,SDL_Rect& positionHelico,SDL_Event& event, int &continuer);
};		



