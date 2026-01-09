#include <string>

class Trie {
 public:
  Trie() {}

  void insert(std::string word) {
    (void)word;
  }

  bool search(std::string word) {
    return word.empty();
  }

  bool startsWith(std::string prefix) {
    return prefix.empty();
  }
};
