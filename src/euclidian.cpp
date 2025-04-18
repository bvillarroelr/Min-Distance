#include "euclidian.h"
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

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
	// usamos la constante de cmath infinity para que cualquier distancia calculada posteriormente sea la menor
	double min = INFINITY;

	for (int i = 0; i < length; i++) {
		// calculamos distancia con el elemento i+1 en set
		for(int j = (i+1); j < length; j++) {
			double currentDistance = calculateDistance(set.at(i), set.at(j));
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


/* Funcion para encontrar la 
distancia entre los puntos mas cercanos dentro de 
un strip. Todos los puntos en 
strip[] estan ordenados deacuerdo a la 
coordenada y. Todos tienen un limite 
superior para la distancia minima dado por d. 

Este metodo parece ser O(n²), pero en realidad es O(n) 
ya que el bucle interno se ejecuta como maximo 6 veces.
*/
double stripClosest(std::vector<std::pair<double, double>> strip, double d) 
{ 
	double min = d; // Inicializa la distancia minima como d
	int size = strip.size(); // Cantidad de puntos del strip

	std::sort(strip.begin(), strip.end(), [](const auto &a, const auto &b) {
        return a.second < b.second; // Compara por la coordenada y
    });

	// Toma los puntos uno por uno y pruba con los siguientes hasta que 
	// la diferencia entre las coordenadas sea menor a d
	for (int i = 0; i < size; ++i) {
		for (int j = i+1; j < size && (strip[j].second - strip[i].second) < min; ++j) {
			double dist=calculateDistance(strip[i],strip[j]);
			if (dist < min) {
				min = dist; 
			}
		}
	}
	return min; 
} 

// Funcion recursiva para encontrar la menor distancia, el arreglo P
//  contiene a los todos los puntos ordenados por la coordenada X
double closestUtil(std::vector<std::pair<double, double>> P, int n) 
{ 
	// Si hay 2 o 3 puntos usar brute_force
	if (n <= 3) 
		return brute_force(P); 

	// Encontrar el punto medio
	int mid = n/2; 
	std::pair<double, double> midPoint = P[mid]; 

	// Divide el conjunto P en dos, left como la primera mitad de P y right como la segunda mitad
	std::vector<std::pair<double, double>> left(P.begin(), P.begin() + mid);
    std::vector<std::pair<double, double>> right(P.begin() + mid, P.end());

	// Considera la linea vertical que pasa por el punto medio
	// Calcula la distancia mas pequeña en el lado izquierdo y derecho
	double dl = closestUtil(left, left.size()); 
	double dr = closestUtil(right, right.size()); 

	double d = std::min(dl, dr); 

	// Considera los puntos cercanos a la linea divisoria para el calculo de la menor distancia
    std::vector<std::pair<double, double>> strip;
	for (int i = 0; i < n; i++) 
		if (abs(P[i].first - midPoint.first) < d) 
			strip.push_back(P[i]); 

	// Encuentra los puntos mas cercanos en el strip
	// Retorna el minimo entre d y el la menor distancia en el strip
	return std::min(d, stripClosest(strip,d) ); 
} 


// Funcion principal que encuentra la menor distancia 
double closest(std::vector<std::pair<double, double>> P) 
{ 
	// Ordena los puntos por la coordenada x
	std::sort(P.begin(), P.end(), [](const auto &a, const auto &b) {
        return a.first < b.first; // Comparar por la coordenada x
    }); 

	// Usa recursivamente closestutil para encontrar la menor distancia 
	return closestUtil(P, P.size()); 
} 
