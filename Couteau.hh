#pragma once
#include "Projectile.hh"

class Couteau : public Projectile{

	public :
		Couteau(int abcisse, int ordonnee):Projectile(abcisse,ordonnee){};
		~Couteau(){};
		void DrawThemself(Screen S) const;
		bool verifieImpact() const{ return 0;};
		void update(){ _ordonnee++;};
};
