#include "program_options.hpp"
#include <iostream>

using namespace std;

static po::options_description desc("Puzzler Options");
static po::variables_map vm;

po::variables_map & cmd_options() {
  return vm;
}

void read_options(int argc, char ** argv) {
  //
  // The options
  //
  desc.add_options()
      // main
      ("help,h", "Display help message.")

      // regexes
      ("regex-size,r", po::value<int>()->default_value(3), "Regex size.")
      ("secondary,s", po::value<string>()/*->default_value("wordlists/top100k")*/, "Refine search by secondary file.")

      // method
      ("shape", "Find words of unique shape.")
  ;

  // positional options
  po::positional_options_description pos;
  pos.add("source", 1);

  po::options_description dpos("Positionals");
  dpos.add_options()
      ("source", po::value<string>()->default_value("wordlists/top100k"), "Source dictionary.")
  ;

  // parse the command line
  po::options_description all;
  all.add(desc).add(dpos);

  po::store(po::command_line_parser(argc, argv).options(all).positional(pos).run(), vm);
  po::notify(vm);
}

void print_options() {
  cout << desc << endl;
}

