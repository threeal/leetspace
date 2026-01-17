#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  double separateSquares(std::vector<std::vector<int>>& squares) {
    std::vector<int> yLines{};

    std::priority_queue<
        std::vector<int>,
        std::vector<std::vector<int>>,
        std::greater<>>
        rects{};

    for (const auto& square : squares) {
      yLines.push_back(square[1]);
      yLines.push_back(square[1] + square[2]);
      rects.push(
          {square[1], square[0], square[1] + square[2], square[0] + square[2]});
    }

    std::sort(yLines.begin(), yLines.end());

    std::size_t n{1};
    for (std::size_t i{1}; i < yLines.size(); ++i) {
      if (yLines[i] != yLines[i - 1]) yLines[n++] = yLines[i];
    }
    yLines.resize(n);

    int topArea{0};
    std::vector<int> yWidths(yLines.size());
    yWidths[0] = 0;

    for (std::size_t i{1}; i < yLines.size(); ++i) {
      int width{0}, x{0};
      while (!rects.empty() && rects.top()[0] < yLines[i]) {
        std::vector<int> rect{rects.top()};
        rects.pop();

        width += rect[3] - std::max(rect[1], x);
        x = rect[3];

        if (rect[2] > yLines[i]) {
          rect[0] = yLines[i];
          rects.push(rect);
        }
      }

      topArea += (yLines[i] - yLines[i - 1]) * width;
      yWidths[i] = width;
    }

    int bottomArea{0};
    std::size_t i{0};
    while (bottomArea < topArea) {
      ++i;
      const int area{(yLines[i] - yLines[i - 1]) * yWidths[i]};
      bottomArea += area;
      topArea -= area;
    }

    return yLines[i] -
        static_cast<double>(bottomArea - topArea) / (yWidths[i] * 2);
  }
};
