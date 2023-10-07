class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> counts;
    for (auto num : nums) {
      ++counts[num];
    }

    vector<int> result;
    const int threshold = nums.size() / 3;
    for (auto [num, count] : counts) {
      if (count > threshold) result.push_back(num);
    }

    return result;
  }
};
