#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
#include <utility>

using Point = std::pair<double,double>;

double distance_squared(const Point& p1, const Point& p2) {
	double dx = p1.first - p2.first;
	double dy = p1.second - p2.second;
	return dx*dx + dy*dy;
}

/* recibe como parámetro un vector que tiene como elementos puntos (x_i,y_i) en el plano */
double brute_force_(const std::vector<Point>& points) {
	double min_dist_sq = std::numeric_limits<double>::max();

	for(size_t i = 0; i<points.size(); ++i){
		for(size_t j = i+1; j<points.size(); ++j){
			min_dist_sq = std::min(min_dist_sq, distance_squared(points[i], points[j]));
		}
	}
	return std::sqrt(min_dist_sq);
}


double strip_Closest(std::vector<Point> strip, double d) { 
	double min_dist_sq = d*d;

	std::sort(strip.begin(), strip.end(), [](const Point& a, const Point& b) {
		return a.second < b.second;
	});
	
	for(size_t i=0; i<strip.size(); ++i){
		for(size_t j=i+1; j<strip.size() &&
				(strip[j].second - strip[i].second)*(strip[j].second - strip[i].second) < min_dist_sq; ++j){
					min_dist_sq = std::min(min_dist_sq, distance_squared(strip[i], strip[j]));
				}
	}
	return std::sqrt(min_dist_sq);

} 

// Funcion recursiva para encontrar la menor distancia, el arreglo P
//  contiene a los todos los puntos ordenados por la coordenada X
double closest_Util(const std::vector<Point>& points) { 
	if(points.size() <= 3) return brute_force_(points);

	const size_t mid = points.size() / 2;
	const Point& mid_point = points[mid];

	std::vector<Point> left(points.begin(), points.begin()+mid);
	std::vector<Point> right(points.begin() + mid, points.end());

	double d = std::min(closest_Util(left), closest_Util(right));

	std::vector<Point> strip;
	strip.reserve(points.size());
	const double d_sq = d*d;
	for(const auto& point : points){
		const double dx = point.first - mid_point.first;
		if(dx*dx < d_sq) strip.push_back(point);
	}
	return std::min(d, strip_Closest(std::move(strip), d));
} 


// Funcion principal que encuentra la menor distancia 
double closest_pair_distance(std::vector<Point> points) { 
	std::sort(points.begin(), points.end(), [](const Point& a, const Point&b){
		return a.first < b.first;
	});

	return closest_Util(points);
} 

int main(){
	std::vector<Point> points = {{1,2}, {3,4}, {5,6}, {7,8}, {9,10}};
	
	std::cout << "Distancia mínima (BF): " << brute_force_(points) << std::endl;
	std::cout << "Distancia mínima (DC): " << closest_pair_distance(points) << std::endl;

	return 0;
}
