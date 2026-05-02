#include "computerv1.hpp"

extern void determine_abc(string check, double sign){
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