#include <algorithm>
#include <unordered_map>
#include <vector>

class FindSumPairs {
  std::vector<int>&nums1{nums1}, nums2{nums2};
  std::unordered_map<int, int> freqs{};

 public:
  FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) : nums1{nums1}, nums2{nums2} {
    std::sort(this->nums1.begin(), this->nums1.end());
    for (const int num : this->nums2) ++freqs[num];
  }

  void add(int index, int val) {
    --freqs[nums2[index]];
    nums2[index] += val;
    ++freqs[nums2[index]];
  }

  int count(int tot) {
    int count{0};
    for (const int num : nums1) {
      if (num >= tot) break;
      const auto it = freqs.find(tot - num);
      if (it != freqs.end()) count += it->second;
    }
    return count;
  }
};
