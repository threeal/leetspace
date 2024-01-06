int minOperations(char* s) {
  int cost01 = 0;

  int i = 0;
  while (s[i] != 0) {
    if (s[i] - '0' != i % 2) {
      ++cost01;
    }
    ++i;
  }

  const int cost10 = i - cost01;
  return cost01 < cost10 ? cost01 : cost10;
}
