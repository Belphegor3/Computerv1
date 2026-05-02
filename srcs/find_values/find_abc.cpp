#include "computerv1.hpp"

extern void find_abc(string equation){
	string check;
	size_t found;
	double sign = 1;
	double post_equal = 0;

	found = equation.find("^");
	while (found != string::npos){
		check = equation.substr(0, found+2);
		// cout << "\x1b[31m" << check << "\x1b[0m\n";
		equation.erase(0, found+3);
		// cout << "\x1b[33m" << equation << "\x1b[0m\n";
		if (post_equal == 1)
			determine_abc(check, -sign);
		else
			determine_abc(check, sign);
		// cout << "\x1b[35mvaleur de a: " << a << "\nvaleur de b: " << b << "\nvaleur de c: " << c << "\n\x1b[0m";
		if (equation[0] == '=')
			post_equal = 1;
		if (equation[0] == '-')
			sign = -1;
		else
			sign = 1;
		equation.erase(0, 2);
		found = equation.find("^");
	}
}