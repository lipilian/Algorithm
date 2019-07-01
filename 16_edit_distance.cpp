#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;

int edit_distance(const string& str1, const string& str2) {
	std::vector<std::vector<int>> EditDist(str1.size() + 1, std::vector<int>(str2.size() + 1));
	for (int i = 0; i <= str1.size(); i++) {
		for (int j = 0; j <= str2.size(); j++) {
			if (i == 0) {
				EditDist[i][j] = j;
			}
			else if (j == 0) {
				EditDist[i][j] = i;
			}
			else if (str1[i - 1] == str2[j - 1]) {
				EditDist[i][j] = std::min(EditDist[i][j-1]+1, std::min(EditDist[i-1][j]+1, EditDist[i-1][j-1]));
			}
			else {
				EditDist[i][j] = std::min(EditDist[i][j - 1] + 1, std::min(EditDist[i - 1][j] + 1, EditDist[i - 1][j - 1] + 1));
			}
		}
	}
	return EditDist[str1.size()][str2.size()];
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}