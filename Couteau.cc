#include "Couteau.hh"

using namespace std;

bool Couteau::verifieImpact(Electeur* electeur) const{
	if(position.y>400){
		if(electeur->getposition().x>position.x-2 && electeur->getposition().x<position.x+2){ //precision + ou - 10
			return true;
		}
	}
	return false;
}
