int minPartitions(char* n) {
  char largest = '0';
  for (char* c = n; *c != 0; ++c) {
    if (*c > largest) largest = *c;
  }
  return largest - '0';
}
