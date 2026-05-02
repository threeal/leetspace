class Solution {
 public:
  int rotatedDigits(int n) {
    int count{0};
    for (int i{0}; i <= n; ++i) {
      bool isValid{true}, hasChange{false};
      for (int num{i}; num != 0; num /= 10) {
        switch (num % 10) {
          case 3:
          case 4:
          case 7:
            isValid = false;
            num = 0;
            break;

          case 2:
          case 5:
          case 6:
          case 9:
            hasChange = true;
            break;
        }
      }
      if (isValid && hasChange) ++count;
    }
    return count;
  }
};
