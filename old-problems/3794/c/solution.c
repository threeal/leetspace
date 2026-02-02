char* reversePrefix(char* s, int k) {
  for (int l = 0, r = k - 1; l < r; ++l, --r) {
    const char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
  }
  return s;
}
