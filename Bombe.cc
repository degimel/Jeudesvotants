#include "Bombe.hh"

using namespace std;

bool Bombe::verifieImpact(Electeur* electeur) const{
	if(position.y>500){
		if(electeur->getposition().x>position.x-50 && electeur->getposition().x<position.x+65){ //precision à revoir
			return true;
		}
	}
	return false;
}
