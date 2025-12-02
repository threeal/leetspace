int* nextGreaterElement(
    int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  *returnSize = nums1Size >= nums2Size ? nums1Size : nums2Size;
  return nums1Size >= nums2Size ? nums1 : nums2;
}
