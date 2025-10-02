class Solution {
 public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int totalDrink{numBottles};
    while (numBottles >= numExchange) {
      ++totalDrink;
      numBottles += 1 - numExchange;
      ++numExchange;
    }
    return totalDrink;
  }
};
