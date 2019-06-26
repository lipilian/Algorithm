#include <iostream>
#include <cassert>
#include <vector>

int fibonacci_naive(int n) {
	if (n <= 1)
		return n;

	return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
	std::vector <long long> fibonacci_array;
	fibonacci_array.push_back(1);
	fibonacci_array.push_back(1);
	if (n <= 1) {
		return n;
	}
	for (int i = 2; i < n; i++) {
		fibonacci_array.push_back(fibonacci_array[i - 1] + fibonacci_array[i - 2]);
	}
	return fibonacci_array[n-1];
}

int main() {
	int n = 0;
	std::cin >> n;
	std::cout << fibonacci_fast(n) << '\n';
	return 0;
}