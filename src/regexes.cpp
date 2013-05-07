#include "regexes.hpp"
#include <iostream>
#include "program_options.hpp"

using namespace std;

set<string> get_regexes() {
  set<string> ret;

  // find all regexes of the form A_B_C
  // where A, B, and C are composed of at most N letters total

  int C = cmd_options()["regex-size"].as<int>();
  
  for (int ca = 0; ca <= C; ++ca)
  for (int cb = 0; cb <= C; ++cb)
  for (int cc = 0; cc <= C; ++cc)
  {
    if (ca + cb + cc < 2) continue;
    if (ca + cb + cc > C) continue;

    for (char c1 = 'a'; c1 <= 'z'; ++c1)
    for (char c2 = 'a'; c2 <= 'z'; ++c2)
    for (char c3 = 'a'; c3 <= 'z'; ++c3)
    for (char c4 = 'a'; c4 <= 'z'; ++c4)
    {
      // create the string
      char m[128];
      char c[4] = { c1, c2, c3, c4 };
      int n = 0;
      int p = 0;

      for (int i = 0 ; i < ca; ++i) m[p++] = c[n++];
      m[p++] = '.';
      m[p++] = '*';
      for (int i = 0 ; i < cb; ++i) m[p++] = c[n++];
      if (cb != 0) {
        m[p++] = '.';
        m[p++] = '*';
      }
      for (int i = 0 ; i < cc; ++i) m[p++] = c[n++];
      m[p++] = 0;

      ret.insert(string(m));
    }
  }

  cout << "Matching against " << ret.size() << " regexes" << endl;

  return ret;
}

