#pragma once
#include "Figure.hh"

class Bonhomme : public Figure{
	private :
		int _vie;
	public :
		Bonhomme(int vie, int abcisse): Figure(abcisse),_vie(vie){};
		~Bonhomme(){};
		void DrawThemself(Screen S) const;
		bool verifieImpact() const{ return 0;};
		int getAbcisse() const{ return _abcisse; }
};
