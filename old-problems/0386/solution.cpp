#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> lexicalOrder(int n) {
    std::vector<int> out{};
    out.reserve(n);

    const int end = std::min(n, 9);
    for (int i{1}; i <= end; ++i) {
      pushLexicalOrder(out, i, n);
    }

    return out;
  }

 private:
  static void pushLexicalOrder(std::vector<int>& out, int num, int n) {
    out.push_back(num);
    if (num * 10 <= n) {
      const int end = std::min(n, num * 10 + 9);
      for (int i{num * 10}; i <= end; ++i) {
        pushLexicalOrder(out, i, n);
      }
    }
  }
};
