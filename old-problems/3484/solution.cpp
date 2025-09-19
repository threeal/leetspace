#include <string>
#include <vector>

class Spreadsheet {
 private:
  std::vector<std::vector<int>> table;

 public:
  Spreadsheet(int rows) : table(26, std::vector<int>(rows, 0)) {}

  void setCell(std::string cell, int value) {
    const int col{cell[0] - 'A'};

    int row{cell[1] - '0'};
    for (std::size_t i{2}; i < cell.size(); ++i) {
      row = row * 10 + cell[i] - '0';
    }

    table[col][row - 1] = value;
  }

  void resetCell(std::string cell) {
    const int col{cell[0] - 'A'};

    int row{cell[1] - '0'};
    for (std::size_t i{2}; i < cell.size(); ++i) {
      row = row * 10 + cell[i] - '0';
    }

    table[col][row - 1] = 0;
  }

  int getValue(std::string formula) {
    std::size_t i{1};

    int a{};
    if (formula[i] >= 'A') {
      const int col{formula[i] - 'A'};

      int row{formula[++i] - '0'};
      while (formula[++i] != '+') {
        row = row * 10 + formula[i] - '0';
      }

      a = table[col][row - 1];
    } else {
      a = formula[i] - '0';
      while (formula[++i] != '+') {
        a = a * 10 + formula[i] - '0';
      }
    }

    int b{};
    if (formula[++i] >= 'A') {
      const int col{formula[i] - 'A'};

      int row{formula[++i] - '0'};
      while (formula[++i] != 0) {
        row = row * 10 + formula[i] - '0';
      }

      b = table[col][row - 1];
    } else {
      b = formula[i] - '0';
      while (formula[++i] != 0) {
        b = b * 10 + formula[i] - '0';
      }
    }

    return a + b;
  }
};
