#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>

using namespace std;

double a = 0;
double b = 0;
double c = 0;


static void check_intruder(string equation){
	size_t intruder = equation.find_first_not_of("0123456789X*-+^=. ");

	if (intruder != string::npos){
		cout << "\x1b[5;31mLe caractere " << equation[intruder] << " n\'est pas reconnu\x1b[0m" << endl;
		cout << "Ce programme sert a resoudre des polynomes du premier et du second degres en utilisant \'X\' comme inconnu (en majuscule).\n\x1b[32mCependant, veillez bien respecter le format \x1b[31ma * X^p\x1b[32m, p valant 0,1 ou 2.\x1b[0m" << endl;
		exit(EXIT_FAILURE);
	}
}

static void check_equal(int count, char *splitted, int *nb_equal){
	*nb_equal++;
	if (*nb_equal > 1){
		cout << "Y a un seul \'=\' dans une equation" << endl;
		exit(EXIT_FAILURE);
	}
	if (strlen(splitted) != 1){
		cout << "Fait attention a ce que tu ecris, il faut juste mettre un \'=\' tout seul" << endl;
		exit(EXIT_FAILURE);
	}
	// if (count < 6){
	// 	cout << "Fait gaffe ou tu mets tes \'=\'" << endl;
	// 	exit(EXIT_FAILURE);
	// }
}

static void check_variable(int count, char *splitted, double *nb){
	char *endptr;

	if (splitted[0] == '.'){
		cout << "Un nombre ne commence pas par un \'.\', a la limite veillez ecrire le 0 devant pour que le format soit respecte parce que c\'est moi qui decide" << endl;
		exit(EXIT_FAILURE);
	}
	if (splitted[0] == '+' || splitted[0] == '*' || splitted[0] == '^'){
		cout << "\x1b[31mVeillez taper une equation valide ðŸ§\x1b[0m\n";
		exit(EXIT_FAILURE);
	}
	else if (splitted[0] == 'X'){
		cout << "\x1b[32mVeillez bien respecter le format \x1b[31ma * X^p\x1b[32m, p valant 0,1 ou 2.\x1b[0m" << endl;
		exit(EXIT_FAILURE);
	}
	else{
		*nb = strtod(splitted, &endptr);
		if (!endptr){
			cout << "Caractere suspect detecte dans " << splitted << " \x1b[5mðŸ§\x1b[0m" << endl;
			exit(EXIT_FAILURE);
		}
	}
}

static void check_dimension_sign(int count, char *splitted){
	if (strlen(splitted) != 1 || splitted[0] != '*'){
		cout << "Il faut mettre des * entre les variables et les X" << endl;
		exit(EXIT_FAILURE);
	}
}

static void check_x(int count, char *splitted){
	if (strlen(splitted) != 3){
		cout << "On a un probleme de taille la.\nLe format est valide si la forme ressemble a \x1b[31ma * X^p\x1b[32m, p valant 0,1 ou 2.\x1b[0m" << endl;
		exit(EXIT_FAILURE);
	}
	if (splitted[0] != 'X'){
		cout << "T\'es qui toi? Hum un " << splitted[0] <<  "\nC'est pas un x majuscule donc je veux pas de toi!" << endl;
		exit(EXIT_FAILURE);
	}
	if (splitted[1] != '^'){
		cout << "Qu\'est ce que c\'est ca? " << splitted[1] << "\nJ\'veux rien savoir, c\'est pas un exposant donc ca degage!" << endl;
		exit(EXIT_FAILURE);
	}
	if (splitted[2] != '0' && splitted[2] != '1' && splitted[2] != '2'){
		if (splitted[2] >= '3' && splitted[2] <= '9'){
			cout << "Le degres du polynome est plus grand que 2, je sais pas faire ca!" << endl;
			exit(EXIT_FAILURE);
		}
		cout << "Soit normal, met un chiffre pour ta puissance et fait en sorte qu\'il soit entre 0 et 2 pour que le programme fonctionne stp!" << endl;
		exit(EXIT_FAILURE);
	}
}

static void check_operand(int count, char *splitted){
	if ((strlen(splitted) != 1) || (splitted[0] != '+' && splitted[0] != '-')){
		cout << "Tiens tiens tiens mais que voila-je ðŸ¤¨? Pas un simple operateur en tout cas!\nPour rappel, le format valide est de la forme \x1b[31ma * X^p\x1b[32m, p valant 0,1 ou 2.\x1b[0m\nNombres, operateurs et inconnus doivent etre separer d\'un espace." << endl;
		exit(EXIT_FAILURE);
	};
}

