#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {

  if (argc != 3) {
    cout << "Incorrect number of input arguments\n";
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
  
  int count[1000000] = { };
  int numFasta = 0;
  int totalContig = 0;
  int currentContig = 0;
  int n50cnt = 0;
  string line1;
  string line2;
  while (getline(input, line1) && getline(input, line2)) {
    count[numFasta] = line2.length();
    totalContig += line2.length();
    numFasta++;
  }
  sort(count, count + (sizeof(count) / sizeof(count[0])), greater<int>());
  input.close();
  while (currentContig < (totalContig / 2)) {
    currentContig += count[n50cnt];
    n50cnt++;
  }
  output << "N50 size:" << count[--n50cnt] << endl;
  output.close();

  return 0;
}
