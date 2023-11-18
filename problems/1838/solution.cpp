class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    size_t left = 0;
    long curr = 0;
    for (size_t right = 0; right < nums.size(); ++right) {
      curr += nums[right];
      if (long(right - left + 1) * nums[right] - curr > k) {
        curr -= nums[left];
        ++left;
      }
    }

    return nums.size() - left;
  }
};
