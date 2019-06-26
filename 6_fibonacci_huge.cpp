#include <iostream>
#include <vector>
#include <iostream>

long long get_fibonacci_huge_fast(long long n, long long m) {
	if (n <= 1)
		return n;
	std::vector <long long> fibonacci_array;
	fibonacci_array.push_back(0);
	fibonacci_array.push_back(1);
	
	for (long long i = 2; i < n; i += 1) {
		long long temp = (fibonacci_array[i - 1] + fibonacci_array[i - 2])%m;
		if (temp == 1 && fibonacci_array[i - 1] == 0) {
			break;
		}
		fibonacci_array.push_back(temp);
		//return (temp + fibonacci_array[i - 1]) % m;
	}
	if (fibonacci_array.size() == n) {
		return (fibonacci_array[n-1] + fibonacci_array[n-2]) % m;
	}
	long long period = fibonacci_array.size() - 1;
	long long index = n % period;
	return fibonacci_array[index];
}

int main() {
	long long n, m;
	std::cin >> n >> m;
	std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
