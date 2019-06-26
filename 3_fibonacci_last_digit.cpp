#include <iostream>
#include <vector>
int get_fibonacci_last_digit_fast(int n) {
	std::vector <int> fibonacci_array;
	fibonacci_array.push_back(1);
	fibonacci_array.push_back(1);
	if (n <= 1) {
		return n;
	}	
	for (int i = 2; i < n; i++) {
		fibonacci_array.push_back((fibonacci_array[i - 1] + fibonacci_array[i - 2])%10);
	}
	return fibonacci_array[n - 1];
	
}

int main() {
	int n;
	std::cin >> n;
	int c = get_fibonacci_last_digit_fast(n);
	std::cout << c << '\n';
}
