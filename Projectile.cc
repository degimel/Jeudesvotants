#include "Projectile.hh"

using namespace std;
/*1 correspond au couteau  2 correspond à la bombe*/
bool Projectile::operator==(int projectile){
	if(projectile == 1 || projectile ==2){
		if(typeProjectile==projectile){
			return true;
		}
		return false;
	}
	
	else{
		cout << "ERREUR OPERATEUR ==" << endl;
		return false;
	}
}
