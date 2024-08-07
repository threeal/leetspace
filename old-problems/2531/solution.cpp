#include <string>
#include <vector>

class Solution {
 public:
  bool isItPossible(std::string word1, std::string word2) {
    std::vector<int> freq1(26, 0);
    for (const auto c : word1) ++freq1[c - 'a'];

    std::vector<int> freq2(26, 0);
    for (const auto c : word2) ++freq2[c - 'a'];

    int distinct1{0};
    for (int i = 25; i >= 0; --i) {
      if (freq1[i] > 0) ++distinct1;
    }

    int distinct2{0};
    for (int i = 25; i >= 0; --i) {
      if (freq2[i] > 0) ++distinct2;
    }

    for (int i = 25; i >= 0; --i) {
      if (freq1[i] == 0) continue;
      if (--freq1[i] == 0) --distinct1;
      for (int j = 25; j >= 0; --j) {
        if (freq2[j] == 0) continue;
        if (++freq2[i] == 1) ++distinct2;
        if (--freq2[j] == 0) --distinct2;
        if (++freq1[j] == 1) ++distinct1;
        if (distinct1 == distinct2) return true;
        if (--freq1[j] == 0) --distinct1;
        if (++freq2[j] == 1) ++distinct2;
        if (--freq2[i] == 0) --distinct2;
      }
      if (++freq1[i] == 1) ++distinct1;
    }

    return false;
  }
};
