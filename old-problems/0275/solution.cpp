#include <vector>

class Solution {
 public:
  int hIndex(std::vector<int>& citations) {
    int count = citations.size();
    for (std::size_t i{0}; i < citations.size(); ++i, --count) {
      if (citations[i] >= count) return count;
    }
    return count;
  }
};
