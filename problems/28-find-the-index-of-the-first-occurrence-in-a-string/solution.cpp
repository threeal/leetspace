class Solution {
 public:
  int strStr(string haystack, string needle) {
    int hn = haystack.size();
    int nn = needle.size();
    for (int hi = 0; hi <= hn - nn; ++hi) {
      bool ok = true;
      for (int i = 0; hi + i < hn && i < nn; ++i) {
        if (haystack[hi + i] != needle[i]) {
          ok = false;
          break;
        }
      }
      if (ok) return hi;
    }
    return -1;
  }
};
