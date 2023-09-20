class Solution {
 public:
  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    const auto ae = a.end();
    const auto be = b.end();

    auto ai = a.begin();
    auto bi = b.begin();

    const auto n = a.size() + b.size();
    const auto n2 = n / 2;

    if (ai == ae) {
      return n % 2 == 0 ? (b[n2] + b[n2 - 1]) / 2.0 : b[n2];
    } else if (bi == be) {
      return n % 2 == 0 ? (a[n2] + a[n2 - 1]) / 2.0 : a[n2];
    }

    return 0;
  }
};
