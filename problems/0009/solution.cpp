class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;

    int high{1000000000};
    while (high > x) high /= 10;

    int low{1};
    while (low < high) {
      if (x / low % 10 != x / high % 10) return false;
      high /= 10;
      low *= 10;
    }

    return true;
  }
};
