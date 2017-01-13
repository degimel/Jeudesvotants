#pragma once
#include "Projectile.hh"
#include "Electeur.hh"

class Bombe : public Projectile{
	public :
		Bombe(int abcisse, int ordonnee):Projectile(abcisse,ordonnee){typeProjectile=2;};
		~Bombe(){};
		bool verifieImpact(Electeur* electeur) const;
		SDL_Rect& update();
};


