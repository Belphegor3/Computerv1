#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>

using namespace std;

extern double a;
extern double b;
extern double c;

struct Complex {
    double realpart;
    double imgpart;
};

int check_dimension_sign(char *splitted);
int check_equal(char *splitted, int nb_equal);
int check_operand(char *splitted);
int check_unknown(char *splitted);
int check_variable(char *splitted, double *nb);

int check_format(string equation);
int check_nonsense();
int check_intruder(string equation);


void determine_degree(string equation);
void find_abc(string equation);
double discriminant_calculation();


double ft_sqrt(double nb);
Complex ft_sqrt_complex(double nb);


void resolution_0_degree();
void resolution_1_degree();
void resolution_2_degree(double discriminant);
void print_reduced_form();