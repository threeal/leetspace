struct Result {
  int a;
  int b;
};

struct Result palindromeEven(char* s, int n, int a, int b);
struct Result palindromeOdd(char* s, int n, int i);

char* longestPalindrome(char* s) {
  struct Result res;
  res.a = 0;
  res.b = 1;

  int n = 0;
  while (s[n] != 0) {
    ++n;
  }

  for (int i = 1; i < n; ++i) {
    struct Result nres = palindromeEven(s, n, i - 1, i);
    if (nres.b - nres.a > res.b - res.a) res = nres;
    if (i < n - 1) {
      nres = palindromeOdd(s, n, i);
      if (nres.b - nres.a > res.b - res.a) res = nres;
    }
  }

  s[res.b] = 0;
  return s + res.a;
}

struct Result palindromeEven(char* s, int n, int a, int b) {
  struct Result res;
  if (s[a] != s[b]) {
    res.a = 0;
    res.b = 0;
    return res;
  }
  while (a >= 0 && b < n) {
    if (s[a] != s[b]) break;
    --a;
    ++b;
  }
  res.a = a + 1;
  res.b = b;
  return res;
}

struct Result palindromeOdd(char* s, int n, int i) {
  return palindromeEven(s, n, i - 1, i + 1);
}
