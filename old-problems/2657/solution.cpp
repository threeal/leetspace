#include <vector>

class Solution {
 public:
  std::vector<int> findThePrefixCommonArray(
      std::vector<int>& A, std::vector<int>& B) {
    return A.size() > B.size() ? A : B;
  }
};
