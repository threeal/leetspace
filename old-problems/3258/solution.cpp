#include <string>

class Solution {
 public:
  int countKConstraintSubstrings(std::string s, int k) {
    std::size_t count{0};
    int zeros{0}, ones{0};
    for (std::size_t l{0}, r{0}; r < s.size(); ++r) {
      if (s[r] == '0') {
        ++zeros;
      } else {
        ++ones;
      }

      while (zeros > k && ones > k) {
        if (s[l] == '0') {
          --zeros;
        } else {
          --ones;
        }
        ++l;
      }

      count += r - l + 1;
    }
    return count;
  }
};
