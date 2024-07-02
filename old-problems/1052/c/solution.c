int maxSatisfied(
    int* customers, int customersSize,
    int* grumpy, int grumpySize, int minutes) {
  (void)customersSize;

  int right = grumpySize - 1;
  int left = grumpySize - minutes;

  int satisfied = 0;
  for (int i = right; i >= left; --i) {
    satisfied += customers[i];
  }

  for (int i = left - 1; i >= 0; --i) {
    if (!grumpy[i]) satisfied += customers[i];
  }

  int maxSatisfied = satisfied;
  while (--left >= 0) {
    if (grumpy[left]) satisfied += customers[left];
    if (grumpy[right]) satisfied -= customers[right];
    if (satisfied > maxSatisfied) maxSatisfied = satisfied;
    --right;
  }

  return maxSatisfied;
}
