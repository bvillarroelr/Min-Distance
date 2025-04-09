#include <iostream>
#include "euclidian.h"

int main(int argc, char const *argv[]) {


	std::pair <double, double> pto1 (5,2);
	std::pair <double, double> pto2 (1,2);
	std::pair <double, double> pto3 (-3, 0);
	std::pair <double, double> pto4 (15, 3);
	std::pair <double, double> pto5 (1,2);

	std::vector <std::pair <double, double>> set = {pto1, pto2, pto3, pto4, pto5};
	
	double min_distance = brute_force(set);
	std::cout<<min_distance<<std::endl;

	return 0;
}