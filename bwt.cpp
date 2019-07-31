#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
  string result = "";
  vector <string> v;
  string t = text;
  v.push_back(t);
  for (int i = 0; i < text.size() - 1; i ++){
	  char temp = t.back();
	  t.pop_back();
	  t.insert(t.begin(), temp);
	  v.push_back(t);
  }
  sort(v.begin(),v.end());
  for (int i = 0; i< text.size(); i++){
	  result += v[i].back();
  }

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}