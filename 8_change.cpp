#include <iostream>

int get_change(int m) {
	int tenth = m / 10;
	int fifth = (m % 10) / 5;
	int oneth = m % 5;
	return (tenth + fifth + oneth);
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}


