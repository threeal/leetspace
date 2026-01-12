#include <vector>

class Solution {
 public:
  int distributeCookies(std::vector<int>& cookies, int k) {
    return cookies.size() + k;
  }
};
