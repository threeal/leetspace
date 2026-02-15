#include <vector>

extern "C" {
double separateSquares(int** squares, int squaresSize, int* squaresColSize);
}

double solution_c(std::vector<std::vector<int>> squares) {
  std::vector<int*> squaresDatas(squares.size());
  std::vector<int> squaresSizes(squares.size());
  for (std::size_t i{0}; i < squares.size(); ++i) {
    squaresDatas[i] = squares[i].data();
    squaresSizes[i] = squares[i].size();
  }

  return separateSquares(
      squaresDatas.data(), squares.size(), squaresSizes.data());
}
