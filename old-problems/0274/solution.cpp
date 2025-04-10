#include <algorithm>
#include <vector>

class Solution {
 public:
  int hIndex(std::vector<int>& citations) {
    std::sort(citations.begin(), citations.end());
    for (int n = citations.size(); n > 0; --n) {
      if (citations[citations.size() - n] >= n) return n;
    }
    return 0;
  }
};
