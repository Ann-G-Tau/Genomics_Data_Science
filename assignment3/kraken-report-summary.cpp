// Note: For all programs to run normally, please add “./” before executable name. 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool sortByVal(const pair<string, int> &a, const pair<string, int> &b) { 
    return (a.second < b.second); 
} 

int main(int argc, char** argv) {
  
  if (argc != 3) {
    cout << "Incorrect number of input arguments\n";
    cout << "Usage: <programname> <inputfilename> <outputfilename>";
    return 1;
  }

  ifstream input;
  ofstream output;
  input.open(argv[1]);
  output.open(argv[2]);
  if (!input.is_open()) {
    cout << "Unable to open input file\n";
    return 2;
  }
  
  string line;
  float filter_f;
  int filter_i;
  int count;
  char ID;
  char filter;
  string name;
  map<string, int> genus;
    map<string, int> species;

  while (getline(input, line)) {
    stringstream ss(line);
    ss >> filter_f >> filter_i >> count >> ID >> filter_i;
    ss >> filter;
    while (filter == ' ') {
      ss >> filter;
    }
    getline(ss, name);
    name.insert(0, 1, filter);
    if (count > 1 && ID == 'G') {
      genus[name] = count;
    }
    if (count > 1 && ID == 'S') {
      species[name] = count;
    }
  }

  vector<pair<string, int>> vec1;
  map<string, int> :: iterator it1;
  for (it1=genus.begin(); it1!=genus.end(); it1++) {
    vec1.push_back(make_pair(it1->first, it1->second));
  }
  sort(vec1.begin(), vec1.end(), sortByVal); 
	for (int i = vec1.size() - 1; i >= 0; i--) {
		output << vec1[i].first << "\t" << vec1[i].second << endl;
	}

  output << endl;
  
  vector<pair<string, int>> vec2;
  map<string, int> :: iterator it2;
  for (it2=species.begin(); it2!=species.end(); it2++) {
    vec2.push_back(make_pair(it2->first, it2->second));
  }
  sort(vec2.begin(), vec2.end(), sortByVal); 
	for (int i = vec2.size() - 1; i >= 0; i--) {
		output << vec2[i].first << "\t" << vec2[i].second << endl;
	}

  input.close();  
  output.close();

  return 0;
}