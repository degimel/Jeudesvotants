#pragma once
#include <iostream>
#include <ctime>
#include "Figure.hh"
//#include "Bonhomme.hh"

class Electeur : public Figure{
	public :
		Electeur() : Figure(0,605){};
		~Electeur(){};
		SDL_Rect update(){position.x++; return position;};
		void initialise_tpsDepart(int tps_Simu);
		void initialise_vitesse(){};
		int get_tpsDepart(){ return _tpsDepart;};
		bool arrivee(int abcsissearrivee){ return position.x>=abcsissearrivee;};
	private :

		int _vitesse;
		int _tpsDepart; //suit une loi uniforme entre 0 et Temps de la simulation
};


