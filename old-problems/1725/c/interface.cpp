#include <vector>

extern "C" {
int countGoodRectangles(
    int** rectangles, int rectanglesSize, int* rectanglesColSize);
}

int solution_c(std::vector<std::vector<int>> rectangles) {
  std::vector<int*> rectanglesDatas(rectangles.size());
  std::vector<int> rectanglesSizes(rectangles.size());
  for (std::size_t i{0}; i < rectangles.size(); ++i) {
    rectanglesDatas[i] = rectangles[i].data();
    rectanglesSizes[i] = rectangles[i].size();
  }

  return countGoodRectangles(
      rectanglesDatas.data(), rectangles.size(), rectanglesSizes.data());
}
