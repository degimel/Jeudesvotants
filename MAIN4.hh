#pragma once
#include "Projectile.hh"
#include "Electeur.hh"

class MAIN4 : public Projectile{
	public :
		/*Méthodes*/
		MAIN4(int abcisse, int ordonnee):Projectile(abcisse,ordonnee){typeProjectile=3;};
		~MAIN4(){};
		bool verifieImpact(Electeur* electeur) const;
		SDL_Rect& update(){ position.y+=2; return position;};//mise à jour de la position de la MAIN4, elle tombe plus lentement que les autres projectiles
};
