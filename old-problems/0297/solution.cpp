#include <queue>
#include <string>

class Codec {
 public:
  std::string serialize(TreeNode* root) {
    if (root == nullptr) return "";
    std::string data{};

    std::queue<TreeNode*> nodes{};
    nodes.push(root);

    while (!nodes.empty()) {
      if (nodes.front() == nullptr) {
        data += 127;
        data += 127;
      } else {
        data += nodes.front()->val / 125;
        data += nodes.front()->val % 125;

        nodes.push(nodes.front()->left);
        nodes.push(nodes.front()->right);
      }
      nodes.pop();
    }

    return data;
  }

  TreeNode* deserialize(std::string data) {
    if (data.empty()) return nullptr;
    TreeNode* root{
        new TreeNode(static_cast<int>(data[0]) * 125 + data[1])};

    std::queue<TreeNode**> nodes{};
    nodes.push(&(root->left));
    nodes.push(&(root->right));

    for (std::size_t i{2}; i < data.size(); i += 2) {
      if (data[i] != 127 && data[i + 1] != 127) {
        const int val{static_cast<int>(data[i]) * 125 + data[i + 1]};
        TreeNode* node{new TreeNode(val)};
        *nodes.front() = node;
        nodes.push(&(node->left));
        nodes.push(&(node->right));
      }
      nodes.pop();
    }

    return root;
  }
};
