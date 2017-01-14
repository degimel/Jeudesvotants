#include "MAIN4.hh"

using namespace std;

/*Cette fonction détecte si une MAIN4 impacte un bonhomme (=un électeur), si c'est le cas elle renvoie true, sinon false*/
bool MAIN4::verifieImpact(Electeur* electeur) const{
	if(position.y==500){
		if(electeur->getposition().x>position.x-100 && electeur->getposition().x<position.x+100){ //La zone d'impact est bien moins importante que pour une bombe
			return true;
		}
	}
	return false;
}
