#include <vector>

class Solution {
 public:
  std::vector<int> decode(std::vector<int>& encoded, int first) {
    std::vector<int> output(encoded.size() + 1);
    output[0] = first;
    for (std::size_t i{0}; i < encoded.size(); ++i) {
      output[i + 1] = output[i] ^ encoded[i];
    }
    return output;
  }
};
