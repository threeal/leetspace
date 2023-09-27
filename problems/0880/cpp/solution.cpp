struct Sub {
  size_t total;
  size_t a;
  size_t b;
  int repeat;
};

class Solution {
 public:
  string decodeAtIndex(string s, int k) {
    --k;
    stack<Sub> subs;

    Sub sub{
        .total = 0,
        .a = 0,
    };

    const size_t n = s.size();
    for (size_t i = 0; i < n; ++i) {
      if (s[i] > '9') {
        if (k-- == 0) {
          return string() + s[i];
        }
      } else {
        sub.b = i;
        sub.repeat = s[i] - '0';
        const auto total_add = (sub.total + sub.b - sub.a) * (sub.repeat - 1);
        if (k > total_add) {
          k -= total_add;
          subs.push(sub);
          sub.total += sub.b - sub.a + total_add;
          sub.a = sub.b + 1;
        } else {
          k %= total_add;
          while (!subs.empty() && k <= sub.total) {
            sub = subs.top();
            subs.pop();
          }
          return string() + s[sub.a + k - sub.total];
        }
      }
    }
    return s;
  }
};
