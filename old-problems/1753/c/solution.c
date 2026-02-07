int maximumScore(int a, int b, int c) {
  const int bc = b > c ? b : c;
  const int abc = a > bc ? a : bc;
  const int x = (a + b + c) / 2;
  const int y = a + b + c - abc;
  return x < y ? x : y;
}
