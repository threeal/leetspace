#include <unordered_map>
#include <vector>

struct Prev {
  std::size_t pos;
  long long count;
  long long sum;
};

class Solution {
 public:
  std::vector<long long> distance(std::vector<int>& nums) {
    std::vector<long long> output(nums.size(), 0);

    std::unordered_map<int, Prev> prevs{};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      auto it = prevs.find(nums[i]);
      if (it != prevs.end()) {
        it->second.sum += (i - it->second.pos) * it->second.count;
        output[i] += it->second.sum;

        it->second.pos = i;
        ++it->second.count;
      } else {
        prevs.emplace(nums[i], Prev{.pos = i, .count = 1, .sum = 0});
      }
    }

    prevs.clear();
    for (std::size_t i{nums.size()}; i > 0;) {
      --i;
      auto it = prevs.find(nums[i]);
      if (it != prevs.end()) {
        it->second.sum += (it->second.pos - i) * it->second.count;
        output[i] += it->second.sum;

        it->second.pos = i;
        ++it->second.count;
      } else {
        prevs.emplace(nums[i], Prev{.pos = i, .count = 1, .sum = 0});
      }
    }

    return output;
  }
};
