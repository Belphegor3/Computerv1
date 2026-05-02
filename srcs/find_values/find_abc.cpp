#include "computerv1.hpp"

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
	delete[] nb;
}

extern void find_abc(string equation){
	string check;
	size_t found;
	double sign = 1;
	double post_equal = 0;

	found = equation.find("^");
	while (found != string::npos){
		check = equation.substr(0, found+2);
		equation.erase(0, found+3);
		if (post_equal == 1)
			determine_abc(check, -sign);
		else
			determine_abc(check, sign);
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