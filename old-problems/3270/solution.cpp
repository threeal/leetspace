class Solution {
 public:
  int generateKey(int num1, int num2, int num3) {
    return num1 ^ num2 ^ num3;
  }
};
