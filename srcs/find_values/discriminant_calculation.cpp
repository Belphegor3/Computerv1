#include "computerv1.hpp"

extern double discriminant_calculation(){
	double discriminant = b*b - 4*a*c;
	cout << "Le discriminant vaut \x1b[1;5;35m" << discriminant << "\x1b[0m" << endl;
	if (discriminant > 0)
		cout << "Le discriminant est strictement positif" << endl;
	if (discriminant < 0)
		cout << "Le discriminant est strictement negatif" << endl;
	return discriminant;
}