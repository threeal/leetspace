#include <string>
#include <vector>

class Solution {
 public:
  int findTheLongestSubstring(std::string s) {
    std::vector<int> maskPos(32, -2);
    maskPos[0] = -1;

    int longest{0};
    unsigned char mask{0};
    for (int i = 0; static_cast<std::size_t>(i) < s.size(); ++i) {
      switch (s[i]) {
        case 'a':
          mask ^= 1;
          break;

        case 'e':
          mask ^= 2;
          break;

        case 'i':
          mask ^= 4;
          break;

        case 'o':
          mask ^= 8;
          break;

        case 'u':
          mask ^= 16;
          break;
      }

      if (maskPos[mask] < -1) {
        maskPos[mask] = i;
      } else if (i - maskPos[mask] > longest) {
        longest = i - maskPos[mask];
      }
    }
    return longest;
  }
};
