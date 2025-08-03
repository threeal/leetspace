#include <algorithm>
#include <string>
#include <string_view>

class Solution {
 public:
  std::string answerString(std::string word, int numFriends) {
    if (numFriends == 1) return word;
    std::string_view view(word);
    std::size_t maxSize{view.size() - numFriends + 1};
    std::string_view answer{view.substr(0, maxSize)};
    for (std::size_t i{1}; i < view.size(); ++i) {
      std::string_view subview{view.substr(i, std::min(view.size() - i, maxSize))};
      if (subview > answer) answer = subview;
    }
    return std::string(answer);
  }
};
