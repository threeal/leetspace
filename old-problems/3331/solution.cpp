#include <cstdint>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> findSubtreeSizes(std::vector<int>& parent, std::string s) {
    std::vector<std::vector<std::size_t>> children(parent.size());
    for (std::size_t i{1}; i < parent.size(); ++i) {
      children[parent[i]].push_back(i);
    }

    std::vector<int> res(parent.size());
    explore(s, children, res, 0, 0);
    res[0] = parent.size();

    return res;
  }

 private:
  static std::vector<int> explore(
      const std::string& s,
      const std::vector<std::vector<std::size_t>>& children,
      std::vector<int>& res,
      std::uint32_t flag,
      std::size_t node) {
    const int c{s[node] - 'a'};
    const std::uint32_t childFlag{flag | (1 << c)};
    std::vector<int> counts(26, 0);

    for (const std::size_t child : children[node]) {
      const std::vector<int> childCounts{
          explore(s, children, res, childFlag, child)};

      for (int i{0}; i < 26; ++i) {
        counts[i] += childCounts[i];
      }
    }

    int count{1};
    for (int i{0}; i < 26; ++i) {
      if ((flag & (1 << i)) == 0) count += counts[i];
    }
    res[node] = count;

    ++counts[c];
    return counts;
  }
};
