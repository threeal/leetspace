#include <bit>
#include <cstdint>
#include <vector>

class Solution {
 public:
  std::vector<int> findThePrefixCommonArray(
      std::vector<int>& A, std::vector<int>& B) {
    std::uint64_t a{0}, b{0};
    for (std::size_t i{0}; i < A.size(); ++i) {
      a |= 1l << A[i];
      b |= 1l << B[i];
      A[i] = std::popcount(a & b);
    }
    return A;
  }
};
