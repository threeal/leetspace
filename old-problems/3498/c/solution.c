int reverseDegree(char* s) {
  int degree = 0, pos = 0;
  for (char* c = s; *c != 0; ++c) {
    degree += (123 - *c) * (++pos);
  }
  return degree;
}
