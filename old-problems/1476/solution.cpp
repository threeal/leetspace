#include <vector>

class SubrectangleQueries {
 public:
  SubrectangleQueries(std::vector<std::vector<int>>& rectangle) {
    (void)rectangle;
  }

  void updateSubrectangle(
      int row1, int col1, int row2, int col2, int newValue) {
    (void)row1;
    (void)col1;
    (void)row2;
    (void)col2;
    (void)newValue;
  }

  int getValue(int row, int col) {
    return row + col;
  }
};
