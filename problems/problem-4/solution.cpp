class Solution {
 public:
  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    const auto ae = a.end();
    const auto be = b.end();

    auto ai = a.begin();
    auto bi = b.begin();

    int n = a.size() + b.size();

    const bool is_even = n % 2 == 0;
    n /= 2;

    if (ai == ae) {
      return is_even ? (b[n] + b[n - 1]) / 2.0 : b[n];
    } else if (bi == be) {
      return is_even ? (a[n] + a[n - 1]) / 2.0 : a[n];
    }

    stack<int> s;
    while (n >= 0) {
      if (*ai < *bi) {
        s.push(*ai);
        if (++ai == ae) {
          while (--n >= 0) {
            s.push(*bi);
            ++bi;
          }
        }
      } else {
        s.push(*bi);
        if (++bi == be) {
          while (--n >= 0) {
            s.push(*ai);
            ++ai;
          }
        }
      }
      --n;
    }

    double res = s.top();
    if (is_even) {
      s.pop();
      res = (res + s.top()) / 2.0;
    }

    return res;
  }
};
