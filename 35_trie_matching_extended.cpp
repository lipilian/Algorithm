#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters = 4;
int const NA = -1;

struct Node
{
	int next[Letters];
	bool patternEnd;

	Node()
	{
		fill(next, next + Letters, NA);
		patternEnd = false;
	}

	bool isLeaf() const
	{
		return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};

int letterToIndex(char letter)
{
	switch (letter)
	{
	case 'A': return 0; break;
	case 'C': return 1; break;
	case 'G': return 2; break;
	case 'T': return 3; break;
	default: assert(false); return -1;
	}
}

void build_trie(const vector <string> &patterns, vector <Node>& t) {
	t.resize(1);
	for (auto& pattern : patterns) {
		int currentNode = 0;
		for (int i = 0; i < pattern.size(); i++) {
			int index = letterToIndex(pattern[i]);
			if (t[currentNode].next[index] != -1) {
				currentNode = t[currentNode].next[index];
			}
			else {
				t[currentNode].next[index] = t.size();
				currentNode = t.size();
				t.resize(currentNode + 1);
			}
		}
		t[currentNode].patternEnd = true;
	}
}


vector <int> solve(const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;
	vector <Node> t;
	build_trie(patterns, t);
	for (int i = 0; i < text.size(); i++) {
		int index = letterToIndex(text[i]);
		int currentNode = 0;
		if (t[currentNode].next[index] != -1) {
			bool found = true;
			for (int j = i; !t[currentNode].patternEnd; j++) {
				if (j >= text.size()) {
					found = false;
					break;
				}
				index = letterToIndex(text[j]);
				currentNode = t[currentNode].next[index];
				if (currentNode == -1) {
					found = false;
					break;
				}
			}
			if (found) {
				result.push_back(i);
			}
		}
	}
	return result;
}

int main(void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns(n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve(t, n, patterns);

	for (int i = 0; i < (int)ans.size(); i++)
	{
		cout << ans[i];
		if (i + 1 < (int)ans.size())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
