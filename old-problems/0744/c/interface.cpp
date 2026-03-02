#include <vector>

extern "C" {
char nextGreatestLetter(char* letters, int lettersSize, char target);
}

char solution_c(std::vector<char> letters, char target) {
  return nextGreatestLetter(letters.data(), letters.size(), target);
}
