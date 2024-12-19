int isPrefixOfWord(char* sentence, char* searchWord) {
  int i = 1;
  char* ca = sentence;

  while (1) {
    char* cb = searchWord;
    while (*cb != 0 && *ca == *cb) {
      ++ca;
      ++cb;
    }

    if (*cb == 0) return i;
    while (*ca >= 'a') ++ca;

    if (*ca == 0) break;

    ++i;
    ++ca;
  }

  return -1;
}
