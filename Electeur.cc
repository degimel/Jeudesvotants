#include "Electeur.hh"

/*Cette fonction initialise le temps de départ d'un électeur.
Ce temps de départ suit une loi uniforme entre 0 et Temps de la simulation*/
void Electeur::initialise_tpsDepart(int tpsSimu){
	 _tpsDepart=rand()%(tpsSimu);
}

