class Solution {
 public:
  int findTheWinner(int n, int k) {
    return recurse(n, k) + 1;
  }

  int recurse(int n, int k) {
    if (n == 1) return 0;
    return (recurse(n - 1, k) + k) % n;
  }
};
