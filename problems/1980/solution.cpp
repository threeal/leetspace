class Solution {
 public:
  string findDifferentBinaryString(vector<string>& nums) {
    sort(nums.begin(), nums.end());

    string res(nums.size(), '0');
    for (const auto& num : nums) {
      if (num != res) break;

      auto c = res.rbegin();
      *c += 1;
      while (*c == '2') {
        *c = '0';
        ++c;
        *c += 1;
      }
    }

    return res;
  }
};
