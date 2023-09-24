class Solution {
 public:
  int myAtoi(string s) {
    const int n = s.size();

    int i;
    for (i = 0; i < n; ++i) {
      if (s[i] >= '0' && s[i] <= '9') break;
    }

    const bool neg = i > 0 && s[i - 1] == '-';

    int total = 0;
    int mul = 1;
    for (; i < n; ++i) {
      if (s[i] < '0' || s[i] > '9') break;
      total = total * 10 + s[i] - '0';
    }

    return neg ? -total : total;
  }
};
