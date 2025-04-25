int countBinarySubstrings(char* s) {
  int total = 0, zeros = 0, ones = 0;
  while (*s != 0) {
    zeros = 0;
    while (*s == '0') ++s, ++zeros;
    total += zeros <= ones ? zeros : ones;

    ones = 0;
    while (*s == '1') ++s, ++ones;
    total += zeros <= ones ? zeros : ones;
  }
  return total;
}
