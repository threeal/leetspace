#include <vector>

class Solution {
 public:
  std::vector<int> preorder(Node* root) {
    return {root->val};
  }
};
