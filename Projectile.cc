#include "Projectile.hh"

using namespace std;

/*Cet opérateur permet de savoit si le projectile est un couteau ou une bombe
1 correspond au couteau  2 correspond à la bombe et 3 à la MAIN4*/
bool Projectile::operator==(int projectile){
	if(projectile == 1 || projectile ==2 || projectile==3){
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
