static int countVowels(char* s, int* i);

char* reverseWords(char* s) {
  int i = 0;
  const int firstVowels = countVowels(s, &i);
  while (s[i] != 0) {
    ++i;
    int l = i;
    const int vowels = countVowels(s, &i);
    if (vowels == firstVowels) {
      int r = i - 1;
      while (l < r) {
        const char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        ++l;
        --r;
      }
    }
  }
  return s;
}

static int countVowels(char* s, int* i) {
  int vowels = 0;
  while (s[*i] != 0 && s[*i] != ' ') {
    switch (s[*i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        ++vowels;
    }
    ++(*i);
  }
  return vowels;
}
