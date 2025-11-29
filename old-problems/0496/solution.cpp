#include <stack>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> nextGreaterElement(
      std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int, std::size_t> indices{};
    for (std::size_t i{0}; i < nums1.size(); ++i) {
      indices.emplace(nums1[i], i);
    }

    std::stack<int> greaters{};
    for (std::size_t i{nums2.size()}; i > 0; --i) {
      const auto it = indices.find(nums2[i - 1]);
      if (it != indices.end()) {
        while (!greaters.empty() && greaters.top() <= it->first) greaters.pop();
        nums1[it->second] = greaters.empty() ? -1 : greaters.top();
      }
      greaters.push(nums2[i - 1]);
    }

    return nums1;
  }
};
