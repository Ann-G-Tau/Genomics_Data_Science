#include <iostream>
#include <fstream>
#include <string>
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

  string line1;
  string line2;
  string line3;
  string line4;
  while (getline(input, line1) && getline(input, line2) && getline(input, line3) && getline(input, line4)) {
    line1[0] = '>';
    output << line1 << '\n';
    output << line2 << '\n';
  }
  input.close();
  output.close();

  return 0;
}
