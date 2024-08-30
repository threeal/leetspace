#include <vector>

extern "C" {
int chalkReplacer(int* chalk, int chalkSize, int k);
}

int solution_c(std::vector<int> chalk, int k) {
  return chalkReplacer(chalk.data(), chalk.size(), k);
}
