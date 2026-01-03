class Solution {
 public:
  int numOfWays(int n) {
    long long a{6}, b{6};
    while (--n != 0) {
      const long long prevA{a}, prevB{b};
      a = (2 * prevA + 2 * prevB) % 1000000007;
      b = (2 * prevA + 3 * prevB) % 1000000007;
    }
    return (a + b) % 1000000007;
  }
};
