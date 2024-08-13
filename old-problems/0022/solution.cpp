#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> out{};
    std::string str(n * 2, '.');
    str.front() = '(';
    str.back() = ')';
    generate(out, str.data(), str.size() - 2, 1, n);
    return out;
  }

 private:
  void generate(
      std::vector<std::string>& out, char* str, int i,
      int closers, int maxClosers) {
    if (i == 0) {
      out.push_back(std::string(str));
    } else {
      if (closers < maxClosers) {
        str[i] = ')';
        generate(out, str, i - 1, closers + 1, maxClosers);
      }
      if (closers > 0) {
        str[i] = '(';
        generate(out, str, i - 1, closers - 1, maxClosers - 1);
      }
    }
  }
};
