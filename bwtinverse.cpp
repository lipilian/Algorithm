#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void relabelSymbols(const string &text,std::map <char, int>& firstOcc, vector <int> &occTimes){
	int Acount = 0;
	int Ccount = 0;
	int Gcount = 0;
	int Tcount = 0;
	int DollorCount = 0;
	for (int i = 0; i < text.size(); i++){
		char symbol = text[i];
		switch (symbol)
		{
			case 'A':
				occTimes.push_back(Acount);
				Acount++;
				break;
			case 'C':
				occTimes.push_back(Ccount);
				Ccount++;
				break;
			case 'G':
				occTimes.push_back(Gcount);
				Gcount++;
				break;
			case 'T':
				occTimes.push_back(Tcount);
				Tcount++;
				break;
			case '$':
				occTimes.push_back(DollorCount);
				DollorCount++;
				break;
			default:
				break;
		}
	}
	firstOcc['$'] = 0;
	firstOcc['A'] = DollorCount;
	firstOcc['C'] = firstOcc['A'] + Acount;
	firstOcc['G'] = firstOcc['C'] + Ccount;
	firstOcc['T'] = firstOcc['G'] + Gcount;
}

string InverseBWT(const string& bwt) {
  string text = "";
  std::map <char, int> firstOcc;
  vector <int> occTimes;
  relabelSymbols(bwt, firstOcc, occTimes);
  
  int lastColIndex = 0;

  for(int i = 0; i < bwt.size(); i++){
	text += bwt[lastColIndex];
	lastColIndex = firstOcc[bwt[lastColIndex]] + occTimes[lastColIndex];
  }
  std::reverse(text.begin(),text.end());
  char a = text[0];
  text.erase(0,1);
  text += a;
  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}