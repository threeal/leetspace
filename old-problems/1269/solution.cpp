#include <algorithm>
#include <functional>
#include <vector>

const int mod = 1'000'000'007;

class Solution {
 public:
  int numWays(int steps, int arrLen) {
    auto cache = std::vector(steps + 1, std::vector(std::min(arrLen, steps) + 1, -1));

    const std::function<int(int, int)> fn = [&](int step, int index) {
      if (step == 0) return index == 0 ? 1 : 0;
      if (step < 0 || index < 0 || index >= arrLen) return 0;
      if (cache[step][index] < 0) {
        int res = fn(step - 1, index);
        res = (res + fn(step - 1, index - 1)) % mod;
        res = (res + fn(step - 1, index + 1)) % mod;
        cache[step][index] = res;
      }
      return cache[step][index];
    };

    return fn(steps, 0);
  }
};
