int distributeCandies(int n, int limit) {
  if (3 * limit <= n) return 3 * limit == n ? 1 : 0;

  const int allCases = (n + 2) * (n + 1) / 2;

  const int excludeOne = n - (limit + 1) + 2;
  const int oneLimit =
      excludeOne > 1 ? 3 * excludeOne * (excludeOne - 1) / 2 : 0;

  const int excludeTwo = n - 2 * (limit + 1) + 2;
  const int twoLimit =
      excludeTwo > 1 ? 3 * excludeTwo * (excludeTwo - 1) / 2 : 0;

  const int excludeThree = n - 3 * (limit + 1) + 2;
  const int threeLimit =
      excludeThree > 1 ? excludeThree * (excludeThree - 1) / 2 : 0;

  return allCases - oneLimit + twoLimit - threeLimit;
}
