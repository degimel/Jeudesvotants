#pragma once
#include "Electeur.hh"
#include "Joueur.hh"
#include "Bombe.hh"
#include "Couteau.hh"
#include "MAIN4.hh"
#include <list>
#include <vector>

/*Paramètres du jeu*/
#define NBTOTALVOTANT1 40
#define NBTOTALVOTANT2 60

class Simu{
	private :
		int _tpsCourant;
		int _tpsSimulation;
		int cpt_vote_pour_1;
		int cpt_vote_pour_2;
		Joueur joueur1;//Le joueur qui joue est le joueur 1
		Joueur joueur2;//L'opposant est le joueur 2
		std::vector<Projectile*> _listProjectiles;
		std::vector<Electeur> _listElecteur1; //votent pour 1
		std::vector<Electeur> _listElecteur2; //votent pour 2
		
	public:
		/*Méthodes*/
		Simu(int tpsSimulation): _tpsSimulation(tpsSimulation){cpt_vote_pour_1=0; cpt_vote_pour_2=0;_tpsCourant=0;};
		~Simu(){};
		void initialise();
		int run(SDL_Surface *ecran,SDL_Surface* helico,SDL_Surface *couteau,SDL_Surface *bombe,SDL_Surface *MAIN4,SDL_Surface *votant1,SDL_Surface *votant2,SDL_Rect& positionHelico,SDL_Event& event, int &continuer);
		void gererEvenementsClavier(SDL_Event& event,int &continuer,SDL_Rect& positionHelico);
		void MajAffichageProjectiles(SDL_Surface* ecran,SDL_Surface *couteau,SDL_Surface *bombe,SDL_Surface *MAIN4);
		void checkEntrants();
		void checkArrivees();
		void MajAffichageElecteurs(SDL_Surface* ecran,SDL_Surface *votant1,SDL_Surface *votant2);
		void supprimer_bonhomme1();
		void supprimer_bonhomme2();
		
		/*Getter*/
		int getcpt1(){ return cpt_vote_pour_1;};
		int getcpt2(){ return cpt_vote_pour_2;};
		int get_tpsSimulation(){ return _tpsSimulation;};
		std::vector<Electeur>& getListElecteur1(){return _listElecteur1;};
		std::vector<Electeur>& getListElecteur2(){return _listElecteur2;};
};
