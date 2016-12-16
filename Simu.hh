#pragma once
#include "Electeur.hh"
#include "Joueur.hh"
#include "Bombe.hh"
#include "Couteau.hh"
#include <list>
#include <vector>

class Simu{
	private :
		int _tpsCourant;
		int _tpsSimulation;
		std::list<Joueur> _listJoueurs;
		std::vector<Projectile> _listProjectiles; //à mettre à jour à chaque pas de temps
		std::vector<Electeur> _listElecteur;
	public:
		Simu(int tpsSimulation): _tpsSimulation(tpsSimulation){};
		~Simu();
		void run();
};		
