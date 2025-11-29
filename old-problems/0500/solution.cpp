#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> findWords(std::vector<std::string>& words) {
    std::size_t n{0};
    for (const std::string& word : words) {
      const int row{rowOf(word[0])};

      std::size_t i{1};
      while (i < word.size()) {
        if (rowOf(word[i]) != row) break;
        ++i;
      }

      if (i == word.size()) {
        words[n++] = word;
      }
    }

    words.resize(n);
    return words;
  }

 private:
  static char rowOf(char c) {
    switch (c < 'a' ? c + 'a' - 'A' : c) {
      case 'q':
      case 'w':
      case 'e':
      case 'r':
      case 't':
      case 'y':
      case 'u':
      case 'i':
      case 'o':
      case 'p':
        return 1;

      case 'a':
      case 's':
      case 'd':
      case 'f':
      case 'g':
      case 'h':
      case 'j':
      case 'k':
      case 'l':
        return 2;

      case 'z':
      case 'x':
      case 'c':
      case 'v':
      case 'b':
      case 'n':
      case 'm':
        return 3;
    }

    return 0;
  }
};
