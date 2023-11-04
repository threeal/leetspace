class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    if (left.empty()) return n - *min_element(right.begin(), right.end());
    if (right.empty()) return *max_element(left.begin(), left.end());
    return max(
        n - *min_element(right.begin(), right.end()),
        *max_element(left.begin(), left.end()));
  }
};
