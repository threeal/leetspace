int compareVersion(char* version1, char* version2) {
  while (*version1 != 0 && *version2 != 0) {
    while (*version1 == '0') ++version1;
    char* begin1 = version1;

    while (*version2 == '0') ++version2;
    char* begin2 = version2;

    while (*version1 != 0 && *version1 != '.') ++version1;
    while (*version2 != 0 && *version2 != '.') ++version2;

    if (version1 - begin1 == version2 - begin2) {
      while (begin1 < version1 && begin2 < version2) {
        if (*begin1 != *begin2) {
          return *begin1 < *begin2 ? -1 : 1;
        }
        ++begin1;
        ++begin2;
      }
    } else {
      return version1 - begin1 < version2 - begin2 ? -1 : 1;
    }

    if (*version1 != 0) ++version1;
    if (*version2 != 0) ++version2;
  }

  while (*version1 != 0) {
    while (*version1 == '0') ++version1;
    if (*version1 != 0) {
      if (*version1 != '.') return 1;
      ++version1;
    }
  }

  while (*version2 != 0) {
    while (*version2 == '0') ++version2;
    if (*version2 != 0) {
      if (*version2 != '.') return -1;
      ++version2;
    }
  }

  return 0;
}
