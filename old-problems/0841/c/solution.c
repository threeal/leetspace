#include <stdbool.h>
#include <stdlib.h>

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
  int* queue = malloc(roomsSize * sizeof(int));
  int queueLeft = 0, queueRight = 0;

  queue[queueRight++] = 0;

  bool* visited = malloc(roomsSize * sizeof(bool));
  for (int i = 0; i < roomsSize; ++i) visited[i] = false;

  visited[0] = true;

  int unvisited = roomsSize - 1;
  while (queueLeft < queueRight) {
    const int room = queue[queueLeft++];
    for (int i = 0; i < roomsColSize[room]; ++i) {
      const int key = rooms[room][i];
      if (!visited[key]) {
        queue[queueRight++] = key;
        visited[key] = true;
        --unvisited;
      }
    }
  }

  free(queue);
  free(visited);

  return unvisited == 0;
}
