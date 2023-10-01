class Solution {
 public:
  string reverseWords(string s) {
    const int n = s.size();
    int a = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == ' ') {
        swap(s, a, i - 1);
        a = i + 1;
      }
    }
    if (s[n - 1] != ' ') {
      swap(s, a, n - 1);
    }
    return s;
  }

  void swap(string& s, int a, int b) {
    while (b > a) {
      auto tmp = s[a];
      s[a] = s[b];
      s[b] = tmp;
      ++a;
      --b;
    }
  }
};
