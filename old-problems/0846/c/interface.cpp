#include <cstring>
#include <vector>

extern "C" {
bool isNStraightHand(int* hand, int handSize, int groupSize);
}

bool solution_c(std::vector<int> hand, int groupSize) {
  return isNStraightHand(hand.data(), hand.size(), groupSize);
}
