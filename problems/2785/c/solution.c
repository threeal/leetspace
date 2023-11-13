// clang-format off
enum { A = 0, E, I, O, U, a, e, i, o, u };
// clang-format on

char* sortVowels(char* s) {
  int vowelsCount[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  char* c = s;
  while (*c != 0) {
    switch (*c) {
      // clang-format off
      case 'A': ++vowelsCount[A]; break;
      case 'E': ++vowelsCount[E]; break;
      case 'I': ++vowelsCount[I]; break;
      case 'O': ++vowelsCount[O]; break;
      case 'U': ++vowelsCount[U]; break;
      case 'a': ++vowelsCount[a]; break;
      case 'e': ++vowelsCount[e]; break;
      case 'i': ++vowelsCount[i]; break;
      case 'o': ++vowelsCount[o]; break;
      case 'u': ++vowelsCount[u]; break;
        // clang-format on
    }
    ++c;
  }

  int vowel = A;
  c = s;
  while (*c != 0) {
    switch (*c) {
      // clang-format off
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        while (vowelsCount[vowel] <= 0) ++vowel;
        switch (vowel) {
          case A: *c = 'A'; break;
          case E: *c = 'E'; break;
          case I: *c = 'I'; break;
          case O: *c = 'O'; break;
          case U: *c = 'U'; break;
          case a: *c = 'a'; break;
          case e: *c = 'e'; break;
          case i: *c = 'i'; break;
          case o: *c = 'o'; break;
          case u: *c = 'u'; break;
        }
        --vowelsCount[vowel];
        break;
        // clang-format on
    }
    ++c;
  }

  return s;
}
