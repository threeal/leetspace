#include <string>
#include <vector>

struct Trie {
  std::size_t idx;
  Trie* children[26];

  Trie(std::size_t idx) : idx{idx}, children{nullptr} {}

  ~Trie() {
    for (int i{0}; i < 26; ++i) {
      if (children[i] != nullptr) delete children[i];
    }
  }
};

class Solution {
 public:
  std::vector<int> stringIndices(
      std::vector<std::string>& wordsContainer,
      std::vector<std::string>& wordsQuery) {
    Trie root(0);
    for (std::size_t i{0}; i < wordsContainer.size(); ++i) {
      if (wordsContainer[i].size() < wordsContainer[root.idx].size()) {
        root.idx = i;
      }

      Trie* trie{&root};
      for (std::size_t j{wordsContainer[i].size()}; j > 0;) {
        --j;
        int k{wordsContainer[i][j] - 'a'};
        if (trie->children[k] == nullptr) {
          trie->children[k] = new Trie(i);
        } else {
          const std::size_t idx{trie->children[k]->idx};
          if (wordsContainer[i].size() < wordsContainer[idx].size()) {
            trie->children[k]->idx = i;
          }
        }
        trie = trie->children[k];
      }
    }

    std::vector<int> output(wordsQuery.size());
    for (std::size_t i{0}; i < wordsQuery.size(); ++i) {
      Trie* trie{&root};
      for (std::size_t j{wordsQuery[i].size()}; j > 0;) {
        --j;
        int k{wordsQuery[i][j] - 'a'};
        if (trie->children[k] == nullptr) break;
        trie = trie->children[k];
      }
      output[i] = trie->idx;
    }

    return output;
  }
};
