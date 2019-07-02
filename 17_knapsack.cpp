#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int optimal_weight(int W, const vector<int>& w) {
	//write your code here
	int n = w.size();
	vector<vector<int>> VW(n + 1, vector<int>(W + 1));
	
	for (int i = 0; i < (n + 1); i++) {
		for (int j = 0; j < (W + 1); j++) {
			if (i == 0 || j ==0) {
				VW[i][j] = 0;
			}
			else {
				VW[i][j] = VW[i - 1][j];
				if (w[i - 1] <= j) {
					int val = VW[i - 1][j - w[i - 1]] + w[i - 1];
					if (VW[i][j] < val) {
						VW[i][j] = val;
					}
				}
			}
		}
	}
	return VW[n][W];
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	std::cout << optimal_weight(W, w) << '\n';
}