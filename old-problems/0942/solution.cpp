#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> diStringMatch(std::string s) {
    std::vector<int> output(s.size() + 1);
    int a{0}, b = s.size();
    for (std::size_t i{0}; i < s.size(); ++i) {
      output[i] = s[i] == 'I' ? a++ : b--;
    }
    output[s.size()] = a;
    return output;
  }
};
