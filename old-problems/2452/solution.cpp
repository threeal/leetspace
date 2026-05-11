#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> twoEditWords(
      std::vector<std::string>& queries,
      std::vector<std::string>& dictionary) {
    std::size_t n{0};
    for (const auto& query : queries) {
      for (const auto& dict : dictionary) {
        int diff{0};
        for (std::size_t i{0}; i < query.size(); ++i) {
          if (query[i] != dict[i]) {
            if (++diff > 2) break;
          }
        }

        if (diff <= 2) {
          queries[n++] = query;
          break;
        }
      }
    }

    queries.resize(n);
    return queries;
  }
};
