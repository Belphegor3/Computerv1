#include "computerv1.hpp"

extern void print_reduced_form(){
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

static void resolution_2_degree_complex(double discriminant){
	Complex x1, x2;

    Complex sqrt_discriminant = ft_sqrt_complex(discriminant);

    x1.realpart = (-b + sqrt_discriminant.realpart) / (2 * a);
    x1.imgpart = ( sqrt_discriminant.imgpart) / (2 * a);

    x2.realpart = (-b - sqrt_discriminant.realpart) / (2 * a);
    x2.imgpart = (-sqrt_discriminant.imgpart) / (2 * a);
	cout << "Les 2 solutions complexes sont:\n" << x1.realpart << " + " << x1.imgpart << "i" << endl;
	cout << x2.realpart << " - " << x2.imgpart << "i" << endl;
}

extern void resolution_2_degree(double discriminant){
	if (discriminant == 0){
		cout << "Le resultat de ce polynome du second degre est " << -b/(2*a) << endl;
	}
	if (discriminant > 0){
		cout << "Les solutions de ce polynome du second degre sont:\n" << ((-b - ft_sqrt(discriminant)) / (2 * a)) << "\n" << ((-b + ft_sqrt(discriminant)) / (2 * a)) << endl;
	}
	if (discriminant < 0){
		cout << "Il n\'y a pas de solutions reelles\n";
		resolution_2_degree_complex(discriminant);
	}
}


extern void	resolution_1_degree(){
	cout << "La solution est:\n" << -c / b << endl;
}

extern void resolution_0_degree(){
	if (c != 0)
		cout << "Il n\'y a pas de solution" << endl;
	else
		cout << "Tous les nombres reels sont des solutions" << endl;
}