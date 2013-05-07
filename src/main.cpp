#include <iostream>
#include "program_options.hpp"
using namespace std;

int main(int argc, char ** argv) {
  read_options(argc, argv);

  // Help
  if (cmd_options().count("help")) {
    cout << "\n     ===== Regex Puzzler =====\n\n"
              "     Nicholas (Gownta) Ormrod\n"
              "     njormrod@\n"
            "\n     =========================\n\n";

    cout << "Usage: puzzler [options] [source] [check] \n\n";

    print_options();

    return 1;
  }

  // Execute the lua scene.

  return 0;
}

