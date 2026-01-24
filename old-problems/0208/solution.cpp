#include <string>

class Trie {
 private:
  bool hasEnd;
  Trie* children[26];

 public:
  Trie() : hasEnd{false}, children{} {
    for (int i{0}; i < 26; ++i) children[i] = nullptr;
  }

  ~Trie() {
    for (int i{0}; i < 26; ++i) {
      if (children[i] != nullptr) delete children[i];
    }
  }

  void insert(std::string word) {
    insert(word.data());
  }

  void insert(char* c) {
    if (*c == 0) {
      hasEnd = true;
    } else {
      if (children[*c - 'a'] == nullptr) {
        children[*c - 'a'] = new Trie();
      }
      children[*c - 'a']->insert(c + 1);
    }
  }

  bool search(std::string word) {
    return search(word.data());
  }

  bool search(char* c) {
    if (*c == 0) return hasEnd;
    if (children[*c - 'a'] == nullptr) return false;
    return children[*c - 'a']->search(c + 1);
  }

  bool startsWith(std::string prefix) {
    return startsWith(prefix.data());
  }

  bool startsWith(char* c) {
    if (*c == 0) return true;
    if (children[*c - 'a'] == nullptr) return false;
    return children[*c - 'a']->startsWith(c + 1);
  }
};
