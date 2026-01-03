#include <stdlib.h>

struct num_t {
  int steps;
  int num;
};

int compare(const void* a, const void* b) {
  struct num_t* aa = (struct num_t*)a;
  struct num_t* bb = (struct num_t*)b;
  return aa->steps == bb->steps ? aa->num - bb->num : aa->steps - bb->steps;
}

int getKth(int lo, int hi, int k) {
  const int numsSize = hi + 1 - lo;
  struct num_t* nums = malloc(numsSize * sizeof(struct num_t));
  for (int num = lo; num <= hi; ++num) {
    int steps = 0, val = num;
    while (val != 1) {
      val = val % 2 == 0 ? val / 2 : val * 3 + 1;
      ++steps;
    }
    nums[num - lo].steps = steps;
    nums[num - lo].num = num;
  }

  qsort(nums, numsSize, sizeof(struct num_t), compare);

  return nums[k - 1].num;
}
