#include <string>

class Solution {
 public:
  int lengthAfterTransformations(std::string s, int t) {
    int freqs[26]{0};
    for (const char c : s) ++freqs[c - 'a'];

    while (--t >= 0) {
      const int temp{freqs[25]};
      for (int i{25}; i > 0; --i) {
        freqs[i] = freqs[i - 1];
      }
      freqs[0] = temp;
      freqs[1] = (freqs[1] + temp) % 1000000007;
    }

    int length{0};
    for (int i{0}; i < 26; ++i) {
      length = (length + freqs[i]) % 1000000007;
    }

    return length;
  }
};
