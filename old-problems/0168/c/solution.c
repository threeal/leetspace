char str[8] = {0};

char* convertToTitle(int columnNumber) {
  int strPos = 7;
  while (columnNumber > 0) {
    --columnNumber;
    str[--strPos] = 'A' + columnNumber % 26;
    columnNumber /= 26;
  }
  return str + strPos;
}
