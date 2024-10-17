class Solution {
 public:
  int maximumSwap(int num) {
    int maxNum{num};
    for (int i = 1; i < num; i *= 10) {
      const int di{(num / i) % 10};
      for (int j = i * 10; j < num; j *= 10) {
        const int dj{(num / j) % 10};
        const int newNum{num + (di - dj) * j + (dj - di) * i};
        if (newNum > maxNum) maxNum = newNum;
      }
    }
    return maxNum;
  }
};
