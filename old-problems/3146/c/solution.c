int findPermutationDifference(char* s, char* t) {
  int indices[26];
  for (int i = 0; s[i] != 0; ++i) {
    indices[s[i] - 'a'] = i;
  }

  int diff = 0;
  for (int i = 0; s[i] != 0; ++i) {
    const int index = indices[t[i] - 'a'];
    diff += i >= index ? i - index : index - i;
  }

  return diff;
}
