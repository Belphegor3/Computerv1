#include "computerv1.hpp"

extern double ft_sqrt(double nb){
    double result = nb;
    double epsilon = 1e-9;
    while ((result * result - nb) > epsilon || (nb - result * result) > epsilon) {
        result = (result + nb / result) / 2;
    }
    return result;
}

extern Complex ft_sqrt_complex(double nb) {
    Complex res;

    if (nb >= 0) {
        res.realpart = ft_sqrt(nb);
        res.imgpart = 0;
    } else {
        res.realpart = 0;
        res.imgpart = ft_sqrt(-nb);
    }
    return res;
}