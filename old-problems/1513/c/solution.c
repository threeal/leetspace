int numSub(char* s) {
  long long num = 0, ones = 0;
  for (char* c = s; *c != 0; ++c) {
    if (*c == '0') {
      num = (num + (ones * (ones + 1)) / 2) % 1000000007;
      ones = 0;
    } else {
      ++ones;
    }
  }
  return (num + (ones * (ones + 1)) / 2) % 1000000007;
}
