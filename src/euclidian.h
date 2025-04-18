#ifndef EUCLIDIAN
#define EUCLIDIAN
#include <utility>
#include <vector>

double calculateDistance(std::pair <double, double> p1 , std::pair <double, double> p2);
bool comparePoints(std::pair <double, double> p1 , std::pair <double, double> p2);
double brute_force(std::vector<std::pair <double, double>> set);
double stripClosest(std::vector<std::pair<double, double>> strip, double d);
double closestUtil(std::vector<std::pair<double, double>> P, int n);
double closest(std::vector<std::pair<double, double>> P);

#endif
