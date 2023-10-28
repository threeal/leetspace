const unsigned int mod = 1'000'000'007;

class Solution {
 public:
  int countVowelPermutation(int n) {
    unsigned int a = 1, e = 1, i = 1, o = 1, u = 1;

    while (--n > 0) {
      const unsigned int aa = a, ee = e, ii = i, oo = o, uu = u;

      a = (ee + ii + uu) % mod;
      e = (aa + ii) % mod;
      i = (ee + oo) % mod;
      o = ii;
      u = (ii + oo) % mod;
    }

    return (a + e + i + o + u) % mod;
  }
};
