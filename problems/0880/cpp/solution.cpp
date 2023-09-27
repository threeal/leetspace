class Solution {
 private:
  string str;

 public:
  string decodeAtIndex(string s, int k) {
    str = s;
    return string() + decode(k - 1);
  }

  char decode(int k) {
    int i = 0;
    for (const auto c : str) {
      if (c > '9') {
        if (i++ == k) {
          return c;
        }
      } else {
        const int repeat = c - '0';
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
