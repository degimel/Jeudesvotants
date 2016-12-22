#include "Couteau.hh"

using namespace std;

bool Couteau::verifieImpact(Electeur* electeur) const{
	if(position.y>500){
		if(electeur->getposition().x>position.x-5 && electeur->getposition().x<position.x+10){ //precision + ou - 10
			return true;
		}
	}
	return false;
}
