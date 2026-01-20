class Solution {
 public:
  int totalWaviness(int num1, int num2) {
    int sum{0};
    for (int num{num1}; num <= num2; ++num) {
      for (int exp{100}; exp <= num; exp *= 10) {
        const int a{(num / exp) % 10};
        const int b{(num / (exp / 10)) % 10};
        const int c{(num / (exp / 100)) % 10};
        if ((a < b && b > c) || (a > b && b < c)) ++sum;
      }
    }
    return sum;
  }
};
