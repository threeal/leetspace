int minFlips(int a, int b, int c) {
  c ^= a | b;
  return __builtin_popcount(c) + __builtin_popcount(a & b & c);
}
