int minNumber(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int first = 0, second = 0;
  for (int i = nums1Size - 1; i >= 0; --i) first |= 1 << nums1[i];
  for (int i = nums2Size - 1; i >= 0; --i) second |= 1 << nums2[i];
  if ((first & second) > 0) return __builtin_ctz(first & second);
  first = __builtin_ctz(first);
  second = __builtin_ctz(second);
  return first < second ? first * 10 + second : second * 10 + first;
}
