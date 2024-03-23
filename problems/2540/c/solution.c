int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int* it1 = nums1;
  int* it2 = nums2;

  nums1 += nums1Size;
  nums2 += nums2Size;

  while (it1 < nums1 && it2 < nums2) {
    if (*it1 == *it2) return *it1;
    *it1 < *it2 ? ++it1 : ++it2;
  }

  return -1;
}
