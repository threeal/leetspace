class Solution {
 public:
  int passThePillow(int n, int time) {
    --n;
    return (time / n) % 2 == 0
        ? 1 + time % n
        : 1 + n - time % n;
  }
};
