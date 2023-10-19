int countRecursively(int parent, int* leftChild, int* rightChild);

bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize) {
  // Initialize an array to check for duplicate values in child arrays.
  bool* existingChild = malloc(n * sizeof(bool));
  for (int i = 0; i < n; ++i) {
    existingChild[i] = false;
  }

  // Count how many children appear in the array.
  int childCount = 0;

  // Check for duplicate values in child arrays.
  // If there is a duplicate value, it means one of the nodes has more than one parent, which is not allowed in a binary tree.
  for (int i = 0; i < leftChildSize; ++i) {
    if (leftChild[i] < 0) continue;
    if (existingChild[leftChild[i]]) return false;
    existingChild[leftChild[i]] = true;
    ++childCount;
  }
  for (int i = 0; i < rightChildSize; ++i) {
    if (rightChild[i] < 0) continue;
    if (existingChild[rightChild[i]]) return false;
    existingChild[rightChild[i]] = true;
    ++childCount;
  }

  // There should be n - 1 children that appear in the array.
  // One of the children that is not in the array is considered as the root.
  if (childCount != n - 1) return false;

  // Find the root.
  int root = 0;
  for (; root < n; ++root) {
    if (!existingChild[root]) break;
  }

  // Recursively count the total nodes from the root.
  int count = countRecursively(root, leftChild, rightChild);
  return count == n;
}

int countRecursively(int parent, int* leftChild, int* rightChild) {
  int count = 1;
  if (leftChild[parent] >= 0) {
    count += countRecursively(leftChild[parent], leftChild, rightChild);
  }
  if (rightChild[parent] >= 0) {
    count += countRecursively(rightChild[parent], leftChild, rightChild);
  }
  return count;
}
