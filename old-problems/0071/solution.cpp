#include <string>
#include <string_view>
#include <vector>

class Solution {
 public:
  std::string simplifyPath(std::string path) {
    const std::string_view view(path);
    std::vector<std::string_view> dirs{};

    for (std::size_t l{1}; l < view.size(); ++l) {
      if (view[l] != '/') {
        std::size_t r{l + 1};
        while (r < view.size() && view[r] != '/') ++r;

        const std::string_view dir{view.substr(l, r - l)};
        if (dir == "..") {
          if (!dirs.empty()) dirs.pop_back();
        } else if (dir != ".") {
          dirs.push_back(dir);
        }

        l = r;
      }
    }

    if (dirs.empty()) return "/";

    std::size_t n{0};
    for (const auto& dir : dirs) {
      path[n++] = '/';
      for (const auto c : dir) {
        path[n++] = c;
      }
    }
    path.resize(n);

    return path;
  }
};
