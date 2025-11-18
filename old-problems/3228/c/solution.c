int maxOperations(char* s) {
  int operations = 0, ones = 0;
  while (*s != 0) {
    while (*s == '1') ++ones, ++s;
    if (*s == 0) break;

    while (*s == '0') ++s;
    operations += ones;
  }

  return operations;
}
