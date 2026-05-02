#include "computerv1.hpp"

extern int check_variable(char *splitted, double *nb){
	char *endptr;

	if (splitted[0] == '.'){
		cout << "Un nombre ne commence pas par un \'.\', a la limite veillez ecrire le 0 devant pour que le format soit respecte parce que c\'est moi qui decide" << endl;
		return (EXIT_FAILURE);
	}
	if (splitted[0] == '+' || splitted[0] == '*' || splitted[0] == '^'){
		cout << "\x1b[31mVeillez taper une equation valide ðŸ§\x1b[0m\n";
		return (EXIT_FAILURE);
	}
	else if (splitted[0] == 'X'){
		cout << "\x1b[32mVeillez bien respecter le format \x1b[31ma * X^p\x1b[32m, p valant 0,1 ou 2.\x1b[0m" << endl;
		return (EXIT_FAILURE);
	}
	else{
		*nb = strtod(splitted, &endptr);
		if (!endptr){
			cout << "Caractere suspect detecte dans " << splitted << " \x1b[5mðŸ§\x1b[0m" << endl;
			return (EXIT_FAILURE);
		}
	}
	return EXIT_SUCCESS;
}