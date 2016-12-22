#pragma once
#include <iostream>
#include "Electeur.hh"
#include <vector>
#include <string>
class Joueur{
	public :
		Joueur(){};
		~Joueur(){};	
		std::vector<Electeur>&  getlistVotants(){ return listVotants;};

	private :		
		int _abcisse;
		std::vector<Electeur> listVotants;
		
	
};
