int commonFactors(int a, int b) {
  if (b < a) {
    const int temp = a;
    a = b;
    b = temp;
  }

  int factors = 1;
  for (int i = 2; i <= a; ++i) {
    if (a % i == 0 && b % i == 0) ++factors;
  }
  return factors;
}
