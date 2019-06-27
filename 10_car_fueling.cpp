#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
	// write your code here
	int currentDist = 0;
	stops.push_back(dist);
	if (dist <= tank) {
		return 0;
	}
	if (stops[0] > tank) {
		return -1;
	}
	for (int i = 0; i < (stops.size()-1); i++) {
		if ((stops[i + 1] - stops[i]) > tank) {
			return -1;
		}
	}
	int i = 0;
	int refuls = 0;
	while (currentDist < (dist - tank)) {
		if ((stops[i] - currentDist) <= tank && (stops[i + 1] - currentDist) > tank) {
			refuls += 1;
			currentDist = stops[i];
		}
		i++;
	}
	return refuls;
	
}


int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i);

	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}
