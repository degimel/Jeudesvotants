#include "Couteau.hh"

using namespace std;

bool Couteau::verifieImpact(Electeur* electeur) const{
	if(position.y==500){
		if(electeur->getposition().x>position.x-30 && electeur->getposition().x<position.x+30){ //precision à revoir
			return true;
		}
	}
	return false;
}
