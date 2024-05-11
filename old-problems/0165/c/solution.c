#include <string.h>

int compareVersion(char* version1, char* version2) {
  const int size1 = strlen(version1);
  const int size2 = strlen(version2);

  int i1 = 0;
  int i2 = 0;

  while (i1 < size1 && i2 < size2) {
    while (i1 < size1 && version1[i1] == '0') ++i1;
    int begin1 = i1;

    while (i2 < size2 && version2[i2] == '0') ++i2;
    int begin2 = i2;

    while (i1 < size1 && version1[i1] != '.') ++i1;
    while (i2 < size2 && version2[i2] != '.') ++i2;

    if (i1 - begin1 == i2 - begin2) {
      while (begin1 < i1 && begin2 < i2) {
        if (version1[begin1] != version2[begin2]) {
          return version1[begin1] < version2[begin2] ? -1 : 1;
        }
        ++begin1;
        ++begin2;
      }
    } else {
      return i1 - begin1 < i2 - begin2 ? -1 : 1;
    }

    ++i1;
    ++i2;
  }

  while (i1 < size1) {
    while (i1 < size1 && version1[i1] == '0') ++i1;
    if (i1 < size1) {
      if (version1[i1] != '.') return 1;
      ++i1;
    }
  }

  while (i2 < size2) {
    while (i2 < size2 && version2[i2] == '0') ++i2;
    if (i2 < size2) {
      if (version2[i2] != '.') return -1;
      ++i2;
    }
  }

  return 0;
}
