#pragma once
#include <iostream>
#include <vector>
#include "screen.hh"
class Figure{
	protected :
		int _abcisse;
	public :
		Figure(int abcisse): _abcisse(abcisse) {};
		virtual ~Figure(){};
		virtual void DrawThemself(Screen S) const=0;
		virtual bool verifieImpact() const=0;
};
