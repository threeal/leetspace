#include <stdbool.h>
#include <stdlib.h>

int* recoverOrder(
    int* order, int orderSize, int* friends, int friendsSize, int* returnSize) {
  bool* isFriends = malloc((orderSize + 1) * sizeof(bool));
  for (int i = 0; i <= orderSize; ++i) isFriends[i] = false;
  for (int i = 0; i < friendsSize; ++i) isFriends[friends[i]] = true;

  int n = 0;
  for (int i = 0; i < orderSize; ++i) {
    if (isFriends[order[i]]) order[n++] = order[i];
  }

  *returnSize = n;
  return order;
}
