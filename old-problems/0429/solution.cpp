#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(Node* root) {
    return {{root->val}};
  }
};
