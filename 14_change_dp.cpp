#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int get_change(int m) {
	//write your code here

	std::vector <int> NeededCoins(m + 1);
	NeededCoins[0] = 0;
	std::vector <int> Coins {1, 3, 4};
	
	for (int i = 1; i < (m + 1); i++) {
		NeededCoins[i] = std::numeric_limits<int>::max();
		for (auto element : Coins) {
			if (i >= element) {
				NeededCoins[i] = std::min(NeededCoins[i - element] + 1, NeededCoins[i]);
			}
		}
	}
	return NeededCoins[m];
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
	return 0;
}