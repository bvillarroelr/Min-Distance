#include "euclidian.h"
#include <iostream>
#include <cmath>

double calculateDistance(std::pair <double, double> p1 , std::pair <double, double> p2) {
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

/*double brute_force(int* set, int length) {

}
*/