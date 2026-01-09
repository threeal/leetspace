#include <string>

class Solution {
 public:
  std::string toGoatLatin(std::string sentence) {
    std::size_t words{1};
    for (char c : sentence) {
      if (c == ' ') ++words;
    }

    std::string output(
        sentence.size() + words * 2 + words * (words + 1) / 2, ' ');

    std::size_t l{0}, i{0}, as{2};
    for (std::size_t r{1}; r <= sentence.size(); ++r) {
      if (r == sentence.size() || sentence[r] == ' ') {
        switch (sentence[l]) {
          case 'a':
          case 'e':
          case 'i':
          case 'o':
          case 'u':
          case 'A':
          case 'E':
          case 'I':
          case 'O':
          case 'U':
            for (std::size_t j{l}; j < r; ++j, ++i) {
              output[i] = sentence[j];
            }
            break;

          default:
            for (std::size_t j{l + 1}; j < r; ++j, ++i) {
              output[i] = sentence[j];
            }
            output[i++] = sentence[l];
        }

        output[i++] = 'm';
        for (std::size_t a{0}; a < as; ++a) {
          output[i++] = 'a';
        }

        l = r + 1;
        ++i;
        ++as;
      }
    }

    return output;
  }
};
