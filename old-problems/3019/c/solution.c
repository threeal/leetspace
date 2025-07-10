int countKeyChanges(char* s) {
  int changes = 0;
  if (s[0] > 'Z') s[0] += 'A' - 'a';
  for (int i = 1; s[i] != 0; ++i) {
    if (s[i] > 'Z') s[i] += 'A' - 'a';
    if (s[i] != s[i - 1]) ++changes;
  }
  return changes;
}
