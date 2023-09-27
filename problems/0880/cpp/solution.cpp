struct Sub {
  size_t total;
  size_t a;
  size_t b;
  int repeat;
};

class Solution {
 public:
  string decodeAtIndex(string s, int k) {
    stack<Sub> subs;

    Sub sub{.total = 0, .a = 0};

    int j = 0;
    const size_t n = s.size();
    for (size_t i = 0; i < n; ++i) {
      if (s[i] > '9') {
        if (++j == k) {
          return string() + s[i];
        }
      } else {
        sub.b = i;
        sub.repeat = s[i] - '0';
        j += (sub.total + sub.b - sub.a) * (sub.repeat - 1);
        if (k > j) {
          subs.push(sub);
          sub.total = j;
          sub.a = sub.b + 1;
        } else {
          --k;
          while (sub.b - sub.a == 0) {
            k %= sub.total;
            sub = subs.top();
            subs.pop();
          }
          k %= sub.b - sub.a;
          return string() + s[sub.a + k];
        }
      }
    }
    return s;
  }
};
