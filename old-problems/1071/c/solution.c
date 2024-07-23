#include <stdbool.h>
#include <string.h>

bool checkCommonDivisor(
    char* str1, int str1Size, char* str2, int str2Size, int n);

char* gcdOfStrings(char* str1, char* str2) {
  int str1Size = strlen(str1);
  int str2Size = strlen(str2);
  for (int n = str1Size < str2Size ? str1Size : str2Size; n > 0; --n) {
    if (str1Size % n != 0) continue;
    if (str2Size % n != 0) continue;
    if (checkCommonDivisor(str1, str1Size, str2, str2Size, n)) {
      str1[n] = 0;
      return str1;
    }
  }
  return "";
}

bool checkCommonDivisor(
    char* str1, int str1Size, char* str2, int str2Size, int n) {
  for (int i = n - 1; i >= 0; --i) {
    if (str1[i] != str2[i]) return false;

    for (int j = i + n; j < str1Size; j += n) {
      if (str1[j] != str1[i]) return false;
    }

    for (int j = i + n; j < str2Size; j += n) {
      if (str2[j] != str2[i]) return false;
    }
  }

  return true;
}
