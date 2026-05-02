#include "computerv1.hpp"

extern void check_nonsense(){
	if (a == 0 && b == 0 && c == 0){
		cout << "Tous les nombres reels sont des solutions et c\'est bien pour ca que personne ecrit \'X^0\' (Ca ne sert a rien ca fait toujours 1).";
		exit(EXIT_FAILURE);
	}
	if (a != 0 && b == 0 && c == 0){
		cout << "Il n\'y a pas de solution et c\'est bien pour ca que personne ecrit \'X^0\' (ca fait toujours 1 donc ca sert a rien).";
		exit(EXIT_FAILURE);
	}
}