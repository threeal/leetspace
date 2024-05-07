long long wonderfulSubstrings(char* word) {
  long long count = 0;
  int frequencies[1024] = {0};
  frequencies[0] = 1;
  int sum = 0;
  while (*word != 0) {
    sum ^= 1 << (*word - 'a');
    count += frequencies[sum]++ + frequencies[sum ^ 1] + frequencies[sum ^ 2] + frequencies[sum ^ 4] + frequencies[sum ^ 8] + frequencies[sum ^ 16] + frequencies[sum ^ 32] + frequencies[sum ^ 64] + frequencies[sum ^ 128] + frequencies[sum ^ 256] + frequencies[sum ^ 512];
    ++word;
  }
  return count;
}
