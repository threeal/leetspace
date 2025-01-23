double findMedianSortedArrays(
    int* nums1, int nums1Size, int* nums2, int nums2Size) {
  return nums1Size > nums2Size ? nums1[nums1Size - 1] : nums2[nums2Size - 1];
}
