#include <vector>

extern "C" {
bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize);
}

int solution_c(int n, std::vector<int> leftChild, std::vector<int> rightChild) {
  return validateBinaryTreeNodes(n, leftChild.data(), leftChild.size(), rightChild.data(), rightChild.size());
}
