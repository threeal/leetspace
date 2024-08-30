#include <algorithm>
#include <vector>

class Solution {
 public:
  int chalkReplacer(std::vector<int>& chalk, int k) {
    if (k < chalk[0]) return 0;
    for (std::size_t i{1}; i < chalk.size(); ++i) {
      if (k - chalk[i - 1] < chalk[i]) return i;
      chalk[i] += chalk[i - 1];
    }

    const auto it = std::upper_bound(
        chalk.begin(), chalk.end(), k % chalk.back());

    return std::distance(chalk.begin(), it);
  }
};
