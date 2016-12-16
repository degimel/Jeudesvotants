#include "Bonhomme.hh"

using namespace std;

void Bonhomme::DrawThemself(Screen S) const{
	while(1){
		S.disc(_abcisse,470,5);
		S.line(_abcisse,490,_abcisse,470);	
		S.line(_abcisse,490,_abcisse+3,500);
		S.line(_abcisse,490,_abcisse-3,500);	
		S.line(_abcisse,480,_abcisse+5,480);
		S.line(_abcisse,480,_abcisse-5,480);
		S.flip();
	}
	
}
