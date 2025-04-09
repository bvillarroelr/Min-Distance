#include "euclidian.h"
#include <iostream>
#include <cmath>

double calculateDistance(std::pair <double, double> p1 , std::pair <double, double> p2) {
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

bool comparePoints(std::pair <double, double> p1 , std::pair <double, double> p2) {
	if(p1.first == p2.first && p1.second == p2.second) {
		return true;
	}
	else {
		return false;
	}
}
/* recibe como parámetro un vector que tiene como elementos puntos (x_i,y_i) en el plano */
double brute_force(std::vector <std::pair <double, double>> set) {
	int length = set.size();	

	double min = INFINITY;
	// como empezamos asignando la distancia minima como el valor set[0], recorremos el vector desde el siguiente elemento set[1]
	for (int i = 1; i < length; i++) {
		// calculamos distancia con el elemento i+1 en set
		for(int j = (i+1); j < length; j++) {
			int currentDistance = calculateDistance(set.at(i), set.at(j));
			if(currentDistance < min) {
				min = currentDistance;
			}
			else {
				continue;
			}
		}
	}
	return min;
}
