#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

struct Path {
  std::string_view root;
  std::string_view filename;
};

class Solution {
 public:
  std::vector<std::vector<std::string>> findDuplicate(
      std::vector<std::string>& paths) {
    std::unordered_map<std::string_view, std::vector<Path>> contentPaths{};
    for (std::size_t i{0}; i < paths.size(); ++i) {
      const std::string_view path(paths[i]);

      std::size_t r{0};
      while (path[r] != ' ') ++r;

      const std::string_view root{path.substr(0, r)};

      while (r < path.size()) {
        std::size_t l{++r};
        while (path[r] != '(') ++r;

        const std::string_view filename{path.substr(l, r - l)};

        l = ++r;
        while (path[r] != ')') ++r;

        const std::string_view content{path.substr(l, r - l)};
        contentPaths[content].push_back({.root = root, .filename = filename});

        ++r;
      }
    }

    std::vector<std::vector<std::string>> output{};
    for (const auto& [content, paths] : contentPaths) {
      if (paths.size() > 1) {
        output.push_back(std::vector<std::string>(paths.size()));
        for (std::size_t i{0}; i < paths.size(); ++i) {
          const std::string_view& root{paths[i].root};
          const std::string_view& filename{paths[i].filename};

          std::string& str{output.back()[i]};
          str.resize(root.size() + filename.size() + 1);

          std::memcpy(str.data(), root.data(), root.size() * sizeof(char));
          str[root.size()] = '/';
          std::memcpy(
              str.data() + root.size() + 1, filename.data(),
              filename.size() * sizeof(char));
        }
      }
    }

    return output;
  }
};
