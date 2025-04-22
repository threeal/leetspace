#include <vector>

extern "C" {
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize);
}

int solution_c(int m, int n, std::vector<std::vector<int>> ops) {
  std::vector<int*> opsDatas(ops.size());
  std::vector<int> opsSizes(ops.size());
  for (std::size_t i{0}; i < ops.size(); ++i) {
    opsDatas[i] = ops[i].data();
    opsSizes[i] = ops[i].size();
  }

  return maxCount(m, n, opsDatas.data(), ops.size(), opsSizes.data());
}
