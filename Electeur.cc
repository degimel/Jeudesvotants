#include "Electeur.hh"


void Electeur::initialise_tpsDepart(int tpsSimu){
	 _tpsDepart=rand()%(tpsSimu);
	//std::cout<< tpsSimu << "   " <<_tpsDepart <<std::endl;
}

