#include <limits.h>
#include <stdlib.h>

int closestMeetingNode(int* edges, int edgesSize, int node1, int node2) {
  int dist = 0;
  int* dist1 = malloc(edgesSize * sizeof(int));
  for (int i = 0; i < edgesSize; ++i) dist1[i] = -1;

  while (node1 != -1 && dist1[node1] == -1) {
    dist1[node1] = dist++;
    node1 = edges[node1];
  }

  dist = 0;
  int* dist2 = malloc(edgesSize * sizeof(int));
  for (int i = 0; i < edgesSize; ++i) dist2[i] = -1;

  while (node2 != -1 && dist2[node2] == -1) {
    dist2[node2] = dist++;
    node2 = edges[node2];
  }

  int maxDist = INT_MAX, res = -1;
  for (int i = 0; i < edgesSize; ++i) {
    if (dist1[i] != -1 && dist2[i] != -1) {
      const int dist = dist1[i] >= dist2[i] ? dist1[i] : dist2[i];
      if (dist < maxDist) {
        maxDist = dist;
        res = i;
      }
    }
  }

  return res;
}
