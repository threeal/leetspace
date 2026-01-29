int totalNumbers(int* digits, int digitsSize) {
  int freqs[10] = {0}, odds = 0, evens = 0;
  for (int i = 0; i < digitsSize; ++i) {
    if (++freqs[digits[i]] == 1) {
      if (digits[i] % 2 == 0) {
        ++evens;
      } else {
        ++odds;
      }
    }
  }

  int total = evens * (odds + evens - 1) * (odds + evens - 2);

  if (freqs[0] != 0) {
    total -= (evens - 1) * (odds + evens - 2);
    if (freqs[0] >= 2) {
      total += evens + odds - 1;
    }
  }

  for (int digit = 1; digit < 10; digit += 2) {
    if (freqs[digit] >= 2) total += evens;
  }

  for (int digit = 2; digit < 10; digit += 2) {
    if (freqs[digit] >= 2) {
      if (freqs[digit] >= 3) ++total;
      total +=
          evens - 1 + (odds + evens - 1) +
          (odds + evens - (freqs[0] == 0 ? 1 : 2));
    }
  }

  return total;
}
