#include "Couteau.hh"

using namespace std;

/*Cette fonction détecte si une bombe impacte un bonhomme (=un électeur), si c'est le cas elle renvoie true, sinon false*/
bool Couteau::verifieImpact(Electeur* electeur) const{
	if(position.y==500){
		if(electeur->getposition().x>position.x-30 && electeur->getposition().x<position.x+30){ //La zone d'impact est bien moins importante que pour une bombe
			return true;
		}
	}
	return false;
}
