#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

void computePrefixFunction(const string& text, vector <int> &s){
	s.resize(text.size());
	s[0] = 0;
	int border = 0;
	for (int i = 1; i < text.size(); i++){
		while(border > 0 && text[i] != text[border]){
			border = s[border - 1];
		}
		if (text[i] == text[border]){
			border++;
		} else {
			border = 0;
		}
		s[i] = border;
	}
}

vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  string input = pattern + '$' + text;
  vector<int> s;
  computePrefixFunction(input,s);
  for (int i = pattern.size() + 1; i < input.size(); i++){
	  if(s[i] == pattern.size()){
		  result.push_back(i - 2*pattern.size());
	  }
  }
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