static void check_format(string equation){
	char *splitted;
	char *to_check = new char [equation.length() + 1];
	double nb;
	int count = 0;
	int nb_equal = 0;

	strcpy(to_check, equation.c_str());
	splitted = strtok(to_check, " ");
	while (splitted != NULL){
		if (splitted[0] == '='){
			check_equal(count, splitted, &nb_equal);
			splitted = strtok(NULL, " ");
			count = 0;
			continue;
		}
		if (count % 4 == 0)
			check_variable(count, splitted, &nb);
		else if (count % 4 == 1)
			check_dimension_sign(count, splitted);
		else if (count % 4 == 2)
			check_x(count, splitted);
		else
			check_operand(count, splitted);
		count++;
		splitted = strtok(NULL, " ");
	}
	if (nb_equal == 0){
		cout << "EP EP EP, police du \'=\', mets en un sinon je marche pas avec toi" << endl;
		exit(EXIT_FAILURE);
	}
}

static void determine_degree(string equation){
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
	if (power == 0){
		cout << "C\'est pas une equation si y a pas d\'inconnu" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Le degre du polynome est: " << power << endl;
}

static void determine_abc(string check, double sign){
	string to_check = check.substr(0, check.length() - 4);
	char *nb = new char [to_check.length() + 1];

	strcpy(nb, to_check.c_str());
	if (check[check.length() - 1] == '0')
		c += (strtod(nb, NULL) * sign);
	if (check[check.length() - 1] == '1')
		b += (strtod(nb, NULL) * sign);
	if (check[check.length() - 1] == '2')
		a += (strtod(nb, NULL) * sign);
}

static void find_abc(string equation){
	string check;
	size_t found;
	double sign = 1;
	double post_equal = 0;

	found = equation.find("^");
	while (found != string::npos){
		check = equation.substr(0, found+2);
		cout << "\x1b[31m" << check << "\x1b[0m\n";
		equation.erase(0, found+3);
		cout << "\x1b[33m" << equation << "\x1b[0m\n";
		if (equation[0] == '-')
			sign = -1;
		// cout << "\x1b[32mvaleur de post_egal: " << post_equal << "\nvaleur de sign: " << sign << "\nresultat du produit sign * -1: " << sign * -1 << "\x1b[0m" << endl;
		if (post_equal == 1){
			// cout << "valeur de a: " << a << "\nvaleur de b: " << b << "\nvaleur de c: " << c << endl;
			determine_abc(check, -sign);
		}
		else
			determine_abc(check, sign);
		sign = 1;
		if (equation[0] == '=')
			post_equal = 1;
		equation.erase(0, 2);
		// if (post_equal == 1)
		// 	post_equal++;
		// cout << "valeur de a: " << a << "\nvaleur de b: " << b << "\nvaleur de c: " << c << endl;
		found = equation.find("^");
	}
}

static double determinant_calculation(){
	double determinant = b*b - 4*a*c;
	if (determinant == 0)
		cout << "Le determinant vaut 0" << endl;
	else if (determinant > 0)
		cout << "Le determinant est strictement positif" << endl;
	else
		cout << "Le determinant est strictement negatif" << endl;
	return determinant;
}

// static void resolution(double determinant){
//   if (determinant == 0){
// 	cout << "Le resultat de ce polynome du secone degre est " << -b/(2*a) << endl;
//   }
// }

static void check_nonsense(){
	if (a == 0 && b == 0 && c == 0){
		cout << "Tous les nombres reels sont des solutions et c\'est bien pour ca que personne ecrit \'X^0\' (Ca ne sert a rien ca fait toujours 1).";
		exit(EXIT_FAILURE);
	}
	if (a != 0 && b == 0 && c == 0){
		cout << "Il n\'y a pas de solution et c\'est bien pour ca que personne ecrit \'X^0\' (ca fait toujours 1 donc ca sert a rien).";
		exit(EXIT_FAILURE);
	}
}

static void print_reduced_form(){
	cout << "Forme reduite: ";
	if (a != 0)
		cout << a << " * X^2";
	if (b > 0){
		if (a != 0)
			cout << " + " << b << " * X^1";
		else
			cout << b << " * X^1";
	}
	if (b < 0){
		if (a != 0)
			cout << " - " << b * -1 << " * X^1";
		else
			cout << b << " * X^1";
	}
	if (c > 0){
		if (b != 0)
			cout << " + " << c << " * X^0";
		else{
			if (a == 0)
				cout << c << " * X^0";
			if (a != 0)
				cout << " + " << c << " * X^0";
		}
	}
	if (c < 0){
		if (b != 0)
			cout << " - " << c * -1 << " * X^0";
		else{
			if (a == 0)
				cout << c << " * X^0";
			else
				cout << " - " << c * -1 << " * X^0";
		}
	}
	cout << " = 0" << endl; 
}

int main(int ac, char **av){
	//! gerer stdin si ac == 1 a la fin

	string equation = av[1];
	check_intruder(equation);
	check_format(equation);
	determine_degree(equation);
	find_abc(equation);
	cout << "valeur de a: " << a << "\nvaleur de b: " << b << "\nvaleur de c: " << c << endl;
	check_nonsense();
	print_reduced_form();
	if (a != 0)
		double determinant = determinant_calculation();
	// resolution(determinant);
}


// ! ATTENTION avec les egal ca marhce pas la sa mere