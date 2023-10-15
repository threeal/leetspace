class Solution {
 public:
  int numWays(int steps, int arrLen) {
    const function<int(int, int)> fn = [&](int step, int index) {
      if (step == 0) return index == 0 ? 1 : 0;
      if (step < 0 || index < 0 || index >= arrLen) return 0;
      return fn(step - 1, index) + fn(step - 1, index - 1) + fn(step - 1, index + 1);
    };

    return fn(steps, 0);
  }
};
