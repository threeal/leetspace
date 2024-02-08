int firstUniqChar(char* s) {
  int indexes[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

  char* c = s;
  while (*c != 0) {
    if (indexes[*c - 'a'] >= -1) {
      indexes[*c - 'a'] = indexes[*c - 'a'] == -1 ? c - s : -2;
    }
    ++c;
  }

  int res = 100000;
  for (unsigned char i = 0; i < 26; ++i) {
    if (indexes[i] >= 0 && indexes[i] < res) {
      res = indexes[i];
    }
  }

  return res != 100000 ? res : -1;
}
