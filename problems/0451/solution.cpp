#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::string frequencySort(std::string s) {
    std::unordered_map<char, int> counts{};
    for (const auto c : s) {
      ++counts[c];
    }

    std::vector<char> order{};
    order.reserve(counts.size());
    for (const auto [c, count] : counts) {
      order.push_back(c);
    }

    std::sort(order.begin(), order.end(), [&](char a, char b) {
      return counts[a] > counts[b];
    });

    auto ptr = s.data();
    for (const auto c : order) {
      std::memset(ptr, c, counts[c]);
      ptr += counts[c];
    }

    return s;
  }
};
