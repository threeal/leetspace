int maxConsecutiveAnswers(char* answerKey, int k) {
  int maxConsecutive = 0;
  int lt = 0, lf = 0;
  int kt = k, kf = k;
  for (int r = 0; answerKey[r] != 0; ++r) {
    if (answerKey[r] == 'F') {
      --kt;
      while (kt < 0) {
        if (answerKey[lt] == 'F') ++kt;
        ++lt;
      }
    } else {
      --kf;
      while (kf < 0) {
        if (answerKey[lf] == 'T') ++kf;
        ++lf;
      }
    }

    const int consecutive = r - (lt <= lf ? lt : lf) + 1;
    if (consecutive > maxConsecutive) maxConsecutive = consecutive;
  }
  return maxConsecutive;
}
