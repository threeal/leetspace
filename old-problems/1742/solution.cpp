class Solution {
 public:
  int countBalls(int lowLimit, int highLimit) {
    int freqs[46]{0};
    for (int num{lowLimit}; num <= highLimit; ++num) {
      const int sum{
          (num % 10) + (num / 10 % 10) + (num / 100 % 10) + (num / 1000 % 10) +
          (num / 10000 % 10) + (num / 100000)};

      ++freqs[sum];
    }

    int maxFreq{0};
    for (int num{0}; num < 46; ++num) {
      if (freqs[num] > maxFreq) maxFreq = freqs[num];
    }

    return maxFreq;
  }
};
