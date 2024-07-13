class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int drinkBottles{numBottles};
    while (numBottles >= numExchange) {
      drinkBottles += numBottles / numExchange;
      numBottles = numBottles / numExchange + numBottles % numExchange;
    }
    return drinkBottles;
  }
};
