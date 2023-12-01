#include <vector>

class Solution {
 public:
  std::vector<int> findArray(std::vector<int>& pref) {
    std::vector<int> res = pref;
    for (size_t i = 1; i < res.size(); ++i) {
      res[i] = pref[i - 1] ^ pref[i];
    }
    return res;
  }
};
