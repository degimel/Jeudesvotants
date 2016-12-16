#pragma once
#include <iostream>
#include "Bonhomme.hh"
class Electeur{
	public :
		Electeur(int joueur_soutenu): _joueurSoutenu(joueur_soutenu),_dessinElecteur(5,1){}; 
		~Electeur();
		void update(){_dessinElecteur.getAbcisse()+=_vitesse;};
	private :
		int _joueurSoutenu;
		Bonhomme _dessinElecteur;
		int _vitesse;
		int _tpsDepart; //suit une loi uniforme entre 0 et Temps de la simulation
};
