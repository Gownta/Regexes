#include "reader.hpp"
#include <iostream>
#include <fstream>

using namespace std;

set<string> read_words(const string & filename) {
  set<string> ret;

  string line;
  ifstream myfile(filename);
  if (myfile.is_open()) {
    while (myfile.good()) {
      getline(myfile, line);

      // skip if not [a-z]*
      if (line.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos) continue;

      ret.insert(line);
    }
    myfile.close();
  } else {
    cerr << "Unable to open file " << filename << endl;
    exit(1);
  }

  cout << "Read " << ret.size() << " words from " << filename << endl;

  return ret;
}

