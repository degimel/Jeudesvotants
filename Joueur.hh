#pragma once
#include <iostream>
#include "Electeur.hh"
#include <vector>
#include <string>
class Joueur{
	public :
		Joueur(){};
		~Joueur(){};
		
		/*Getter*/
		std::vector<Electeur>&  getlistVotants(){ return listVotants;};
		
	private :		
		int _abcisse;
		std::vector<Electeur> listVotants; //Liste des votants qui soutiennent le joueur
};
