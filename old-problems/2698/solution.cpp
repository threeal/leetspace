class Solution {
 public:
  int punishmentNumber(int n) {
    static const int nums[29]{
        1, 9, 10, 36, 45, 55, 82, 91, 99, 100, 235, 297, 369, 370, 379, 414,
        657, 675, 703, 756, 792, 909, 918, 945, 964, 990, 991, 999, 1000};

    for (int i = 28; i >= 0; --i) {
      if (nums[i] <= n) {
        int sum{0};
        while (i >= 0) {
          sum += nums[i] * nums[i];
          --i;
        }
        return sum;
      }
    }

    return 0;
  }
};
