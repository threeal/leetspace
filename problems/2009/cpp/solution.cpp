class Solution {
 public:
  int minOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    const int n = nums.size();

    int a = 0;
    int b = n - 1;

    while (a < b) {
      if (nums[b] - nums[a] < n) {
        break;
      }

      const int aa = nums[a + 1] - nums[a];
      const int bb = nums[b] - nums[b - 1];
      if (aa > bb) {
        ++a;
      } else {
        --b;
      }
    }

    int duplicates = 0;
    for (int i = a + 1; i <= b; ++i) {
      if (nums[i] == nums[i - 1]) {
        ++duplicates;
      }
    }

    return n - (b - a + 1) + duplicates;
  }
};
