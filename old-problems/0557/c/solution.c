void swap(char* s, int a, int b);

char* reverseWords(char* s) {
  int a = 0;
  int i = 0;
  while (s[i] != 0) {
    if (s[i] == ' ') {
      swap(s, a, i - 1);
      a = i + 1;
    }
    ++i;
  }
  if (s[i - 1] != ' ') {
    swap(s, a, i - 1);
  }
  return s;
}

void swap(char* s, int a, int b) {
  while (b > a) {
    char tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
    ++a;
    --b;
  }
}
