class Solution {
 public:
  int numTilings(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 5;

    int a{5}, b{2}, c{1};
    while (--n >= 3) {
      const int num{((a * 2) % 1000000007 + c) % 1000000007};
      c = b;
      b = a;
      a = num;
    }

    return a;
  }
};
