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

/*double brute_force(std::vector<std::pair> set) {
	int length = set.size();
	int min = -1 // siempre asignará un nuevo minimo en la primera comparación
	for (int i = 1; i < length; i++) {
		for(int j = 1; i < length; j++) {
			int currentDistance = calculateDistance(set[i], set[j]);
			if(currentDistance)
		}
	}
}
*/