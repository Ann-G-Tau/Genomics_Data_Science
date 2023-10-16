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
  
  if (argc != 2) {
    cout << "Incorrect number of input arguments\n";
    cout << "Usage: <programname> <inputfilename>";
    return 1;
  }

  ifstream input;
  input.open(argv[1]);
  if (!input.is_open()) {
    cout << "Unable to open input file\n";
    return 2;
  }
  
  string line;
  int count = 0;
  
  while (getline(input, line)) {
    int i = int(line.back() - '0');
    if (i != 0) {
      count++;
    }
  }

  input.close();  
  cout << count << endl;

  return 0;
}