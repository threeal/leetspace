class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    auto left = nums.begin();
    auto right = nums.end();
    --right;
    return shiftLeftRight(left, right, x, 1);
  }

  int shiftLeftRight(vector<int>::const_iterator left, vector<int>::const_iterator right, int x, int count) {
    const int left_res = shiftLeft(left, right, x, count);
    const int right_res = shiftRight(left, right, x, count);
    if (left_res > 0) {
      if (right_res > 0) {
        return min(left_res, right_res);
      }
      return left_res;
    }
    return right_res;
  }

  int shiftLeft(vector<int>::const_iterator left, vector<int>::const_iterator right, int x, int count) {
    x -= *left;
    if (x > 0) {
      if (left == right) return -1;
      ++left;
      return shiftLeftRight(left, right, x, ++count);
    }
    return x == 0 ? count : -1;
  }

  int shiftRight(vector<int>::const_iterator left, vector<int>::const_iterator right, int x, int count) {
    x -= *right;
    if (x > 0) {
      if (left == right) return -1;
      --right;
      return shiftLeftRight(left, right, x, ++count);
    }
    return x == 0 ? count : -1;
  }
};
