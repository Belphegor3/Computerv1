#include "computerv1.hpp"

extern int check_unknown(char *splitted){
	if (strlen(splitted) != 3){
		cout << "On a un probleme de taille la.\nLe format est valide si la forme ressemble a \x1b[31ma * X^p\x1b[32m, p valant 0,1 ou 2.\x1b[0m" << endl;
		return (EXIT_FAILURE);
	}
	if (splitted[0] != 'X'){
		cout << "T\'es qui toi? Hum un " << splitted[0] <<  "\nC'est pas un x majuscule donc je veux pas de toi!" << endl;
		return (EXIT_FAILURE);
	}
	if (splitted[1] != '^'){
		cout << "Qu\'est ce que c\'est ca? " << splitted[1] << "\nJ\'veux rien savoir, c\'est pas un exposant donc ca degage!" << endl;
		return (EXIT_FAILURE);
	}
	if (splitted[2] != '0' && splitted[2] != '1' && splitted[2] != '2'){
		if (splitted[2] >= '3' && splitted[2] <= '9'){
			cout << "Le degres du polynome est plus grand que 2, je sais pas faire ca!" << endl;
			return (EXIT_FAILURE);
		}
		cout << "Soit normal, met un chiffre pour ta puissance et fait en sorte qu\'il soit entre 0 et 2 pour que le programme fonctionne stp!" << endl;
		return (EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}