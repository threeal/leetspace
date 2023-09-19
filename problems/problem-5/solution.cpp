class Solution {
 public:
  string longestPalindrome(string s) {
    string res = s.substr(0, 1);
    const int n = s.size();
    for (int i = 1; i < n; ++i) {
      auto ss = palindromeEven(s, i - 1, i);
      if (ss.size() > res.size()) res = ss;
      if (i < n - 1) {
        ss = palindromeOdd(s, i);
        if (ss.size() > res.size()) res = ss;
      }
    }
    return res;
  }

  string palindromeEven(const string& s, int a, int b) {
    if (s[a] != s[b]) return "";
    const int n = s.size();
    while (a >= 0 && b < n) {
      if (s[a] != s[b]) break;
      --a;
      ++b;
    }
    return s.substr(a + 1, b - a - 1);
  }

  string palindromeOdd(const string& s, int i) {
    return palindromeEven(s, i - 1, i + 1);
  }
};
