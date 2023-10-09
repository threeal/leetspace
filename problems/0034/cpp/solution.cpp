class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    const int n = nums.size();

    int a = 0;
    int b = n - 1;

    while (a + 1 < b) {
      const int c = a + (b - a) / 2;
      if (nums[c] == target) {
        int c1 = c;
        while (c1 > 0) {
          if (nums[c1 - 1] != target) break;
          --c1;
        }

        int c2 = c;
        while (c2 < n - 1) {
          if (nums[c2 + 1] != target) break;
          ++c2;
        }

        return {c1, c2};
      }

      if (nums[c] < target) {
        a = c;
      } else {
        b = c;
      }
    }

    return {-1, -1};
  }
};
