char* reversePrefix(char* word, char ch) {
  for (char* right = word; *right != 0; ++right) {
    if (*right == ch) {
      char temp;
      for (char* left = word; left < right; ++left) {
        temp = *left;
        *left = *right;
        *right = temp;
        --right;
      }
      break;
    }
  }
  return word;
}
