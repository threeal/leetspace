int minimumChairs(char* s) {
  int maxChairs = 0, chairs = 0;
  for (char* c = s; *c != 0; ++c) {
    if (*c == 'E') {
      if (++chairs > maxChairs) maxChairs = chairs;
    } else {
      --chairs;
    }
  }
  return maxChairs;
}
