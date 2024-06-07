void strrev(char* left, char* right) {
  while (left < right) {
    char c = *left;
    *left = *right;
    *right = c;
    ++left;
    --right;
  }
}

char* reverseWords(char* s) {
  char* right = s;
  char* it = right;

  while (*it == ' ') ++it;

  while (*it != 0) {
    char* left = right;
    while (*it != 0 && *it != ' ') {
      *right = *it;
      ++right;
      ++it;
    }

    strrev(left, right - 1);

    while (*it == ' ') ++it;

    if (*it != 0) {
      *right = ' ';
      ++right;
    }
  }

  *right = 0;
  strrev(s, right - 1);
  return s;
}
