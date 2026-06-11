#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::string evaluate(
      std::string s, std::vector<std::vector<std::string>>& knowledge) {
    std::unordered_map<std::string_view, std::string_view> knowledgeMap{};
    for (const auto& pair : knowledge) {
      knowledgeMap.emplace(pair[0], pair[1]);
    }

    std::string out{};
    std::string_view sv{s};
    for (std::size_t r{0}; r < s.size(); ++r) {
      if (sv[r] == '(') {
        const std::size_t l{++r};
        while (sv[r] != ')') ++r;

        const auto it = knowledgeMap.find(sv.substr(l, r - l));
        if (it != knowledgeMap.end()) {
          out += it->second;
        } else {
          out += '?';
        }
      } else {
        out += sv[r];
      }
    }

    return out;
  }
};
