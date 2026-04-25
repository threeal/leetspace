int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
  return *words[wordsSize - 1] + *target + startIndex;
}
