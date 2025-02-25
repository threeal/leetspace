#include <cstring>
#include <string>

class Solution {
 public:
  std::string getSmallestString(int n, int k) {
    std::string s(n, 'a');
    k -= n;
    std::memset(s.data() + n - k / 25, 'z', k / 25);
    if (k % 25 > 0) s[n - k / 25 - 1] += k % 25;
    return s;
  }
};
