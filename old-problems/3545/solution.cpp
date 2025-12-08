#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int minDeletion(std::string s, int k) {
    std::vector<int> freqs(26, 0);
    for (const char c : s) ++freqs[c - 'a'];

    std::sort(freqs.begin(), freqs.end(), std::greater<int>());

    int deletion{0};
    for (int i{k}; i < 26; ++i) deletion += freqs[i];

    return deletion;
  }
};
