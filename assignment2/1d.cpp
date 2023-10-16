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
  char recognition;
  string header;
  string WP;
  // int query_number;
  // int start;
  // int matching_length;
  bool empty_header = true;
  bool first_line = true;

  while (getline(input, line)) {
    stringstream ss(line);
    ss >> recognition;
    if (recognition == '>' && empty_header) {
        if (first_line) {
            first_line = false;
            ss >> header;
        } else {
            string filter;
            string line_predict;
            int start;
            int end;
            char strand;
            int frame;
            float score;
            ifstream input_predict("tag.predict");;
            while (getline(input_predict, line_predict)) {
              size_t pos = line_predict.find(header);
              if (pos != string::npos) {
                stringstream ss_predict(line_predict);
                ss_predict >> filter >> start >> end >> strand >> frame >> score;
              }
            }
            if (start > end) {
              int store = start;
              start = end;
              end = store;
            }
            output << "scf7180000000010\t" << header << "\tCDS\t" << start << "\t" << end << "\t" << score << "\t" << strand << "\t" << frame - 1 << "\tmatch=none" << endl; 
            ss >> header;
            empty_header = true;
        }
    }
    else if (recognition == '>' && !empty_header) {
        ss >> header;
        empty_header = true;
    }
    else {
        empty_header = false;
        ss >> WP;
        string line_GCF;
        string filter1;
        string filter2;
        char firstchar;
        string name;
        ifstream input_GCF("GCF_002752995.1_ASM275299v1_protein.faa");;
        while (getline(input_GCF, line_GCF)) {
            size_t pos = line_GCF.find(WP);
            if (pos != string::npos) {
                stringstream ss_GCF(line_GCF);
                ss_GCF >> filter1 >> filter2 >> firstchar;
                getline(ss_GCF, name);
            }
        }
        string line_predict;
        string filter3;
        int start;
        int end;
        char strand;
        int frame;
        float score;
        ifstream input_predict("tag.predict");;
        while (getline(input_predict, line_predict)) {
            size_t pos = line_predict.find(header);
            if (pos != string::npos) {
                stringstream ss_predict(line_predict);
                ss_predict >> filter3 >> start >> end >> strand >> frame >> score;
            }
        }
        input_GCF.close();
        input_predict.close();
        if (start > end) {
          int store = start;
          start = end;
          end = store;
        }
        output << "scf7180000000010\t" << header << "\tCDS\t" << start << "\t" << end << "\t" << score << "\t" << strand << "\t" << frame - 1 << "\tmatch=" 
            << recognition << WP << "; \"" << firstchar << name << "\"" << endl;
    }
  }
  // output << header << "\tmummer4.0.0rc1\tCDS\t.\t.\t.\t+\t.\tmatch=none" << endl;

  // Dealing with last line
  string line_predict;
  string filter;
  int start;
  int end;
  char strand;
  int frame;
  float score;
  ifstream input_predict("tag.predict");;
  while (getline(input_predict, line_predict)) {
    size_t pos = line_predict.find(header);
    if (pos != string::npos) {
      stringstream ss_predict(line_predict);
      ss_predict >> filter >> start >> end >> strand >> frame >> score;
    }
  }
  if (start > end) {
    int store = start;
    start = end;
    end = store;
  }
  output << "scf7180000000010\t" << header << "\tCDS\t" << start << "\t" << end << "\t" << score << "\t" << strand << "\t" << frame - 1 << "\tmatch=none" << endl; 
  input.close();
  output.close();

  return 0;
}