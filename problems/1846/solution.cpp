class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int max = 0;
    for (const auto num : arr) {
      if (num - max > 0) ++max;
    }

    return max;
  }
};
