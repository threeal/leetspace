#include <string>

class Solution {
 public:
  std::string pushDominoes(std::string dominoes) {
    bool rExist{false};
    std::size_t l{0}, r{0}, i{0};
    while (i < dominoes.size()) {
      if (dominoes[i] != '.') {
        if (dominoes[i] == 'R') {
          if (rExist) {
            while (++r < i) dominoes[r] = 'R';
          } else {
            rExist = true;
            r = i;
          }
        } else {
          if (rExist) {
            l = i;
            while (++r < --l) {
              dominoes[r] = 'R';
              dominoes[l] = 'L';
            }
            rExist = false;
            l = i + 1;
          } else {
            while (l < i) dominoes[l++] = 'L';
            ++l;
          }
        }
      }
      ++i;
    }

    if (rExist) {
      while (++r < dominoes.size()) dominoes[r] = 'R';
    }

    return dominoes;
  }
};
