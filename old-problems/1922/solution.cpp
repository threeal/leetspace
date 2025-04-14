class Solution {
 public:
  int countGoodNumbers(long long n) {
    return (pow(5, n / 2 + n % 2) * pow(4, n / 2)) % 1000000007;
  }

 private:
  static long long pow(long long x, long long n) {
    long long res{1};
    while (n != 0) {
      if (n % 2) res = (res * x) % 1000000007;
      x = (x * x) % 1000000007;
      n /= 2;
    }
    return res;
  }
};
