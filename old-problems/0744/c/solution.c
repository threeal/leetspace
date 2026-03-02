char nextGreatestLetter(char* letters, int lettersSize, char target) {
  char res = 127;
  for (int i = 0; i < lettersSize; ++i) {
    if (letters[i] > target && letters[i] < res) res = letters[i];
  }

  return res == 127 ? letters[0] : res;
}
