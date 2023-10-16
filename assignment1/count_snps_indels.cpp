#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char** argv) {

  if (argc != 2) {
    cout << "Incorrect number of input arguments\n";
    return 1;
  }

  ifstream input;
  input.open(argv[1]);
  if (!input.is_open()) {
    cout << "Unable to open input file\n";
    return 2;
  }

  string line;
  int snps = 0;
  int indels = 0;
  getline(input, line);
  getline(input, line);
  getline(input, line);
  getline(input, line);
  getline(input, line);
  while (getline(input, line)) {
    if (line[11] == '.' || line[13] == '.') {
        snps++;
    } else {
        indels++;
    }
  }
  input.close();
  cout << "Number of SNPs:" << snps << endl; 
  cout << "Number of Indels:" << indels << endl;

  return 0;
}