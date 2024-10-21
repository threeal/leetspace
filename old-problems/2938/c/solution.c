long long minimumSteps(char* s) {
  long long sum = 0, ones = 0;
  while (*s != 0) {
    if (*s == '1') {
      ++ones;
    } else {
      sum += ones;
    }
    ++s;
  }
  return sum;
}
