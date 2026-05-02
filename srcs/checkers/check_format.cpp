#include "computerv1.hpp"

extern int check_format(string equation){
	char *splitted;
	char *to_check = new char [equation.length() + 1];
	double nb;
	int count = 0;
	int nb_equal = 0;
	int error = 0;

	strcpy(to_check, equation.c_str());
	splitted = strtok(to_check, " ");
	while (splitted != NULL){
		if (splitted[0] == '='){
			nb_equal++;
			error += check_equal(splitted, nb_equal);
			splitted = strtok(NULL, " ");
			count = 0;
			continue;
		}
		if (count % 4 == 0)
			error += check_variable(splitted, &nb);
		else if (count % 4 == 1)
			error += check_dimension_sign(splitted);
		else if (count % 4 == 2)
			error += check_unknown(splitted);
		else
			error += check_operand(splitted);
		count++;
		if (error > 0){
			delete[] to_check;
			return(EXIT_FAILURE);
		}
		splitted = strtok(NULL, " ");
	}
	if (nb_equal == 0){
		cout << "EP EP EP, police du \'=\', mets en un sinon je marche pas avec toi" << endl;
		delete[] to_check;
		return (EXIT_FAILURE);
	}
	delete[] to_check;
	return EXIT_SUCCESS;
}