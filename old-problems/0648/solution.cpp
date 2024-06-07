#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence) {
    std::sort(dictionary.begin(), dictionary.end());

    std::string output{""};
    output.reserve(sentence.size());

    std::string_view view(sentence);
    std::size_t left{0};
    std::size_t right{view.find(' ', left)};

    while (right != std::string::npos) {
      std::string_view subview{view.substr(left, right - left)};
      const auto it = std::find_if(dictionary.begin(), dictionary.end(), [&](auto str) {
        return subview.starts_with(str);
      });
      if (it == dictionary.end()) {
        output += subview;
      } else {
        output += *it;
      }
      output += " ";

      left = right + 1;
      right = view.find(' ', left);
    }

    std::string_view subview{view.substr(left)};
    const auto it = std::find_if(dictionary.begin(), dictionary.end(), [&](auto str) {
      return subview.starts_with(str);
    });
    if (it == dictionary.end()) {
      output += subview;
    } else {
      output += *it;
    }

    return output;
  }
};
