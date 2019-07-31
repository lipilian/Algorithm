#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using std::map;
using std::vector;
using std::string;
using std::pair;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string>& patterns) {
	trie t;
	t.resize(1);
	for (const string& pattern : patterns) {
		int currentNode = 0;
		for (int i = 0; i < pattern.size(); i++) {
			char c = pattern[i];
			if (t[currentNode].find(c) != t[currentNode].end()) {
				currentNode = t[currentNode][c];
			}
			else {
				t[currentNode][c] = t.size();
				currentNode = t.size();
				t.resize(t.size() + 1);
			}
		}
	}


	return t;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<string> patterns;
	for (size_t i = 0; i < n; i++) {
		string s;
		std::cin >> s;
		patterns.push_back(s);
	}

	trie t = build_trie(patterns);
	for (size_t i = 0; i < t.size(); ++i) {
		for (const auto& j : t[i]) {
			std::cout << i << "->" << j.second << ":" << j.first << "\n";
		}
	}

	return 0;
}
