#pragma once
#include "Figure.hh"
#include "Electeur.hh"
//class Electeur;
class Projectile : public Figure{
	protected :
		int typeProjectile; // Pour distinguer le type de projectile : 1 pour un couteau et 2 pour une bombe
		
	public :
		/*Méthodes*/
		Projectile(int abcisse, int ordonnee) : Figure(abcisse,ordonnee){};
		virtual ~Projectile(){};
		virtual bool verifieImpact(Electeur* electeur) const=0; //les impacts des bombes ne sont pas les mêmes que ceux des couteaux ou que des MAIN4 => fonction virtuelle
		virtual SDL_Rect& update() = 0; //On ne met pas à jour le couteau, la MAIN4 et la bombe de la même manière => fonction virtuelle
		
		/*Getter*/
		int gety(){ return position.y;};
		int getx(){ return position.x;};
		
		/*Opérateur*/
		bool operator==(int projectile);
};
