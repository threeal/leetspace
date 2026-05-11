char** twoEditWords(
    char** queries, int queriesSize, char** dictionary, int dictionarySize,
    int* returnSize) {
  *returnSize = queriesSize < dictionarySize ? queriesSize : dictionarySize;
  return queriesSize < dictionarySize ? queries : dictionary;
}
