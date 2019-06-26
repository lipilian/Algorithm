#include <iostream>
#include <vector>
#include <iostream>

long long get_fibonacci_huge_fast(long long n) {
	if (n <= 1)
		return n;
	int m = 10;
	std::vector <long long> fibonacci_array;
	fibonacci_array.push_back(0);
	fibonacci_array.push_back(1);

	for (long long i = 2; i < n; i += 1) {
		long long temp = (fibonacci_array[i - 1] + fibonacci_array[i - 2]) % m;
		if (temp == 1 && fibonacci_array[i - 1] == 0) {
			break;
		}
		fibonacci_array.push_back(temp);
		//return (temp + fibonacci_array[i - 1]) % m;
	}
	if (fibonacci_array.size() == n) {
		int a = (fibonacci_array[n - 1] + fibonacci_array[n - 2]) % m;
		int b = (fibonacci_array[n - 1] + a) % m;
		
		return ((a + b) % m - 1);
	}
	long long period = fibonacci_array.size() - 1;
	long long index = (n + 2) % period;
	return fibonacci_array[index] - 1;
}

int main() {
	long long n;
	std::cin >> n;
	int result = get_fibonacci_huge_fast(n);
	if (result == -1) {
		result = 9;
	}
	std::cout << result << '\n';
}
