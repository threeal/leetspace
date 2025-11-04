#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> pacificAtlantic(
      std::vector<std::vector<int>>& heights) {
    const int h = heights.size();
    const int w = heights[0].size();

    std::vector<std::vector<char>> flags(h, std::vector<char>(w, 0));

    for (int y{0}; y < h; ++y) {
      if (flags[y][0] == 0) explorePacific(heights, flags, h, w, y, 0);
    }

    for (int x{0}; x < w; ++x) {
      if (flags[0][x] == 0) explorePacific(heights, flags, h, w, 0, x);
    }

    std::vector<std::vector<int>> output{};

    for (int y{0}; y < h; ++y) {
      if (flags[y][w - 1] < 2) {
        exploreAtlantic(output, heights, flags, h, w, y, w - 1);
      }
    }

    for (int x{0}; x < w; ++x) {
      if (flags[h - 1][x] < 2) {
        exploreAtlantic(output, heights, flags, h, w, h - 1, x);
      }
    }

    return output;
  }

  static void explorePacific(
      const std::vector<std::vector<int>>& heights,
      std::vector<std::vector<char>>& flags,
      const int h, const int w, int y, int x) {
    flags[y][x] = 1;

    if (y > 0 && flags[y - 1][x] == 0 && heights[y - 1][x] >= heights[y][x]) {
      explorePacific(heights, flags, h, w, y - 1, x);
    }

    if (x > 0 && flags[y][x - 1] == 0 && heights[y][x - 1] >= heights[y][x]) {
      explorePacific(heights, flags, h, w, y, x - 1);
    }

    if (y + 1 < h && flags[y + 1][x] == 0 &&
        heights[y + 1][x] >= heights[y][x]) {
      explorePacific(heights, flags, h, w, y + 1, x);
    }

    if (x + 1 < w && flags[y][x + 1] == 0 &&
        heights[y][x + 1] >= heights[y][x]) {
      explorePacific(heights, flags, h, w, y, x + 1);
    }
  }

  static void exploreAtlantic(
      std::vector<std::vector<int>>& output,
      const std::vector<std::vector<int>>& heights,
      std::vector<std::vector<char>>& flags,
      const int h, const int w, int y, int x) {
    if ((flags[y][x] |= 2) == 3) output.push_back({y, x});

    if (y > 0 && flags[y - 1][x] < 2 && heights[y - 1][x] >= heights[y][x]) {
      exploreAtlantic(output, heights, flags, h, w, y - 1, x);
    }

    if (x > 0 && flags[y][x - 1] < 2 && heights[y][x - 1] >= heights[y][x]) {
      exploreAtlantic(output, heights, flags, h, w, y, x - 1);
    }

    if (y + 1 < h && flags[y + 1][x] < 2 &&
        heights[y + 1][x] >= heights[y][x]) {
      exploreAtlantic(output, heights, flags, h, w, y + 1, x);
    }

    if (x + 1 < w && flags[y][x + 1] < 2 &&
        heights[y][x + 1] >= heights[y][x]) {
      exploreAtlantic(output, heights, flags, h, w, y, x + 1);
    }
  }
};
