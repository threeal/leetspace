int percentageLetter(char* s, char letter) {
  int count = 0, sSize = 0;
  while (s[sSize] != '\0') {
    if (s[sSize] == letter) ++count;
    ++sSize;
  }
  return (count * 100) / sSize;
}
