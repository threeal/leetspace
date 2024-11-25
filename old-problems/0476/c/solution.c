int findComplement(int num) {
  unsigned int pow = 1;
  while (pow <= (unsigned int)num) pow = pow << 1;
  return ~num & (pow - 1);
}
