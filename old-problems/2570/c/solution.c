int** mergeArrays(
    int** nums1, int nums1Size, int* nums1ColSize,
    int** nums2, int nums2Size, int* nums2ColSize,
    int* returnSize, int** returnColumnSizes) {
  *returnSize = nums1Size > nums2Size ? nums1Size : nums2Size;
  *returnColumnSizes = nums1Size > nums2Size ? nums1ColSize : nums2ColSize;
  return nums1Size > nums2Size ? nums1 : nums2;
}
