#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  bool canTraverseAllPairs(std::vector<int>& nums) {
    if (nums.size() == 1) return true;

    int maxNum{0};
    for (const int num : nums) {
      if (num == 1) return false;
      if (num > maxNum) maxNum = num;
    }

    std::vector<int> rootOf(maxNum + 1);
    std::iota(rootOf.begin(), rootOf.end(), 0);

    for (int prime{2}; prime <= maxNum; ++prime) {
      int primeRoot{getRootOf(rootOf, prime)};
      if (primeRoot == prime) {
        for (int num{prime + prime}; num <= maxNum; num += prime) {
          const int root{getRootOf(rootOf, num)};
          if (root != primeRoot) {
            if (root <= primeRoot) {
              rootOf[primeRoot] = root;
              primeRoot = root;
            } else {
              rootOf[root] = primeRoot;
            }
          }
        }
      }
    }

    const int root{getRootOf(rootOf, nums[0])};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (getRootOf(rootOf, nums[i]) != root) return false;
    }

    return true;
  }

 private:
  static int getRootOf(std::vector<int>& rootOf, int x) {
    if (rootOf[x] == x) return x;
    return (rootOf[x] = getRootOf(rootOf, rootOf[x]));
  }
};
