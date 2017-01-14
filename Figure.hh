#pragma once
#include <SDL.h>
#include <iostream>
#include <iostream>
#include <vector>


class Figure{
	protected :
		SDL_Rect position; //position de la figure sur l'écran (type spécial de la SDL)
	public :
		Figure(int abcisse, int ordonnee){position.x=abcisse; position.y=ordonnee;};
		virtual ~Figure(){};
		SDL_Rect getposition(){ return position;};		
};
