#include "computerv1.hpp"

double a;
double b;
double c;

int main(int ac, char **av){
	if (ac > 2){
		cout << "Du calme, un a la fois je te prie ☺️" << endl;
		return (EXIT_FAILURE);
	}
	string equation;
	if (ac == 1){
		getline(cin, equation);
		if (cin.eof())
			exit(EXIT_FAILURE);
	}
	else
		equation = av[1];
	check_intruder(equation);
	check_format(equation);
	determine_degree(equation);
	find_abc(equation);
	check_nonsense();
	print_reduced_form();
	if (a != 0){
		double discriminant = discriminant_calculation();
		resolution_2_degree(discriminant);
	}
	if (a == 0 && b != 0)
		resolution_1_degree();
	if (a == 0 && b == 0)
		resolution_0_degree();
	return (EXIT_SUCCESS);
}