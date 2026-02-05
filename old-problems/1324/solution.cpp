#include <string>
#include <string_view>
#include <vector>

class Solution {
 public:
  std::vector<std::string> printVertically(std::string s) {
    std::string_view sv(s);
    std::vector<std::string_view> svs{};
    std::size_t l{0};
    for (std::size_t r{1}; r < sv.size(); ++r) {
      if (sv[r] == ' ') {
        svs.push_back(sv.substr(l, r - l));
        l = r + 1;
      }
    }
    svs.push_back(sv.substr(l));

    std::vector<std::string> out{};
    for (std::size_t i{0}; i < svs.size(); ++i) {
      if (out.size() < svs[i].size()) out.resize(svs[i].size());
      for (std::size_t j{0}; j < svs[i].size(); ++j) {
        if (out[j].size() <= i) out[j].resize(i + 1, ' ');
        out[j][i] = svs[i][j];
      }
    }

    return out;
  }
};
