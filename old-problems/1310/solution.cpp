#include <vector>

class Solution {
 public:
  std::vector<int> xorQueries(
      std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
    for (std::size_t i{1}; i < arr.size(); ++i) arr[i] ^= arr[i - 1];

    std::vector<int> outputs{};
    outputs.reserve(queries.size());
    for (const auto& query : queries) {
      if (query[0] > 0) {
        outputs.push_back(arr[query[1]] ^ arr[query[0] - 1]);
      } else {
        outputs.push_back(arr[query[1]]);
      }
    }
    return outputs;
  }
};
