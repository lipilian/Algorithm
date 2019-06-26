#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
	int current_gcd = 1;

	int c = std::max(a, b);
	int d = std::min(a, b);

	while (d!= 0) {
		int temp = c % d;
		c = d;
		d = temp;
	}
	return c;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	int temp = gcd(a, b);
	std::cout << (((long long)a)*b)/temp << std::endl;
	return 0;
}
