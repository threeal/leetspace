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

    int maxLength{0};
    for (auto num : arr2) {
      while (num > 0) {
        if (prefixes.contains(num)) {
          int length{0};
          while (num > 0) {
            ++length;
            num /= 10;
          }
          if (length > maxLength) maxLength = length;
          break;
        }
        num /= 10;
      }
    }

    return maxLength;
  }
};
