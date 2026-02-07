#include <vector>

class Solution {
 public:
  char nextGreatestLetter(std::vector<char>& letters, char target) {
    char res{127};
    for (char c : letters) {
      if (c > target && c < res) res = c;
    }

    return res == 127 ? letters[0] : res;
  }
};
