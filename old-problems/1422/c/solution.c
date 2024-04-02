int maxScore(char* s) {
  int zeros = s[0] == '0' ? 1 : 0;

  int ones = 0;
  for (char* c = s + 1; *c != 0; ++c) {
    if (*c == '1') ++ones;
  }

  int score = zeros + ones;
  for (char* c = s + 1; *(c + 1) != 0; ++c) {
    switch (*c) {
      case '0':
        ++zeros;
        break;

      case '1':
        --ones;
        break;
    }

    if (zeros + ones > score)
      score = zeros + ones;
  }

  return score;
}
