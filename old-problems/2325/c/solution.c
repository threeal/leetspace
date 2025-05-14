char* decodeMessage(char* key, char* message) {
  return *key > *message ? key : message;
}
