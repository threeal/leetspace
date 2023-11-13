// The solution can be done by counting the number of vowel occurrences and then replacing each vowel using that count as references.

// This enum helps store the count of vowels in an array.
// clang-format off
enum { A = 0, E, I, O, U, a, e, i, o, u };
// clang-format on

char* sortVowels(char* s) {
  int vowelsCount[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  // Count the vowels from the given string.
  char* c = s;
  while (*c != 0) {
    // Switch case is used for faster lookup.
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

  // From the first vowel, replace each vowel in the given string according to the vowel count.
  int vowel = A;
  c = s;
  while (*c != 0) {
    // Switch case is used for faster lookup.
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

  // Return the modified string.
  return s;
}
