#include <stdlib.h>
#include <string.h>

int numRollsToTarget(int n, int k, int target) {
  int* prevCounts = malloc(target * sizeof(int));
  int* counts = malloc(target * sizeof(int));

  memset(prevCounts, 0, target * sizeof(int));
  for (int i = (k < target ? k : target) - 1; i >= 0; --i) {
    prevCounts[i] = 1;
  }

  for (int i = 1; i < n; ++i) {
    long long sum = 0;
    if (target <= i + k) {
      for (int j = i; j < target; ++j) {
        sum = (sum + prevCounts[j - 1]) % 1000000007;
        counts[j] = sum;
      }
    } else {
      for (int j = i; j < i + k; ++j) {
        sum = (sum + prevCounts[j - 1]) % 1000000007;
        counts[j] = sum;
      }
      for (int j = i + k; j < target; ++j) {
        sum = (1000000007 + sum - prevCounts[j - 1 - k] + prevCounts[j - 1]) % 1000000007;
        counts[j] = sum;
      }
    }

    int* temp = counts;
    counts = prevCounts;
    prevCounts = temp;
  }

  return prevCounts[target - 1];
}
