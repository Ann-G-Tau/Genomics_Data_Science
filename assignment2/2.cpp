// Note: For all programs to run normally, please add “./” before executable name. 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main() {

  string unprocessed;
  string header;
  map<string, int> codon_table = {{"TTT", 0}, {"TTC", 0}, {"TTA", 0}, {"TTG", 0},
                                  {"TCT", 0}, {"TCC", 0}, {"TCA", 0}, {"TCG", 0},
                                  {"TAT", 0}, {"TAC", 0}, {"TAA", 0}, {"TAG", 0},
                                  {"TGT", 0}, {"TGC", 0}, {"TGA", 0}, {"TGG", 0},
                                  {"CTT", 0}, {"CTC", 0}, {"CTA", 0}, {"CTG", 0},
                                  {"CCT", 0}, {"CCC", 0}, {"CCA", 0}, {"CCG", 0},
                                  {"CAT", 0}, {"CAC", 0}, {"CAA", 0}, {"CAG", 0},
                                  {"CGT", 0}, {"CGC", 0}, {"CGA", 0}, {"CGG", 0},
                                  {"ATT", 0}, {"ATC", 0}, {"ATA", 0}, {"ATG", 0},
                                  {"ACT", 0}, {"ACC", 0}, {"ACA", 0}, {"ACG", 0},
                                  {"AAT", 0}, {"AAC", 0}, {"AAA", 0}, {"AAG", 0},
                                  {"AGT", 0}, {"AGC", 0}, {"AGA", 0}, {"AGG", 0},
                                  {"GTT", 0}, {"GTC", 0}, {"GTA", 0}, {"GTG", 0},
                                  {"GCT", 0}, {"GCC", 0}, {"GCA", 0}, {"GCG", 0},
                                  {"GAT", 0}, {"GAC", 0}, {"GAA", 0}, {"GAG", 0},
                                  {"GGT", 0}, {"GGC", 0}, {"GGA", 0}, {"GGG", 0}};
  getline(cin, unprocessed, '>');
  while (getline(cin, unprocessed, '>')) {
    stringstream ss(unprocessed);
    getline(ss, header);
    string line;
    string sequence;
    while (getline(ss, line)) {
      sequence += line;
    }
    for (int i = 0; i < sequence.length(); i += 3) {
      codon_table[sequence.substr(i, 3)]++;
    }
  }
  int total_codon = 0;
  for(auto it = codon_table.cbegin(); it != codon_table.cend(); ++it) {
    total_codon += it->second;
  }
  // This commented out segment of code is to see if total probability is 100%.
  float total_probability = 0;
  for(auto it = codon_table.cbegin(); it != codon_table.cend(); ++it) {
    if (it->first != "UAA" && it->first != "UAG" && it->first != "UGA") {
      total_probability += (float)it->second / (float)total_codon;
    }
  }
  cout << total_probability << endl;
  for(auto it = codon_table.cbegin(); it != codon_table.cend(); ++it) {
    if (it->first != "TAA" && it->first != "TAG" && it->first != "TGA") {
      cout << it->first << "\t" << (float)it->second / (float)total_codon << "\n";
    }
  }
  return 0;
}