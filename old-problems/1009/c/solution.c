int bitwiseComplement(int n) {
  if (n == 0) return 1;
  unsigned int pow = 1;
  while (pow <= (unsigned int)n) pow = pow << 1;
  return ~n & (pow - 1);
}
