#include "computerv1.hpp"

extern void check_intruder(string equation){
	size_t intruder = equation.find_first_not_of("0123456789X*-+^=. ");

	if (intruder != string::npos){
		cout << "\x1b[5;31mLe caractere " << equation[intruder] << " n\'est pas reconnu\x1b[0m" << endl;
		cout << "Ce programme sert a resoudre des polynomes du premier et du second degres en utilisant \'X\' comme inconnu (en majuscule).\n\x1b[32mCependant, veillez bien respecter le format \x1b[31ma * X^p\x1b[32m, p valant 0,1 ou 2.\x1b[0m" << endl;
		exit(EXIT_FAILURE);
	}
}