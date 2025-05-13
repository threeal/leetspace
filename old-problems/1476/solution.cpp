#include <vector>

class SubrectangleQueries {
 private:
  std::vector<std::vector<int>> rectangle;

 public:
  SubrectangleQueries(std::vector<std::vector<int>>& rectangle)
      : rectangle{rectangle} {}

  void updateSubrectangle(
      int row1, int col1, int row2, int col2, int newValue) {
    for (int row{row1}; row <= row2; ++row) {
      for (int col{col1}; col <= col2; ++col) {
        rectangle[row][col] = newValue;
      }
    }
  }

  int getValue(int row, int col) {
    return rectangle[row][col];
  }
};
