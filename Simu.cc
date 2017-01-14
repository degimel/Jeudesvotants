#include "Simu.hh"

/*Initialisation de la simulation : cette fonction crée les listes de votants en fonction des 
paramètres du jeu et initialise aléatoirement (loi uniforme sur la durée de la simulation) leur
temps de départ*/ 
void Simu::initialise(){
		for(int i=0;i<NBTOTALVOTANT1;i++){
			Electeur electeur;
			joueur1.getlistVotants().push_back(electeur);
		}
		for(int i=0;i<NBTOTALVOTANT2;i++){
			Electeur electeur;
			joueur2.getlistVotants().push_back(electeur);
		}
		for(auto it=joueur1.getlistVotants().begin();it<joueur1.getlistVotants().end();it++){
			it->initialise_tpsDepart(_tpsSimulation);
		}
		for(auto it=joueur2.getlistVotants().begin();it<joueur2.getlistVotants().end();it++){
			it->initialise_tpsDepart(_tpsSimulation);
		}	
}

/*Cette fonction met à jour toute la simulation pour un pas de temps*/
int Simu::run(SDL_Surface* ecran,SDL_Surface *helico,SDL_Surface *couteau,SDL_Surface *bombe,SDL_Surface *MAIN4, SDL_Surface *votant1,SDL_Surface *votant2,SDL_Rect& positionHelico, SDL_Event& event, int &continuer){
	/*On regarde si le joueur a appuyer sur des touches du clavier*/
	gererEvenementsClavier(event, continuer, positionHelico);
	
	/*Gestion du fond de l'écran*/
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
	
	/*Mise à jour de la position de l'hélico dans la fenêtre graphique*/
	SDL_BlitSurface(helico, NULL, ecran, &positionHelico);		
	
	/*Mise à jour del'affichage des projectiles*/
	MajAffichageProjectiles(ecran,couteau,bombe,MAIN4);		

	/*Vérifier si certains rentrent*/
	checkEntrants();
	
	/*Vérifier si certains sont arrivés : arrivée <=> abscisse=650*/
	checkArrivees();
					
	/*Mise à jour de l'affichage des électeurs*/
	MajAffichageElecteurs(ecran,votant1,votant2);			
	
	/*Verifier impacts et supprimer des bonhommes si nécessaire*/
	supprimer_bonhomme1();
	supprimer_bonhomme2();
	
	/*Mise à jour de la fenêtre*/
	SDL_Flip(ecran);
	
	/*Mise à jour du temps courant*/
	_tpsCourant++;
	
	return _tpsCourant;
}

/************************************************************************************************
						Fonctions intermédiaires appelées dans run()
*************************************************************************************************/

/*Cette fonction détecte si une touche du clavier a été enfoncée. Lorsque l'on appuie sur :
	- échap : le jeu s'arrête
	- flèche du haut : on lâche une bombe depuis l'hélicoptère
	- flèche du bas : on jette un couteau depuis l'hélicoptère
	- touche M : on jette une MAIN4 depuis l'hélicoptère
	- flèches de droite et de gauche : on déplace l'hélicoptère*/
void Simu::gererEvenementsClavier(SDL_Event& event,int &continuer,SDL_Rect& positionHelico){
		SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){         
					case SDLK_ESCAPE:
						continuer=0;
						break;
					case SDLK_UP:{
				    	Bombe* bombe=new Bombe(positionHelico.x,0);					 
						_listProjectiles.push_back(bombe);
						}
				        break;
				    case SDLK_DOWN:{
						Couteau* couteau=new Couteau(positionHelico.x,0);
						 _listProjectiles.push_back(couteau);
						}
				        break;
				    case SDLK_m:{
				    	MAIN4* Main=new MAIN4(positionHelico.x,0);					 
						_listProjectiles.push_back(Main);
				    }
				    break;
				    case SDLK_RIGHT:
				    	if(positionHelico.x<630){//L'hélicoptère ne sort pas de l'écran
				        	positionHelico.x+=10;
				        }
				        break;
				    case SDLK_LEFT:
				        positionHelico.x-=10;
				        break;
					default : 
						break;
            	}
         }
}

/*Cette fonction met à jour les projectiles sur la fenêtre graphique*/
void Simu::MajAffichageProjectiles(SDL_Surface* ecran,SDL_Surface *couteau,SDL_Surface *bombe,SDL_Surface *MAIN4){
	
	for(auto it=_listProjectiles.begin();it!=_listProjectiles.end();it++){
		/*si le projectile est un couteau*/
		if(**it==1){
			SDL_Rect rect=(*it)->update();
			SDL_BlitSurface(couteau, NULL, ecran, &rect);
		}
		/*si le projectile est une bombe*/
		else if(**it==2){ 
			SDL_Rect rect=(*it)->update();
			SDL_BlitSurface(bombe, NULL, ecran, &rect);
		}
		/*si le projectile est une MAIN4*/
		else if(**it==3){ 
			SDL_Rect rect=(*it)->update();
			SDL_BlitSurface(MAIN4, NULL, ecran, &rect);
		}
	}
}

