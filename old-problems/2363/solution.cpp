#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> mergeSimilarItems(
      std::vector<std::vector<int>>& items1,
      std::vector<std::vector<int>>& items2) {
    std::sort(items1.begin(), items1.end());
    std::sort(items2.begin(), items2.end());

    std::vector<std::vector<int>> output{};

    std::size_t i1{0}, i2{0};
    while (i1 < items1.size() && i2 < items2.size()) {
      if (items1[i1][0] == items2[i2][0]) {
        output.push_back({items1[i1][0], items1[i1][1] + items2[i2][1]});
        ++i1;
        ++i2;
      } else if (items1[i1][0] < items2[i2][0]) {
        output.push_back(items1[i1]);
        ++i1;
      } else {
        output.push_back(items2[i2]);
        ++i2;
      }
    }

    while (i1 < items1.size()) {
      output.push_back(items1[i1]);
      ++i1;
    }

    while (i2 < items2.size()) {
      output.push_back(items2[i2]);
      ++i2;
    }

    return output;
  }
};
