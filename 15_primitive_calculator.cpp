#include <iostream>
#include <vector>
#include <algorithm>

std::vector <int> optimal_sequence(int n) {
	std::vector <int> operation (n);
	operation[0] = 0;

	for (int i = 1; i < n; i++) {
		if ((i + 1) % 2 == 0) {
			operation[i] = std::min(operation[i - 1] + 1, operation[(i + 1) / 2 - 1] + 1);
		}
		if ((i + 1) % 3 == 0) {
			operation[i] = std::min(operation[i - 1] + 1, operation[(i + 1) / 3 - 1] + 1);
		}
		if ((i + 1) % 3 !=0 && (i + 1) % 2 != 0){
			operation[i] = operation[i - 1] + 1;
		}
	}

	std::vector <int> sequence;
	while (n >= 1) {
		sequence.push_back(n);
		if (n % 3 == 0 && operation[n/3 - 1] == (operation[n - 1] - 1)) {
			n /= 3;
		}
		else if (n % 2 == 0 && operation[n/2 - 1] == (operation[n - 1] - 1)) {
			n /= 2;
		}
		else {
			n = n - 1;
		}
	}
	reverse(sequence.begin(), sequence.end());
	return sequence;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
}
