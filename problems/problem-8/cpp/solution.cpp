class Solution {
 public:
  int myAtoi(string s) {
    const int n = s.size();

    int i;
    for (i = 0; i < n; ++i) {
      if (s[i] >= '0' && s[i] <= '9') break;
      switch (s[i]) {
        case ' ':
        case '+':
        case '-':
          continue;

        default:
          return 0;
      }
    }

    const bool neg = i > 0 && s[i - 1] == '-';

    int total = 0;
    for (; i < n; ++i) {
      if (s[i] < '0' || s[i] > '9') break;
      if (neg) {
        if (total <= -214748364) {
          if (total < -214748364 || s[i] - '0' >= 8)
            return -2147483648;
        }
        total = total * 10 - (s[i] - '0');
      } else {
        if (total >= 214748364) {
          if (total > 214748364 || s[i] - '0' >= 7)
            return 2147483647;
        }
        total = total * 10 + (s[i] - '0');
      }
    }

    return total;
  }
};
