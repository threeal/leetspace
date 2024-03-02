char* maximumOddBinaryNumber(char* s) {
  int count = 0;
  char* c = s;
  while (*c != 0) {
    if (*c == '1') ++count;
    ++c;
  }

  if (count == 0) {
    return s;
  }

  --count;
  *(--c) = '1';

  for (char* cc = s; cc < c; ++cc) {
    if (count > 0) {
      *cc = '1';
      --count;
    } else {
      *cc = '0';
    }
  }

  return s;
}
