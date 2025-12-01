#include <string>
#include <vector>

class Solution {
 public:
  int beautySum(std::string s) {
    for (char& c : s) c -= 'a';

    int sum{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      std::vector<int> freqs(26, 0);
      ++freqs[s[i]];

      char most{s[i]}, least{s[i]};

      for (std::size_t j{i + 1}; j < s.size(); ++j) {
        ++freqs[s[j]];
        if (freqs[s[j]] > freqs[most]) most = s[j];
        if (s[j] == least) {
          for (char c{0}; c < 26; ++c) {
            if (freqs[c] != 0 && freqs[c] < freqs[least]) least = c;
          }
        } else if (freqs[s[j]] < freqs[least]) {
          least = s[j];
        }

        sum += freqs[most] - freqs[least];
      }
    }

    return sum;
  }
};
