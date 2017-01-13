#include "Bombe.hh"

using namespace std;

bool Bombe::verifieImpact(Electeur* electeur) const{
	if(position.y==549){
		if(electeur->getposition().x>position.x-200 && electeur->getposition().x<position.x+200){ //precision à revoir
			return true;
		}
	}
	return false;
}

SDL_Rect& Bombe::update(){
	if(position.y<430){
		position.y+=5; 
	}
	else{
		position.y++;
	}
	return position;
}
