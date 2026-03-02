#include <string.h>

int titleToNumber(char* columnTitle) {
  const int columnTitleLen = strlen(columnTitle);
  int num = columnTitle[columnTitleLen - 1] + 1 - 'A', pow = 1;
  for (int i = 1; i < columnTitleLen; ++i) {
    pow *= 26;
    num += (columnTitle[columnTitleLen - i - 1] + 1 - 'A') * pow;
  }
  return num;
}
