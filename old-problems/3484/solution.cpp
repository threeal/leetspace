#include <string>

class Spreadsheet {
 public:
  Spreadsheet(int rows) {
    (void)rows;
  }

  void setCell(std::string cell, int value) {
    (void)cell;
    (void)value;
  }

  void resetCell(std::string cell) {
    (void)cell;
  }

  int getValue(std::string formula) {
    return formula.size();
  }
};
