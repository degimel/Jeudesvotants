#pragma once
#include "Figure.hh"
#include "Electeur.hh"
//class Electeur;
class Projectile : public Figure{
	protected :
		int typeProjectile; // 1:couteau ; 2 bombe
		
	public :
		Projectile(int abcisse, int ordonnee) : Figure(abcisse,ordonnee){};
		virtual ~Projectile(){};
		virtual bool verifieImpact(Electeur* electeur) const=0;
		virtual SDL_Rect& update() = 0; //On ne met pas à jour le couteau et la bombe de la même manière
		int gety(){ return position.y;};
		int getx(){ return position.x;};
		bool operator==(int projectile);
};
