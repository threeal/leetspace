#include <iostream>
#include <queue>
#include <vector>

class Solution {
 public:
  double separateSquares(std::vector<std::vector<int>>& squares) {
    std::priority_queue<
      std::vector<double>,
      std::vector<std::vector<double>>,
      std::greater<>
    > squareRects{};

    for (const auto& square : squares) {
      squareRects.push({
        static_cast<double>(square[1]),
        static_cast<double>(square[0]),
        static_cast<double>(square[2]),
        static_cast<double>(square[2])});
    }

    std::vector<std::vector<double>> rects{};
    rects.push_back(squareRects.top());
    squareRects.pop();

    while (!squareRects.empty()) {
      auto& rect = rects.back();
      auto& squareRect = squareRects.top();

      std::cout << rects.size() << " " << squareRects.size() << " -> ";

      for (const double num : rect) {
        std::cout << num << " ";
      }
      std::cout << " - ";

      for (const double num : squareRect) {
        std::cout << num << " ";
      }
      std::cout << "\n";

      if (rect[0] == squareRect[0]) {
        if (rect[2] == squareRect[2]) {
          if (rect[1] + rect[3] >= squareRect[1]) {
            const double width{squareRect[1] + squareRect[3] - rect[1]};
            if (width > rect[3]) rect[3] = width;
            squareRects.pop();
          } else {
            rects.push_back(squareRect);
            squareRects.pop();
          }
        } else {
          if (rect[2] > squareRect[2]) {
            std::vector<double> split{rect};
            rect[2] = squareRect[2];
            split[0] += rect[2];
            split[2] -= rect[2];
            squareRects.push(split);
          } else {
            auto squareRect = squareRects.top();
            squareRects.pop();

            std::vector<double> split{squareRect};
            squareRect[2] = rect[2];
            split[0] += squareRect[2];
            split[2] -= squareRect[2];

            squareRects.push(squareRect);
            squareRects.push(split);
          }
        }
      } else {
        if (rect[0] + rect[2] > squareRect[0]) {
          std::vector<double> split{rect};
          rect[2] = squareRect[0] - rect[0];
          split[0] += rect[2];
          split[2] -= rect[2];
          squareRects.push(split);
        } else {
          rects.push_back(squareRect);
          squareRects.pop();
        }
      }
    }


    std::cout << "res:\n";
    for (const double num : rects[0]) {
      std::cout << num << " ";
    }
    std::cout << "\n";

    double lowY{rects[0][0]};
    double highY{rects[0][0] + rects[0][2]};
    for (std::size_t i{1}; i < rects.size(); ++i) {
      for (const double num : rects[i]) {
        std::cout << num << " ";
      }
      std::cout << "\n";
      if (rects[i][0] < lowY) lowY = rects[i][0];
      if (rects[i][0] + rects[i][2] > highY) highY = rects[i][0] + rects[i][2];
    }

    while (highY - lowY >= 0.00001) {
      const double midY{lowY + (highY - lowY) / 2};

      double lowSum{0}, highSum{0};
      for (const auto& rect : rects) {
        if (rect[0] >= midY) {
          highSum += rect[2] * rect[3];
        } else if (rect[0] + rect[2] <= midY) {
          lowSum += rect[2] * rect[3];
        } else {
          lowSum += (midY - rect[0]) * rect[3];
          highSum += (rect[0] + rect[2] - midY) * rect[3];
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

// [[26,29,13],[24,30,13],[15,24,10]]

// 30 24 13 13
// 29 26 13 13
// 24 15 10 10

// 29 15 5 10
// 29 26 1 13
// 30 24 4 15
// 34 24 8 15
// 42 24 1 13
