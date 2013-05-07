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
  ;

  // positional options
  po::positional_options_description pos;
  pos.add("source", 1);
  pos.add("check", 2);

  po::options_description dpos("Positionals");
  dpos.add_options()
      ("source", po::value<string>()->default_value("top100k"), "Source dictionary.")
      ("check",  po::value<string>()->default_value("top5k"),   "Pruning dictionary.")
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

