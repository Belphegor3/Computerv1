#include "computerv1.hpp"

extern void determine_degree(string equation){
	char *splitted;
	int power = 0;
	int count = 0;
	
	equation = equation.substr(0, equation.find('='));
	char *to_check = new char [equation.length() + 1];
	strcpy(to_check, equation.c_str());
	splitted = strtok(to_check, "^");
	while (splitted != NULL){
		if (count != 0)
			if (power < splitted[0] - 48)
				power = splitted[0] - 48;
		splitted = strtok(NULL, "^");
		count++;
	}
	// if (power == 0){
	// 	cout << "C\'est pas une equation si y a pas d\'inconnu" << endl;
	// 	exit(EXIT_FAILURE);
	// }
	cout << "Le degre du polynome est: " << power << endl;
	delete[] to_check;
}