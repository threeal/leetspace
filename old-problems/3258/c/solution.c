int countKConstraintSubstrings(char* s, int k) {
  int count = 0, zeros = 0, ones = 0;
  for (int l = 0, r = 0; s[r] != 0; ++r) {
    if (s[r] == '0') {
      ++zeros;
    } else {
      ++ones;
    }

    while (zeros > k && ones > k) {
      if (s[l] == '0') {
        --zeros;
      } else {
        --ones;
      }
      ++l;
    }

    count += r - l + 1;
  }
  return count;
}
