int countSubstrings(char* s) {
  int count = 0;
  for (char* c = s; *c != 0; ++c) {
    char* l = c - 1;
    char* r = c + 1;
    while (l >= s && *l == *r) {
      --l;
      ++r;
    }
    count += r - c;

    l = c - 1;
    r = c;
    while (l >= s && *l == *r) {
      --l;
      ++r;
    }
    count += r - c;
  }

  return count;
}
