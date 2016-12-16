#pragma once
#include "Figure.hh"

class Projectile : public Figure{
	protected :
		int _ordonnee;
	public :
		Projectile(int abcisse, int ordonnee) : Figure(abcisse),_ordonnee(ordonnee){};
		virtual ~Projectile(){};
		virtual void DrawThemself(Screen S) const=0;
		virtual bool verifieImpact() const=0;
};
