#include <vector>

class Solution {
 public:
  std::vector<int> minOperations(std::string boxes) {
    std::vector<int> operations(boxes.size(), 0);

    int n{0}, operation{0};
    for (std::size_t i{0}; i < boxes.size(); ++i) {
      operation += n;
      operations[i] += operation;
      if (boxes[i] == '1') ++n;
    }

    n = 0;
    operation = 0;

    for (std::size_t i{boxes.size()}; i > 0; --i) {
      operation += n;
      operations[i - 1] += operation;
      if (boxes[i - 1] == '1') ++n;
    }

    return operations;
  }
};
