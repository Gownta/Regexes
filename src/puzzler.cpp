#include "puzzler.hpp"
#include <iostream>
#include <regex>
#include <map>
#include <ctype.h>
#include "program_options.hpp"
using namespace std;

void puzzle(const std::set<std::string> & regexes,
            const std::set<std::string> & large,
            const std::set<std::string> & small) {
  bool second = cmd_options().count("secondary");

  for (const auto & reg : regexes) {
    // If there are 10+ consecutive matches, or 2 non-consecutive matches,
    // continue.

    regex rgx(reg); // regex
    bool good = true; // is this regex interesting

    set<string>::const_iterator first; // first match
    int num = 0; // number of consecutive matches
    bool passed = false; // have we passed the run of matches yet

    for (auto it = large.begin(); it != large.end(); ++it) {
      const auto & str = *it;
      if (regex_match(str, rgx)) {
        if (passed == true) {
          good = false;
          break;
        }

        if (num == 0) first = it;

        num++;
        if (num > 10) {
          good = false;
          break;
        }
      } else if (num > 0) {
        passed = true;
      }
    }

    if (!good || num == 0) continue;

    // now that we have a (potentially) good regex, make sure that the matched
    // word is also found in the small word set

    if (second) {
      bool insmall = false;
      auto firstc = first;
      for (int i = 0 ; i < num; ++i, ++firstc) {
        if (small.count(*firstc)) {
          insmall = true;
          break;
        }
      }

      if (!insmall) continue;
    }


    // we have a good regex. print it

    cout << reg << "\t:    ";
    auto firstc = first;
    for (int i = 0; i < num; ++i, ++firstc) cout << *firstc << " ";
    cout << endl;
  }
}

void shape_puzzle(const std::set<std::string> & words) {
  map<string, string> shapes;
  const string invalid("INVALID");

  for (const auto & word : words) {
    // find the word's shape
    // if the shape is already in the map, invalidate it
    // else add the unique shape to the map

    string shape;
    shape.reserve(word.size());
    for (char c : word) {
      if (!islower(c)) {
        shape = "";
        break;
      }

      switch (c) {
        case 'a':
        case 'c':
        case 'e':
        case 'i': // ??
        case 'm':
        case 'n':
        case 'o':
        case 'r':
        case 's':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'z':
          shape.push_back('o');
          break;

        case 'b':
        case 'd':
        case 'f':
        case 'h':
        case 'k':
        case 'l':
        case 't':
          shape.push_back('l');
          break;

        case 'g':
        case 'j':
        case 'p':
        case 'q':
        case 'y':
          shape.push_back('p');
          break;
      }

    }

    if (shapes.count(shape) == 0) shapes[shape] = word;
    else shapes[shape] = invalid;
  }

  for (const auto & kv : shapes) {
    if (kv.second != invalid) {
      cout << kv.first << "  \t" << kv.second << endl;
    }
  }
}

