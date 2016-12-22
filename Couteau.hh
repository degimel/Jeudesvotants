#pragma once
#include "Projectile.hh"
#include "Electeur.hh"

class Couteau : public Projectile{

	public :
		Couteau(int abcisse, int ordonnee):Projectile(abcisse,ordonnee){};
		~Couteau(){};
		bool verifieImpact(Electeur* electeur) const;
};
