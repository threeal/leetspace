int maxLengthBetweenEqualCharacters(char* s) {
  int maxLength = -1;
  int lefts[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  for (int i = 0; s[i] != 0; ++i) {
    int left_id = s[i] - 'a';
    if (lefts[left_id] == -1) {
      lefts[left_id] = i;
    } else {
      const int length = i - lefts[left_id] - 1;
      if (length > maxLength) maxLength = length;
    }
  }
  return maxLength;
}
