#include "computerv1.hpp"

extern double discriminant_calculation(){
	double discriminant = b*b - 4*a*c;
	if (discriminant == 0)
		cout << "Le discriminant vaut 0" << endl;
	else if (discriminant > 0)
		cout << "Le discriminant est strictement positif" << endl;
	else
		cout << "Le discriminant est strictement negatif" << endl;
	return discriminant;
}