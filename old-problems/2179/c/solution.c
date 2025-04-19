#include <stdlib.h>

static void updateTree(int* tree, int treeSize, int i, int delta);
static int queryTree(int* tree, int i);

long long goodTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int* indices2 = malloc(nums2Size * sizeof(int));
  for (int i2 = 0; i2 < nums2Size; ++i2) indices2[nums2[i2]] = i2;

  const int leftCountsSize = nums1Size + 1;
  int* leftCounts = malloc(leftCountsSize * sizeof(int));
  for (int i = 0; i < leftCountsSize; ++i) leftCounts[i] = 0;

  long long counts = 0;
  for (int i1 = 0; i1 < nums1Size; ++i1) {
    const int i2 = indices2[nums1[i1]];

    const long long leftCount = queryTree(leftCounts, i2);
    updateTree(leftCounts, leftCountsSize, i2, 1);

    const long long rightCount = nums2Size - 1 - i2 - (i1 - leftCount);
    counts += leftCount * rightCount;
  }

  return counts;
}

static void updateTree(int* tree, int treeSize, int i, int delta) {
  ++i;
  while (i < treeSize) {
    tree[i] += delta;
    i += i & -i;
  }
}

static int queryTree(int* tree, int i) {
  ++i;
  int sum = 0;
  while (i > 0) {
    sum += tree[i];
    i -= i & -i;
  }
  return sum;
}
