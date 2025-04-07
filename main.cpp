#include <iostream>
#include "euclidian.h"

int main(int argc, char const *argv[]) {

	std::pair <double, double> pto1 (5,2);
	std::pair <double, double> pto2 (5,2);

	bool comp = comparePoints(pto1, pto2);
	std::cout<<comp<<std::endl;

	return 0;
}