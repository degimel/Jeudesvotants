#pragma once
#include <iostream>
#include "Figure.hh"

class Electeur : public Figure{
	public :
		/*Méthodes*/
		Electeur() : Figure(0,500){};//Les electeurs partent toujours de la gauche de l'écran
		~Electeur(){};
		SDL_Rect update(){position.x++; return position;};//Mise à jour de la position de l'électeur
		void initialise_tpsDepart(int tps_Simu);
		
		//Fonction renvoyant un booléen indiquant si l'electeur est arrivé tout à droite de l'écran
		bool arrivee(int abcsissearrivee){ return position.x>=abcsissearrivee;};
		
		/*Getter*/
		int get_tpsDepart(){ return _tpsDepart;};
		
	private :
		int _tpsDepart;
};
