char* toLowerCase(char* s) {
  for (char* c = s; *c != 0; ++c) {
    if (*c >= 'A' && *c <= 'Z') *c += 'a' - 'A';
  }
  return s;
}
