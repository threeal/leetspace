int maxFreqSum(char* s) {
  int freqs[26] = {0};
  for (char* c = s; *c != 0; ++c) ++freqs[*c - 'a'];

  int vowels = 0, consonants = 0;
  for (int i = 0; i < 26; ++i) {
    switch (i) {
      case 0:
      case 4:
      case 8:
      case 14:
      case 20:
        if (freqs[i] > vowels) vowels = freqs[i];
        break;

      default:
        if (freqs[i] > consonants) consonants = freqs[i];
    }
  }

  return vowels + consonants;
}
