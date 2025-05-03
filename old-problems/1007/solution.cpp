#include <vector>

class Solution {
 public:
  int minDominoRotations(std::vector<int>& tops, std::vector<int>& bottoms) {
    int rotations{minDominoRotationsForNumber(tops, bottoms, tops[0])};
    if (rotations == -1 && tops[0] != bottoms[0]) {
      rotations = minDominoRotationsForNumber(tops, bottoms, bottoms[0]);
    }
    return rotations;
  }

 private:
  static int minDominoRotationsForNumber(
      std::vector<int>& tops, std::vector<int>& bottoms, int num) {
    int topFreqs{0}, bottomFreqs{0};
    for (std::size_t i{0}; i < tops.size(); ++i) {
      if (tops[i] == num) {
        if (bottoms[i] != num) {
          ++topFreqs;
        }
      } else {
        if (bottoms[i] == num) {
          ++bottomFreqs;
        } else {
          return -1;
        }
      }
    }
    return topFreqs <= bottomFreqs ? topFreqs : bottomFreqs;
  }
};
