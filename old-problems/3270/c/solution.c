int generateKey(int num1, int num2, int num3) {
  int key = 0;
  for (int exp = 1; exp <= 1000; exp *= 10) {
    const int n1 = num1 / exp % 10;
    const int n2 = num2 / exp % 10;
    const int n12 = n1 < n2 ? n1 : n2;
    const int n3 = num3 / exp % 10;
    key += (n12 < n3 ? n12 : n3) * exp;
  }
  return key;
}
