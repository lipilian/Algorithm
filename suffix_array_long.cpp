#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using std::map;

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> SortCharacters(const string& text){
  vector<int> order(text.length());
  map<char, int> count;
  count['$'] = 0;
  count['A'] = 0;
  count['C'] = 0;
  count['G'] = 0;
  count['T'] = 0;
  for(int i = 0; i < text.length(); i++){
    count[text[i]]++;
  }
  auto itFirst = ++count.begin();
  for(map<char,int>::iterator it = itFirst; it != count.end(); it++){
    (*it).second = it->second + std::prev(it)->second;
  }
  for(int i = text.length() - 1; i >=0 ; i--){
    char c = text[i];
    count[c] = count[c] - 1;
    order[count[c]] = i;
  }
  return order;
}

vector<int> ComputeCharClasses(const string& text, const vector<int>& order){
  vector<int> CharClass (text.length());
  CharClass[order[0]] = 0;
  for(int i = 1; i < text.length(); i++){
    if(text[order[i]] != text[order[i - 1]]){
      CharClass[order[i]] = CharClass[order[i - 1]] + 1;
    } else {
      CharClass[order[i]] = CharClass[order[i - 1]];
    }
  }
  return CharClass;
}

vector<int> SortDoubled(const string& text, int L, const vector<int>& order, const vector<int>& CharClass){
  vector<int> count (text.length(), 0);
  vector<int> newOrder (text.length());
  for(int i = 0; i < text.length(); i++){
    count[CharClass[i]] = count[CharClass[i]] + 1;
  }
  for(int i = 1; i < text.length(); i++){
    count[i] = count[i] + count[i - 1];
  }
  for(int i = text.length() - 1; i >= 0; i--){
    int start = (order[i] - L + text.length()) % text.length();
    int cl = CharClass[start];
    count[cl]--;
    newOrder[count[cl]] = start;
  }
  return newOrder;
}

vector<int> UpdateClasses(const vector<int>& newOrder, const vector<int>& CharClass, int L){
  int n = newOrder.size();
  vector<int> newClass (n);
  newClass[newOrder[0]] = 0;
  for(int i = 1; i < n; i++){
    int cur = newOrder[i];
    int prev = newOrder[i - 1];
    int mid = (cur + L) % n;
    int midPrev = (prev + L) % n;
    if(CharClass[cur] != CharClass[prev] || CharClass[mid] != CharClass[midPrev]){
      newClass[cur] = newClass[prev] + 1;
    } else {
      newClass[cur] = newClass[prev];
    }
  }
  return newClass;
}

vector<int> BuildSuffixArray(const string& text) {
  vector<int> order = SortCharacters(text);
  vector<int> CharClass = ComputeCharClasses(text, order);
  int L = 1;
  while(L < text.length()){
    order = SortDoubled(text, L, order, CharClass);
    CharClass = UpdateClasses(order, CharClass, L);
    L = 2 * L;
  }
  return order;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}

