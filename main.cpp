#include <iostream>
#include "euclidian.h"

int main(int argc, char const *argv[]) {


	std::pair <double, double> pto1 (1,2);
	std::pair <double, double> pto2 (3,4);
	std::pair <double, double> pto3 (5,6);
	std::pair <double, double> pto4 (7,8);
	std::pair <double, double> pto5 (9,10);

	std::vector <std::pair <double, double>> set = {pto1, pto2, pto3, pto4, pto5};
	
	//Brute-force
	double BFmin_distance = brute_force(set);
	std::cout << "Distancia mínima (brute-force): " << BFmin_distance << std::endl;

	//Divide-Conquer
	double DCmin_distance = closest(set);
	std::cout << "Distancia mínima (divide and conquer): " << DCmin_distance << std::endl;

	return 0;
}