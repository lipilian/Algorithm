#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int>& a, int left, int right) {
	if (left == right) return -1;
	if (left + 1 == right) return a[left];
	//write your code here

	std::sort(a.begin(), a.end());
	int mid = right / 2;
	int count = 1;
	while (mid < right-1 && a[mid + 1] == a[mid]) {
		mid+=1;
		count+=1;
	}
	mid = right / 2;
	while (mid > 0 && a[mid - 1] == a[mid]) {
		mid-=1;
		count+=1;
	}
	if (count > right/2) {
		return 1;
	}
	return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

