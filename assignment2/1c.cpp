// Note: For all programs to run normally, please add “./” before executable name. 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
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
  string attribute;
  int start_position;
  int end_position;
  char strand;
  int frame;
  float score;
  getline(input, line);
  while (getline(input, line)) {
    stringstream ss(line);
    ss >> attribute >> start_position >> end_position >> strand >> frame >> score;
    if (start_position > end_position) {
      int storage = start_position;
      start_position = end_position;
      end_position = storage;
    }
    output << "scf7180000000010\tglimmer3\tCDS" << "\t" << start_position << "\t" << end_position 
      << "\t" << score << "\t" << strand << "\t" << frame - 1 << "\t" << "transcript_id " << "\"" << attribute << "\"\n";
  }
  input.close();
  output.close();

  return 0;
}