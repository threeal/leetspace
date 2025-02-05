#include <stack>
#include <tuple>
#include <vector>

class Solution {
 public:
  int sumSubarrayMins(std::vector<int>& arr) {
    std::stack<std::tuple<std::size_t, int>> stack{};

    for (std::size_t i{0}; i < arr.size(); ++i) {
      while (!stack.empty() && std::get<1>(stack.top()) >= arr[i]) stack.pop();
      if (stack.empty()) {
        stack.push({i, arr[i]});
        arr[i] = (static_cast<long long>(arr[i]) * (i + 1)) % 1000000007;
      } else {
        std::size_t j{std::get<0>(stack.top())};
        stack.push({i, arr[i]});
        arr[i] = (arr[j] + static_cast<long long>(arr[i]) * (i - j)) % 1000000007;
      }
    }

    int sum{0};
    for (const auto val : arr) sum = (sum + val) % 1000000007;
    return sum;
  }
};
