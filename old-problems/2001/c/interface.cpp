#include <vector>

extern "C" {
long long interchangeableRectangles(
    int** rectangles, int rectanglesSize, int* rectanglesColSize);
}

long long solution_c(std::vector<std::vector<int>> rectangles) {
  std::vector<int*> rectanglesDatas(rectangles.size());
  std::vector<int> rectanglesSizes(rectangles.size());
  for (std::size_t i{0}; i < rectangles.size(); ++i) {
    rectanglesDatas[i] = rectangles[i].data();
    rectanglesSizes[i] = rectangles[i].size();
  }

  return interchangeableRectangles(
      rectanglesDatas.data(), rectangles.size(), rectanglesSizes.data());
}
