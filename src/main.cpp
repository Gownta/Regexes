#include <iostream>
#include <set>
#include <string>
#include "program_options.hpp"
#include "regexes.hpp"
#include "reader.hpp"
#include "puzzler.hpp"
using namespace std;

int main(int argc, char ** argv) {
  read_options(argc, argv);

  // Help
  if (cmd_options().count("help")) {
    cout << "\n     ===== Regex Puzzler =====\n\n"
              "     Nicholas (Gownta) Ormrod\n"
              "     njormrod@\n"
            "\n     =========================\n\n";

    cout << "Usage: puzzler [options] [source]\n\n";

    print_options();

    return 1;
  }

  // get regexes of interest
  set<string> regexes = get_regexes();

  // get words of interest
  set<string> large = read_words(cmd_options()["source"   ].as<string>());
  set<string> small;
  if (cmd_options().count("secondary")) small = read_words(cmd_options()["secondary"].as<string>());

  // match
  puzzle(regexes, large, small);

  return 0;
}

