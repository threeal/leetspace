char kthCharacter(long long k, int* operations, int operationsSize) {
  (void)operationsSize;
  --k;
  int increment = 0;
  for (int i = 0; (k >> i) != 0; ++i) {
    if ((k >> i & 1) != 0) {
      increment += operations[i];
    }
  }
  return 'a' + (increment % 26);
}
