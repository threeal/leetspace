class Solution {
 public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    static const int min_val = numeric_limits<int>::min();

    const int n1 = nums1.size();
    const int n2 = nums2.size();

    auto cache = vector(n1, vector(n2, min_val));

    const function<int(int, int)> fn = [&](int i1, int i2) -> int {
      if (i1 >= n1 || i2 >= n2) return min_val;

      if (cache[i1][i2] > min_val) return cache[i1][i2];

      cache[i1][i2] = max({nums1[i1] * nums2[i2] + max(fn(i1 + 1, i2 + 1), 0),
                           fn(i1 + 1, i2),
                           fn(i1, i2 + 1),
                           fn(i1 + 1, i2 + 1)});

      return cache[i1][i2];
    };

    return fn(0, 0);
  }
};
