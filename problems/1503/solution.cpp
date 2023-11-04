class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    const auto l = left.empty() ? 0 : *max_element(left.begin(), left.end());
    const auto r = right.empty() ? 0 : *min_element(right.begin(), right.end());
    return max(l, n - r);
  }
};
