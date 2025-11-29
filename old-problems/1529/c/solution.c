int minFlips(char* target) {
  int i = 0, count = 0;
  while (1) {
    while (target[i] != 0 && target[i] == '0') ++i;
    if (target[i] == 0) break;
    ++count;

    while (target[i] != 0 && target[i] == '1') ++i;
    if (target[i] == 0) break;
    ++count;
  }
  return count;
}
