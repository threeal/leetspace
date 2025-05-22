#include <cstring>
#include <string>
#include <string_view>

class Solution {
 public:
  std::string sortSentence(std::string s) {
    std::string_view sentence(s), words[9]{};

    std::size_t l{0}, wordsSize{0};
    for (std::size_t r{0}; r < sentence.size(); ++r) {
      if (sentence[r] == ' ') {
        words[sentence[r - 1] - '1'] = sentence.substr(l, r - l - 1);
        l = r + 1;
        ++wordsSize;
      }
    }

    words[sentence.back() - '1'] = sentence.substr(l, sentence.size() - l - 1);
    ++wordsSize;

    std::string output(sentence.size() - wordsSize, ' ');
    for (std::size_t l{0}, i{0}; i < wordsSize; ++i) {
      std::memcpy(
          output.data() + l, words[i].data(), words[i].size() * sizeof(char));
      l += words[i].size() + 1;
    }

    return output;
  }
};
