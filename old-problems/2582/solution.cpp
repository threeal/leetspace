class Solution {
 public:
  int passThePillow(int n, int time) {
    return 1 + time % (n - 1);
  }
};
