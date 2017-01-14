#pragma once
#include <iostream>
#include <vector>
#include "screen.hh"

class Figure{
	protected :
		SDL_Rect position;
	public :
		Figure(int abcisse, int ordonnee){position.x=abcisse; position.y=ordonnee;};
		virtual ~Figure(){};
		SDL_Rect getposition(){ return position;};		
};
