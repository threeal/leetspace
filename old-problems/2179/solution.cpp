#include <vector>

class Solution {
 public:
  long long goodTriplets(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<std::size_t> indices2(nums2.size());
    for (std::size_t i2{0}; i2 < nums2.size(); ++i2) indices2[nums2[i2]] = i2;

    long long counts{0};
    std::vector<int> leftCounts(nums1.size() + 1, 0);
    for (std::size_t i1{0}; i1 < nums1.size(); ++i1) {
      const std::size_t i2{indices2[nums1[i1]]};
      const long long leftCount{queryTree(leftCounts, i2)};
      updateTree(leftCounts, i2, 1);
      (void)leftCount;
      const long long rightCount = nums2.size() - 1 - i2 - (i1 - leftCount);
      counts += leftCount * rightCount;
    }

    return counts;
  }

 private:
  static void updateTree(std::vector<int>& tree, std::size_t i, int delta) {
    ++i;
    while (i < tree.size()) {
      tree[i] += delta;
      i += i & -i;
    }
  }

  static int queryTree(std::vector<int>& tree, std::size_t i) {
    ++i;
    int sum{0};
    while (i > 0) {
      sum += tree[i];
      i -= i & -i;
    }
    return sum;
  }
};