/*Cette fonction regarde si un ou plusieurs bonhommes doivent rentrer à cet instant de la simulation.
 Si c'est le cas, on ajoute le bonhomme à la bonne liste d'electeurs de la simulation */
void Simu::checkEntrants(){
	for(auto it=joueur1.getlistVotants().begin();it<joueur1.getlistVotants().end();it++){
		if(it->get_tpsDepart()==_tpsCourant){
			_listElecteur1.push_back(*it);
		}
	}
	for(auto it=joueur2.getlistVotants().begin();it<joueur2.getlistVotants().end();it++){
		if(it->get_tpsDepart()==_tpsCourant){
			_listElecteur2.push_back(*it);
		}
	}
}

/*Cette fonction regarde si un bonhomme est arrivé tout à droite de l'écran. Si c'est le cas, on rajoute
1 point au joueur soutenu par ce bonhomme*/
void Simu::checkArrivees(){
	for(auto it=_listElecteur1.begin(); it!=_listElecteur1.end();++it){
		if(it->arrivee(650)){
			_listElecteur1.erase(it); //retirer l'electeur (=bonhomme) it de la liste
			cpt_vote_pour_1++;
			std::cout << "Score actuel : vous " << cpt_vote_pour_1 << "-" << cpt_vote_pour_2 << " adversaire"<< std::endl; 
			/*Lorsque que l'on supprime un électeur dans le liste, la liste change, et donc également l'itérateur, 
			ainsi on appelle récursivement cette fonction (avec la nouvelle liste de d'électeurs) ; si on ne l'appelle
			pas récursivement cette fonction, des erreurs surviennent*/
			checkArrivees();
			return;
		}
	}
	
	for(auto it=_listElecteur2.begin(); it!=_listElecteur2.end();++it){	
		if(it->arrivee(650)){
			_listElecteur2.erase(it);
			cpt_vote_pour_2++;
			std::cout << "Score actuel : vous " << cpt_vote_pour_1 << "-" << cpt_vote_pour_2 << " adversaire"<< std::endl; 
			checkArrivees();
			return;	
		}
	}
}

/*Cette fonction met à jour les électeurs sur la fenêtre graphique*/
void Simu::MajAffichageElecteurs(SDL_Surface* ecran,SDL_Surface *votant1,SDL_Surface *votant2){
	for(auto it=_listElecteur1.begin(); it!=_listElecteur1.end();it++){
		SDL_Rect rect=(*it).update();
		SDL_BlitSurface(votant1, NULL, ecran, &rect);
		
	}
	for(auto it=_listElecteur2.begin(); it!=_listElecteur2.end();it++){
		SDL_Rect rect=(*it).update();
		SDL_BlitSurface(votant2, NULL, ecran, &rect);
	}
}

/*Cette fonction fait deux choses : 
  - elle regarde si un projectile est arrivé en bas de l'écran (sans qu'il n'ait fait de victimes), si c'est le cas, elle
  supprime ce projectile
  - elle regarde s'il y a impact entre un projectile et un bonhomme soutenant le joueur 1, et supprime le projectile et les 
  bonhommes impactés*/
void Simu::supprimer_bonhomme1(){
	for(auto it1=_listProjectiles.begin();it1!=_listProjectiles.end();++it1){
		if((*it1)->getposition().y>550){
			Projectile* copieProjectile=(*it1);
			_listProjectiles.erase(it1);
			delete (copieProjectile);
			/*Lorsque que l'on supprime un projectile, la liste de projectiles change, et donc également l'itérateur, 
			ainsi on appelle récursivement cette fonction (avec la nouvelle liste de projectiles) ; si on ne l'appelle
			pas récursivement cette fonction, des erreurs surviennent*/
			this->supprimer_bonhomme1();
			return;	
		}			
		for(auto it2=_listElecteur1.begin();it2!=_listElecteur1.end();++it2){
			if((*it1)->verifieImpact(&(*it2))){
				Projectile* copieProjectile=(*it1);
				_listElecteur1.erase(it2);
				_listProjectiles.erase(it1);
				delete (copieProjectile);
				this->supprimer_bonhomme1();
				return;				
			}					
		}	
	}
}

/*Cette fonction fait la même chose que la précédente, mais regarde les impacts entre les projectiles et les bonhommes
soutenant le joueur 2 (et non le 1)*/
void Simu::supprimer_bonhomme2(){
	for(auto it1=_listProjectiles.begin();it1!=_listProjectiles.end();++it1){
		if((*it1)->getposition().y>550){
			Projectile* copieProjectile=(*it1);
			_listProjectiles.erase(it1);
			delete (copieProjectile);
			this->supprimer_bonhomme2();
			return;	
		}
		for(auto it2=_listElecteur2.begin();it2!=_listElecteur2.end();++it2){
			if((*it1)->verifieImpact(&(*it2))){
				Projectile* copieProjectile=(*it1);
				_listElecteur2.erase(it2);
				_listProjectiles.erase(it1);
				delete (copieProjectile); 
				this->supprimer_bonhomme2();
				return;				
			}					
		}	
	}
}
