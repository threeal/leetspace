int clumsy(int n) {
  const int magic[] = {1, 2, 2, -1, 0, 0, 3, 3};
  return n + (n > 4 ? magic[n % 4] : magic[n + 3]);
}
