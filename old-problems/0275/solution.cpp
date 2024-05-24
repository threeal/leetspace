#include <vector>

class Solution {
 public:
  int hIndex(std::vector<int>& citations) {
    int left{0};
    int right = citations.size();

    while (left < right) {
      const int mid{(left + right) / 2};
      if (citations[mid] >= static_cast<int>(citations.size()) - mid) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return static_cast<int>(citations.size()) - left;
  }
};
