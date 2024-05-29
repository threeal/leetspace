int dfs(int* counts, const int* num, const int* end, int k);

int beautifulSubsets(int* nums, int numsSize, int k) {
  int counts[1001] = {0};
  return dfs(counts, nums, nums + numsSize, k);
}

int dfs(int* counts, const int* num, const int* end, int k) {
  if (num >= end) return 0;
  int subsets = 0;

  if (counts[*num] == 0) {
    if (*num + k <= 1000) ++counts[*num + k];
    if (*num - k >= 0) ++counts[*num - k];

    subsets += 1 + dfs(counts, num + 1, end, k);

    if (*num + k <= 1000) --counts[*num + k];
    if (*num - k >= 0) --counts[*num - k];
  }

  return subsets + dfs(counts, num + 1, end, k);
}
