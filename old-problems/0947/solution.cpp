#include <unordered_map>
#include <vector>

class Solution {
 public:
  int removeStones(std::vector<std::vector<int>>& stones) {
    int removed{};

    std::unordered_map<int, int> hParents{};
    std::unordered_map<int, int> vParents{};

    for (int i = stones.size() - 1; i >= 0; --i) {
      const auto hIt = hParents.find(stones[i][0]);
      const auto vIt = vParents.find(stones[i][1]);

      if (hIt == hParents.end()) {
        if (vIt == vParents.end()) {
          hParents.emplace(stones[i][0], i);
          vParents.emplace(stones[i][1], i);
        } else {
          hParents.emplace(stones[i][0], vIt->second);
          ++removed;
        }
      } else {
        if (vIt == vParents.end()) {
          vParents.emplace(stones[i][1], hIt->second);
          ++removed;
        } else {
          int hRoot = findHRoot(hParents, stones, hIt->second);
          int vRoot = findHRoot(hParents, stones, vIt->second);
          if (hRoot != vRoot) {
            ++removed;
            if (hRoot > vRoot) {
              hParents[stones[vRoot][0]] = hRoot;
              vParents[stones[vRoot][1]] = hRoot;
            } else {
              hParents[stones[hRoot][0]] = vRoot;
              vParents[stones[hRoot][1]] = vRoot;
            }
          }
          ++removed;
        }
      }
    }

    return removed;
  }

 private:
  static int findHRoot(
      std::unordered_map<int, int>& hParents,
      const std::vector<std::vector<int>>& stones, int i) {
    auto& parent = hParents[stones[i][0]];
    if (parent != i) parent = findHRoot(hParents, stones, parent);
    return parent;
  }
};
