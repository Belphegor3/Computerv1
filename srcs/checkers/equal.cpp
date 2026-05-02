#include "computerv1.hpp"

extern int check_equal(char *splitted, int nb_equal){
	if (nb_equal > 1){
		cout << "Y a un seul \'=\' dans une equation" << endl;
		return (EXIT_FAILURE);
	}
	if (strlen(splitted) != 1){
		cout << "Fait attention a ce que tu ecris, il faut juste mettre un \'=\' tout seul" << endl;
		return (EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}