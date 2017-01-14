#include "Bombe.hh"

using namespace std;

/*Cette fonction détecte si une bombe impacte un bonhomme (=un électeur), si c'est le cas elle renvoie true, sinon false*/
bool Bombe::verifieImpact(Electeur* electeur) const{
	if(position.y==549){
		if(electeur->getposition().x>position.x-200 && electeur->getposition().x<position.x+200){ //La zone d'impact est importante puisqu'il s'agit d'une bombe
			return true;
		}
	}
	return false;
}

/*Cette fonction met à jour la position de la bombe
Lorsque la bombe s'approche du sol, elle va plus lentement pour que l'on ait le temps de voir l'explosion*/
SDL_Rect& Bombe::update(){
	if(position.y<430){
		position.y+=5; 
	}
	else{
		position.y++;
	}
	return position;
}
