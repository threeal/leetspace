int bestClosingTime(char* customers) {
  int penalty = 0;
  for (char* c = customers; *c != 0; ++c) {
    if (*c == 'Y') ++penalty;
  }

  int bestTime = 0;
  int bestPenalty = penalty;

  for (int i = 0; customers[i] != 0; ++i) {
    if (customers[i] == 'Y') {
      --penalty;
    } else {
      ++penalty;
    }

    if (penalty < bestPenalty) {
      bestPenalty = penalty;
      bestTime = i + 1;
    }
  }

  return bestTime;
}
