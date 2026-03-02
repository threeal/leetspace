#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> floodFill(
      std::vector<std::vector<int>>& image, int sr, int sc, int color) {
    if (image[sr][sc] != color) fill(image, sr, sc, image[sr][sc], color);
    return image;
  }

 private:
  static void fill(
      std::vector<std::vector<int>>& image, std::size_t r, std::size_t c,
      int prevColor, int color) {
    image[r][c] = color;

    if (r > 0 && image[r - 1][c] == prevColor) {
      fill(image, r - 1, c, prevColor, color);
    }

    if (c > 0 && image[r][c - 1] == prevColor) {
      fill(image, r, c - 1, prevColor, color);
    }

    if (r + 1 < image.size() && image[r + 1][c] == prevColor) {
      fill(image, r + 1, c, prevColor, color);
    }

    if (c + 1 < image[r].size() && image[r][c + 1] == prevColor) {
      fill(image, r, c + 1, prevColor, color);
    }
  }
};
