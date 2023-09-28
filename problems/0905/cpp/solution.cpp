class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    list<int> odd, even;

    for (const auto num : nums) {
      if (num % 2)
        odd.push_back(num);
      else
        even.push_back(num);
    }

    size_t i = 0;
    for (const auto num : even) {
      nums[i++] = num;
    }
    for (const auto num : odd) {
      nums[i++] = num;
    }

    return nums;
  }
};
