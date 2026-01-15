class Solution {
 public:
  bool checkDivisibility(int n) {
    int sum{0}, product{1};
    for (int nn{n}; nn != 0; nn /= 10) {
      sum += nn % 10;
      product *= nn % 10;
    }
    return n % (sum + product) == 0;
  }
};
