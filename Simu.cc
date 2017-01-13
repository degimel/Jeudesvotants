#include "Simu.hh"


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

/*Bonhommes blancs*/
void Simu::supprimer_bonhomme1(){
	for(auto it1=_listProjectiles.begin();it1!=_listProjectiles.end();++it1){
		if((*it1)->getposition().y>550){
			Projectile* copieProjectile=(*it1);
			_listProjectiles.erase(it1);
			delete (copieProjectile);
			this->supprimer_bonhomme1();
			return ;	
		}
		for(auto it2=_listElecteur2.begin();it2!=_listElecteur2.end();++it2){
			if((*it1)->verifieImpact(&(*it2))){
				Projectile* copieProjectile=(*it1);
				_listElecteur2.erase(it2);
				_listProjectiles.erase(it1);
				delete (copieProjectile); 
				this->supprimer_bonhomme1();
				return ;				
			}					
		}	
	}
}

/*Bonhommes noirs*/
void Simu::supprimer_bonhomme2(){
	for(auto it1=_listProjectiles.begin();it1!=_listProjectiles.end();++it1){
		if((*it1)->getposition().y>550){
			Projectile* copieProjectile=(*it1);
			_listProjectiles.erase(it1);
			delete (copieProjectile);
			this->supprimer_bonhomme2();
			return;	
		}			
		for(auto it2=_listElecteur1.begin();it2!=_listElecteur1.end();++it2){
			if((*it1)->verifieImpact(&(*it2))){
				Projectile* copieProjectile=(*it1);
				_listElecteur1.erase(it2);
				_listProjectiles.erase(it1);
				delete (copieProjectile);
				this->supprimer_bonhomme2();
				return;				
			}					
		}	
	}
}

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
				    case SDLK_RIGHT:
				        positionHelico.x+=10;
				        break;
				    case SDLK_LEFT:
				        positionHelico.x-=10;
				        break;
					default : 
						break;
            	}
         }
}

int Simu::run(SDL_Surface* ecran,SDL_Surface *helico,SDL_Surface *couteau,SDL_Surface *bombe, SDL_Surface *votant1,SDL_Surface *votant2,SDL_Rect& positionHelico, SDL_Event& event, int &continuer){
	/*On regarde si le joueur a appuyer sur des touches du clavier*/
	gererEvenementsClavier(event, continuer, positionHelico);
	
	//mise à jour des projectiles
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
	SDL_BlitSurface(helico, NULL, ecran, &positionHelico);

	for(auto it=_listProjectiles.begin();it!=_listProjectiles.end();it++){
		if(**it==1){ //si le projectile est un couteau
			SDL_Rect rect=(*it)->update();
			SDL_BlitSurface(couteau, NULL, ecran, &rect);
		}
		else if(**it==2){ //si le projectile est une bombe
			SDL_Rect rect=(*it)->update();
			SDL_BlitSurface(bombe, NULL, ecran, &rect);
		}
	}		

	//verifier si certains rentrent
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
	
	//verifier si certains sont arrivés : arrivée <=> abscisse=650
	
	for(auto it=_listElecteur1.begin(); it!=_listElecteur1.end();++it){
		if(it->arrivee(650)){
			_listElecteur1.erase(it); //retirer l'élement it de la liste
			cpt_vote_pour_1++;
			std::cout << "Score actuel : vous " << cpt_vote_pour_1 << "-" << cpt_vote_pour_2 << " adversaire"<< std::endl; 
			break; //pour eviter le segmentation fault
			
		}
	}
	
	for(auto it=_listElecteur2.begin(); it!=_listElecteur2.end();++it){	
		if(it->arrivee(650)){
			_listElecteur2.erase(it);
			cpt_vote_pour_2++;
			std::cout << "Score actuel : vous " << cpt_vote_pour_1 << "-" << cpt_vote_pour_2 << " adversaire"<< std::endl; 
			break; //pour éviter le segmentation fault
			
		}
	}		
	//Mise à jour des electeurs
									
	for(auto it=_listElecteur1.begin(); it!=_listElecteur1.end();it++){
		SDL_Rect rect=(*it).update();
		SDL_BlitSurface(votant1, NULL, ecran, &rect);
		
	}
	for(auto it=_listElecteur2.begin(); it!=_listElecteur2.end();it++){
		SDL_Rect rect=(*it).update();
		SDL_BlitSurface(votant2, NULL, ecran, &rect);
	}

	//Verifier impacts
	supprimer_bonhomme1();
	supprimer_bonhomme2();
	
	SDL_Flip(ecran);
	_tpsCourant++;
	return _tpsCourant;
}
