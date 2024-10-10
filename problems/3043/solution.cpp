#include <unordered_set>
#include <vector>

class Solution {
 public:
  int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::unordered_set<int> prefixes{};
    for (auto num : arr1) {
      while (num > 0) {
        prefixes.insert(num);
        num /= 10;
      }
    }

    static const int exp[11] = {
        0, 1, 10, 100, 1000, 10000, 100000, 1000000,
        10000000, 100000000, 1000000000};

    int maxLength{0};
    for (auto num : arr2) {
      while (num > 0 && num >= exp[maxLength]) {
        if (prefixes.contains(num)) {
          while (num >= exp[maxLength + 1]) ++maxLength;
          break;
        }
        num /= 10;
      }
    }

    return maxLength;
  }
};
