#include <iostream>
#include "euclidian.h"

int main(int argc, char const *argv[]) {
	std::pair <double, double> pto1 (1,2);
	std::pair <double, double> pto2 (5,2);

	double distancia = calculateDistance(pto1, pto2);
	std::cout<<distancia<<std::endl;

	return 0;
}