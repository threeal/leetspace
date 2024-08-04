int countSeniors(char** details, int detailsSize) {
  int count = 0;
  for (int i = detailsSize - 1; i >= 0; --i) {
    if (details[i][11] > '6') {
      ++count;
    } else if (details[i][11] == '6' && details[i][12] > '0') {
      ++count;
    }
  }
  return count;
}
