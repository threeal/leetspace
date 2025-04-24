int fib(int n) {
  if (n == 0) return 0;
  int a = 0, b = 1;
  while (--n != 0) {
    const int c = a + b;
    a = b;
    b = c;
  }
  return b;
}
