class Solution {
 private:
  string str;

 public:
  string decodeAtIndex(string s, int k) {
    str = s;
    return string() + decode(k - 1);
  }

  char decode(uint64_t k) {
    uint64_t i = 0;
    for (const auto c : str) {
      if (c > '9') {
        if (i++ == k) {
          return c;
        }
      } else {
        const uint64_t repeat = c - '0';
        if (k < i * repeat) {
          return decode(k % i);
        } else {
          i *= repeat;
        }
      }
    }
    return '?';
  }
};
