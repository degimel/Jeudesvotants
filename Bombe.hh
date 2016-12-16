#pragma once
#include "Projectile.hh"

class Bombe : public Projectile{
	public :
		Bombe(int abcisse, int ordonnee):Projectile(abcisse,ordonnee){};
		~Bombe(){};
		void DrawThemself(Screen S) const;
		bool verifieImpact() const{ return 0;};
};
