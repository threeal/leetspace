#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freqs{};
    for (const int num : nums) ++freqs[num];

    std::priority_queue<std::tuple<int, int>> queue{};
    for (const auto& [num, freq] : freqs) {
      queue.push({freq, num});
    }

    std::vector<int> output(k);
    for (int i{0}; i < k; ++i) {
      output[i] = std::get<1>(queue.top());
      queue.pop();
    }

    return output;
  }
};
