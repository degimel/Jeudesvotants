#pragma once
#include <iostream>
#include "Electeur.hh"
#include <vector>
#include <string>
class Joueur{
	public :
		Joueur();
		~Joueur(){};	
		void DrawThemself(Screen S) const;
		void update_gauche(){_abcisse--;}
		void update_droite(){_abcisse++;}
		//Rajouter peut-être une méthode pour supprimer un votant
	private :		
		static int numeroJoueur;
		int _abcisse;
		std::vector<Electeur> listVotants;
		//int nbre_votants_arrives;
		//int nbre_adversaires_arrives;
};
