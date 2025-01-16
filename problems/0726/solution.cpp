#include <cstdint>
#include <map>
#include <sstream>
#include <string>
#include <utility>

class Solution {
 public:
  std::string countOfAtoms(std::string formula) {
    std::map<std::pair<char, char>, int> atoms{};
    count(atoms, formula.data(), formula.size() - 1);

    std::stringstream ss{};
    for (const auto& [atom, count] : atoms) {
      ss << atom.first;
      if (atom.second != 0) ss << std::get<1>(atom);
      if (count > 1) ss << count;
    }

    return ss.str();
  }

  int count(
      std::map<std::pair<char, char>, int>& atoms,
      const char* formula, int i) {
    while (i >= 0) {
      if (formula[i] >= 'a') {
        ++atoms[{formula[i - 1], formula[i]}];
        i -= 2;
      } else if (formula[i] >= 'A') {
        ++atoms[{formula[i], 0}];
        --i;
      } else if (formula[i] >= '0') {
        std::uint32_t exp{1};
        std::uint32_t num{0};
        while (formula[i] >= '0' && formula[i] <= '9') {
          num += (formula[i] - '0') * exp;
          exp *= 10;
          --i;
        }

        if (formula[i] >= 'a') {
          atoms[{formula[i - 1], formula[i]}] += num;
          i -= 2;
        } else if (formula[i] >= 'A') {
          atoms[{formula[i], 0}] += num;
          --i;
        } else if (formula[i] == ')') {
          std::map<std::pair<char, char>, int> subAtoms{};
          i = count(subAtoms, formula, i - 1);
          for (const auto& [atom, count] : subAtoms) {
            atoms[atom] += count * num;
          }
        }
      } else if (formula[i] == '(') {
        return i - 1;
      } else if (formula[i] == ')') {
        std::map<std::pair<char, char>, int> subAtoms{};
        i = count(subAtoms, formula, i - 1);
        for (const auto& [atom, count] : subAtoms) {
          atoms[atom] += count;
        }
      }
    }

    return i;
  }
};
