#ifndef GOWNTA_PUZZLER_HPP
#define GOWNTA_PUZZLER_HPP

#include <set>
#include <string>

void puzzle(const std::set<std::string> & regexes,
            const std::set<std::string> & large,
            const std::set<std::string> & small);

void shape_puzzle(const std::set<std::string> & words);

#endif // GOWNTA_PUZZLER_HPP

