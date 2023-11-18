// The solution is straightforward. Despite collisions between two ants, both ants eventually end up in the same starting place.
// Conceptually, we can ignore the collisions, and ant movement is as if they pass through each other.
// Hence, the time required is the same as the position of the leftmost ant moving right or the rightmost ant moving left.

int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize) {
  // Calculate the index of the rightmost ant moving left.
  int leftMax = 0;
  for (int i = 0; i < leftSize; ++i) {
    if (left[i] > leftMax) leftMax = left[i];
  }

  // Calculate the index of the leftmost ant moving right.
  int rightMin = 10000;
  for (int i = 0; i < rightSize; ++i) {
    if (right[i] < rightMin) rightMin = right[i];
  }

  if (leftSize == 0) return n - rightMin;
  if (rightSize == 0) return leftMax;
  return (leftMax > n - rightMin) ? leftMax : n - rightMin;
}
