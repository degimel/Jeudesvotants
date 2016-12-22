#pragma once
#include "Figure.hh"
//#include "Electeur.hh"
class Electeur;
class Projectile : public Figure{
	protected :

		
	public :
		Projectile(int abcisse, int ordonnee) : Figure(abcisse,ordonnee){};
		virtual ~Projectile(){};
		virtual bool verifieImpact(Electeur* electeur) const=0;
		SDL_Rect& update(){ position.y+=10; return position;};
		int gety(){ return position.y;};
		int getx(){ return position.x;};
};
