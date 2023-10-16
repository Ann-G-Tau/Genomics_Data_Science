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

  string line;
  while (getline(input, line)) {
    for(int i = line.size() - 1; i >= 0; i--) {
      switch (line[i]){
        case 'A':
          output << 'T';
          break;
        case 'T':
          output << 'A';
          break;
        case 'C':
          output << 'G';
          break;
        case 'G':
          output << 'C';
          break;
        }
    }
    output << '\n';
  }
  input.close();
  output.close();

  return 0;
}
