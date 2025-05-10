#include <vector>

extern "C" {
int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize);
}

int solution_c(std::vector<int> tops, std::vector<int> bottoms) {
  return minDominoRotations(
      tops.data(), tops.size(), bottoms.data(), bottoms.size());
}
