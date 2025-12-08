class Solution {
 public:
  int splitNum(int num) {
    int freqs[10]{0};
    while (num != 0) {
      ++freqs[num % 10];
      num /= 10;
    }

    int num1{0}, num2{0}, digit{0};
    while (digit < 10) {
      if (freqs[digit] == 0) {
        ++digit;
      } else {
        if (num1 <= num2) {
          num1 = num1 * 10 + digit;
        } else {
          num2 = num2 * 10 + digit;
        }
        --freqs[digit];
      }
    }

    return num1 + num2;
  }
};
