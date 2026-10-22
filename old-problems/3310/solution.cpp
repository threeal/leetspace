#include <vector>

class Solution {
 public:
  std::vector<int> remainingMethods(
      int n, int k, std::vector<std::vector<int>>& invocations) {
    std::vector<std::vector<int>> methodInvocations(n);
    for (const auto& invocation : invocations) {
      methodInvocations[invocation[i][0]].push_back(invocation[i][1]);
    }

    std::vector<bool> isMethodSuspicious(n);
    markSuspiciousMethods(methodInvocations, isMethodSuspicious, k);

    (void)n;
    (void)k;
    (void)invocations;
    return {};
  }

 private:
  void markSuspiciousMethods(
      const std::vector<std::vector<int>>& methodInvocations,
      std::vector<bool>& isMethodSuspicious,
      int method) {
    isMethodSuspicious[method] = true;
    for (const auto invokedMethod : methodInvocations[method]) {
      if (!isMethodSuspicious[invokedMethod]) {
        markSuspiciousMethods(
            methodInvocations, isMethodSuspicious, invokedMethod);
      }
    }
  }
};
