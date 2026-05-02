#include "computerv1.hpp"

extern int check_dimension_sign(char *splitted){
	if (strlen(splitted) != 1 || splitted[0] != '*'){
		cout << "Il faut mettre des * entre les variables et les X" << endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}