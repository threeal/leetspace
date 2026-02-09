#include <vector>

class Solution {
 public:
  double separateSquares(std::vector<std::vector<int>>& squares) {
    double lowY = squares[0][1];
    double highY = squares[0][1] + squares[0][2];
    for (std::size_t i{1}; i < squares.size(); ++i) {
      double low = squares[i][1];
      if (low < lowY) lowY = low;

      double high = squares[i][1] + squares[i][2];
      if (high > highY) highY = high;
    }

    while (highY - lowY >= 0.00001) {
      const double midY{lowY + (highY - lowY) / 2};

      double lowSum{0}, highSum{0};
      for (const auto& square : squares) {
        const double y = square[1], l = square[2];
        if (y >= midY) {
          highSum += l * l;
        } else if (y + l <= midY) {
          lowSum += l * l;
        } else {
          lowSum += (midY - y) * l;
          highSum += (y + l - midY) * l;
        }
      }

      if (lowSum >= highSum) {
        highY = midY;
      } else {
        lowY = midY;
      }
    }

    return lowY;
  }
};
