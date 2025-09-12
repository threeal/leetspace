#include <unordered_set>
#include <vector>

class Solution {
 public:
  int subarrayBitwiseORs(std::vector<int>& arr) {
    std::unordered_set<int> all{}, prevs{}, curr{};
    prevs.insert(0);
    for (const int num : arr) {
      curr.clear();
      curr.insert(num);
      all.insert(num);
      for (const int prev : prevs) {
        curr.insert(prev | num);
        all.insert(prev | num);
      }
      std::swap(curr, prevs);
    }
    return all.size();
  }
};
