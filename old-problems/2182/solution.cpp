#include <string>

class Solution {
 public:
  std::string repeatLimitedString(std::string s, int repeatLimit) {
    int freqs[26] = {0};
    for (const auto c : s) {
      ++freqs[c - 'a'];
    }

    int curr{25};
    while (curr >= 0 && freqs[curr] == 0) --curr;

    int next{curr - 1};
    while (next >= 0 && freqs[next] == 0) --next;

    std::size_t i{0};
    while (curr >= 0) {
      if (freqs[curr] > repeatLimit) {
        for (int k{repeatLimit}; k > 0; --k, ++i) s[i] = 'a' + curr;
        freqs[curr] -= repeatLimit;

        if (next < 0) break;
        s[i] = 'a' + next;
        ++i;

        --freqs[next];
        while (next >= 0 && freqs[next] == 0) --next;
      } else {
        for (int k{freqs[curr]}; k > 0; --k, ++i) s[i] = 'a' + curr;
        freqs[curr] = 0;

        curr = next;
        --next;
        while (next >= 0 && freqs[next] == 0) --next;
      }
    }

    s.resize(i);
    return s;
  }
};
