#include <string>
#include <vector>

class Solution {
 private:
  struct Node {
    int count{1};
    Node* nexts[26] = {nullptr};

    ~Node() {
      for (int i{0}; i < 26; ++i) {
        if (nexts[i] != nullptr) delete nexts[i];
      }
    }
  };

 public:
  std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
    Node root;

    for (const auto& word : words) {
      Node* node{&root};
      for (const char* c{word.data()}; *c != 0; ++c) {
        Node** next{node->nexts + *c - 'a'};
        if (*next == nullptr) {
          *next = new Node();
        } else {
          ++((*next)->count);
        }
        node = *next;
      }
    }

    std::vector<int> output{};
    output.reserve(words.size());

    for (const auto& word : words) {
      int total{0};
      Node* node{&root};
      for (const char* c{word.data()}; *c != 0; ++c) {
        Node** next{node->nexts + *c - 'a'};
        total += (*next)->count;
        node = *next;
      }
      output.push_back(total);
    }

    return output;
  }
};
