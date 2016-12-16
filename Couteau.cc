#include "Couteau.hh"

using namespace std;

void Couteau::DrawThemself(Screen S) const{
	while(1){
		S.line(_abcisse,_ordonnee,_abcisse,_ordonnee+5);
//Il faut mettre à jour le couteau et incrémenter son ordonnée à chaque pas de temps
		S.flip();
	}
}	
