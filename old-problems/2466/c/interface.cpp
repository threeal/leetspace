extern "C" {
int countGoodStrings(int low, int high, int zero, int one);
}

int solution_c(int low, int high, int zero, int one) {
  return countGoodStrings(low, high, zero, one);
}
