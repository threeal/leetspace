#include <cstring>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> fullJustify(
      std::vector<std::string>& words, int maxWidth) {
    std::string line(maxWidth, ' ');
    std::vector<std::string> output{};

    std::size_t l{0}, width{words[0].size()};
    for (std::size_t r{1}; r < words.size(); ++r) {
      if (width + words[r].size() + 1 <= line.size()) {
        width += words[r].size() + 1;
        continue;
      }

      if (r - l > 1) {
        std::memcpy(
            line.data(), words[l].data(), words[l].size() * sizeof(char));

        std::size_t pos{words[l].size()};
        std::size_t spaceWidth{1 + (line.size() - width) / (r - l - 1)};
        std::size_t extraSpaces{(line.size() - width) % (r - l - 1)};

        for (++l; l < r; ++l) {
          if (extraSpaces > 0) {
            std::memset(
                line.data() + pos, ' ', (spaceWidth + 1) * sizeof(char));

            pos += spaceWidth + 1;
            --extraSpaces;
          } else {
            std::memset(line.data() + pos, ' ', spaceWidth * sizeof(char));
            pos += spaceWidth;
          }

          std::memcpy(
              line.data() + pos, words[l].data(),
              words[l].size() * sizeof(char));

          pos += words[l].size();
        }
      } else {
        std::memcpy(
            line.data(), words[l].data(), words[l].size() * sizeof(char));

        std::memset(
            line.data() + words[l].size(), ' ',
            (line.size() - words[l].size()) * sizeof(char));

        ++l;
      }

      output.push_back(line);
      width = words[r].size();
    }

    std::memcpy(line.data(), words[l].data(), words[l].size() * sizeof(char));
    std::size_t pos{words[l].size()};

    for (++l; l < words.size(); ++l) {
      line[pos++] = ' ';
      std::memcpy(
          line.data() + pos, words[l].data(), words[l].size() * sizeof(char));

      pos += words[l].size();
    }

    std::memset(line.data() + pos, ' ', (line.size() - pos) * sizeof(char));
    output.push_back(line);

    return output;
  }
};
