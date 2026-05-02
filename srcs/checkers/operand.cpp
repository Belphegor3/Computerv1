#include "computerv1.hpp"

extern int check_operand(char *splitted){
	if ((strlen(splitted) != 1) || (splitted[0] != '+' && splitted[0] != '-')){
		cout << "Tiens tiens tiens mais que voila-je ðŸ¤¨? Pas un simple operateur en tout cas!\nPour rappel, le format valide est de la forme \x1b[31ma * X^p\x1b[32m, p valant 0,1 ou 2.\x1b[0m\nNombres, operateurs et inconnus doivent etre separer d\'un espace." << endl;
		return (EXIT_FAILURE);
	};
	return (EXIT_SUCCESS);
}