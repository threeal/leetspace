int countPermutations(int* complexity, int complexitySize) {
  for (int i = 1; i < complexitySize; ++i) {
    if (complexity[i] <= complexity[0]) return 0;
  }

  long long count = 1;
  for (long long i = 2, r = complexitySize; i < r; ++i) {
    count = (count * i) % 1000000007;
  }

  return count;
}
