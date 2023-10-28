class Solution {
 public:
  string longestPalindrome(string s) {
    const int n = s.size();

    int res_a = 0;
    int res_n = 1;

    const function<void(int, int)> fn = [&](int a, int b) {
      if (s[a] != s[b]) return;
      while (a >= 0 && b < n) {
        if (s[a] != s[b]) break;
        --a;
        ++b;
      }
      if (b - a - 1 > res_n) {
        res_a = a + 1;
        res_n = b - a - 1;
      }
    };

    for (int i = 1; i < n; ++i) {
      fn(i - 1, i);
      if (i < n - 1) {
        fn(i - 1, i + 1);
      }
    }
    return s.substr(res_a, res_n);
  }
};
