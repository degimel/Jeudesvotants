#pragma once
#include "Electeur.hh"
#include "Joueur.hh"
#include "Bombe.hh"
#include "Couteau.hh"
#include <list>

class Simu{
	private :
		int _tpsCourant;
		int _tpsSimulation;
		std::list<Joueur> ListeJoueurs;
	public:
		Simu(int tpsSimulation): _tpsSimulation(tpsSimulation){};
		~Simu();
		void run();
};		
