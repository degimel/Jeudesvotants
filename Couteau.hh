#pragma once
#include "Projectile.hh"
#include "Electeur.hh"

class Couteau : public Projectile{

	public :
		Couteau(int abcisse, int ordonnee):Projectile(abcisse,ordonnee){typeProjectile=1;};
		~Couteau(){};
		bool verifieImpact(Electeur* electeur) const;
		SDL_Rect& update(){ position.y+=10; return position;};
};
