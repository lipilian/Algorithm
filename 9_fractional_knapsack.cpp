#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using std::vector;

double get_optimal_value(double capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;

	vector <std::tuple<double, double, double>> VperW;
	for (int i = 0; i < weights.size(); i++) {
		VperW.push_back(std::make_tuple(((double)values[i])/weights[i],weights[i],values[i]));
	}
	std::sort(VperW.begin(),VperW.end());
	std::reverse(VperW.begin(), VperW.end());
	
	int i = 0;
	while (capacity > 0.0 && i < weights.size()) {
		if (std::get<1>(VperW[i]) <= capacity) {
			capacity -= std::get<1>(VperW[i]);
			value += std::get<2>(VperW[i]);
		}
		else {
			value += std::get<0>(VperW[i]) * capacity;
			capacity = 0.0;
		}
		i++;
	}
	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}