class Solution {
 public:
  int minimumFlips(int n) {
    int l{1};
    while ((l << 1) <= n) l <<= 1;

    int flips{0}, r{1};
    while (l > r) {
      if (((n & l) == 0) != ((n & r) == 0)) flips += 2;
      l >>= 1;
      r <<= 1;
    }

    return flips;
  }
};
