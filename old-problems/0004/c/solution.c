double findMedianSortedArrays(
    int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int target = (nums1Size + nums2Size) / 2 + 1;
  if ((nums1Size + nums2Size) % 2 == 0) {
    int i1 = 0, i2 = 0, median1, median2;
    while (target > 0) {
      if (i1 == nums1Size) {
        median2 = (target == 1) ? median1 : nums2[i2 + target - 2];
        median1 = nums2[i2 + target - 1];
        break;
      }

      if (i2 == nums2Size) {
        median2 = (target == 1) ? median1 : nums1[i1 + target - 2];
        median1 = nums1[i1 + target - 1];
        break;
      }

      median2 = median1;
      if (nums1[i1] <= nums2[i2]) {
        median1 = nums1[i1];
        ++i1;
      } else {
        median1 = nums2[i2];
        ++i2;
      }

      --target;
    }
    return (median1 + median2) / 2.0;
  } else {
    int i1 = 0, i2 = 0, median;
    while (target > 0) {
      if (i1 == nums1Size) {
        median = nums2[i2 + target - 1];
        break;
      }

      if (i2 == nums2Size) {
        median = nums1[i1 + target - 1];
        break;
      }

      if (nums1[i1] <= nums2[i2]) {
        median = nums1[i1];
        ++i1;
      } else {
        median = nums2[i2];
        ++i2;
      }

      --target;
    }

    return median;
  }
}
