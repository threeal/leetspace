char* decodeMessage(char* key, char* message) {
  char map[26] = {0};

  char val = 'a';
  for (char* c = key; *c != 0; ++c) {
    if (*c != ' ' && map[*c - 'a'] == 0) {
      map[*c - 'a'] = val++;
    }
  }

  for (char* c = message; *c != 0; ++c) {
    if (*c != ' ') *c = map[*c - 'a'];
  }

  return message;
}
