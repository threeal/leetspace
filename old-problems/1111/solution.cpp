#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> maxDepthAfterSplit(std::string seq) {
    int depth{0};
    std::vector<int> output(seq.size());
    for (std::size_t i{0}; i < seq.size(); ++i) {
      output[i] = seq[i] == '(' ? ++depth % 2 : depth-- % 2;
    }
    return output;
  }
};
