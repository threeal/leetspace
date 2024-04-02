// The solution can simply be done by using a for loop.
//
// Think about it as an inheritance:
//
// - A number ending with 0 will be inherited to a number ending with 4 and 6
// - A number ending with 1 will be inherited to a number ending with 6 and 8
// - And so on...
//
// For example:
//
// - 0 => 04, 06
// - 1 => 16, 18
// - And so on...
//
// So to count the number, we can do the following:
//
// - endedWith6 = endedWith0 + endedWith1
// - endedWith7 = endedWith2 + endedWith6
// - And so on...
//
// At the end of the loop, we can just total the number count.
// And don't forget to handle the mod 10e9+7.

#include <string.h>

const unsigned int mod = 1000000007;

int knightDialer(int n) {
  if (n == 1) return 10;

  // Count of numbers ending with i (0 is 2, 1 is 2, ... 4 is 3, 5 is 0, ...)
  unsigned int nums[10] = {2, 2, 2, 2, 3, 0, 3, 2, 2, 2};

  // Repeat n - 2 times.
  while (--n > 1) {
    // Copy previous number counts;
    unsigned int prevNums[10];
    memcpy(prevNums, nums, 10 * sizeof(unsigned int));

    // 0 depends on 4 and 6, 1 depends on 6 and 8, ...
    nums[0] = (prevNums[4] + prevNums[6]) % mod;
    nums[1] = (prevNums[6] + prevNums[8]) % mod;
    nums[2] = (prevNums[7] + prevNums[9]) % mod;
    nums[3] = (prevNums[4] + prevNums[8]) % mod;
    nums[4] = (prevNums[0] + prevNums[3] + prevNums[9]) % mod;
    nums[6] = (prevNums[0] + prevNums[1] + prevNums[7]) % mod;
    nums[7] = (prevNums[2] + prevNums[6]) % mod;
    nums[8] = (prevNums[1] + prevNums[3]) % mod;
    nums[9] = (prevNums[2] + prevNums[4]) % mod;
  }

  // Calculate total count.
  unsigned int total = 0;
  for (unsigned int i = 0; i < 10; ++i) {
    total = (total + nums[i]) % mod;
  }

  return total;
}
