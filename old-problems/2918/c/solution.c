long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  long long zeros1 = 0, sum1 = 0;
  for (int i = 0; i < nums1Size; ++i) {
    if (nums1[i] == 0) {
      ++zeros1;
    } else {
      sum1 += nums1[i];
    }
  }

  long long zeros2 = 0, sum2 = 0;
  for (int i = 0; i < nums2Size; ++i) {
    if (nums2[i] == 0) {
      ++zeros2;
    } else {
      sum2 += nums2[i];
    }
  }

  if (zeros1 == 0) {
    if (zeros2 == 0) {
      return sum1 == sum2 ? sum1 : -1;
    } else {
      return sum1 >= sum2 + zeros2 ? sum1 : -1;
    }
  } else {
    if (zeros2 == 0) {
      return sum2 >= sum1 + zeros1 ? sum2 : -1;
    } else {
      return sum1 + zeros1 >= sum2 + zeros2
          ? sum1 + zeros1
          : sum2 + zeros2;
    }
  }
}
