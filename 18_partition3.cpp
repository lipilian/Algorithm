#include <iostream>
#include <vector>
#include <numeric>

using std::vector;

int partition3(vector<int>& A) {
	int Total = std::accumulate(A.begin(), A.end(), 0);
	vector<vector <int>> SV(Total + 1, vector <int>(Total + 1));
	if (A.size() < 3 || Total % 3 != 0) {
		return 0;
	}
	else {
		for (int i = 0; i < Total + 1; i++) {
			for (int j = 0; j < Total + 1; j++) {
				SV[i][j] = 0;
			}
		}
		SV[0][0] = 1;
		for (int k = 0; k < A.size(); k++) {
			for (int i = Total; i >= 0; i--) {
				for (int j = Total; j >= 0; j--) {
					if (SV[i][j] == 1) {
						SV[i + A[k]][j] = 1;
						SV[i][j + A[k]] = 1;
					}
				}
			}
		}
	}
	return SV[Total / 3][Total / 3];
}

int main() {
	int n;
	std::cin >> n;
	vector<int> A(n);
	for (size_t i = 0; i < A.size(); ++i) {
		std::cin >> A[i];
	}
	std::cout << partition3(A) << '\n';
	return 0;
}
