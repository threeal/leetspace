class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int res = 0;
    for (const auto num : arr) {
      res = min(res + 1, num);
    }

    return res;
  }
};
