#include <limits.h>
#include <stdlib.h>
#include <string.h>

struct queue_t {
  int city;
  int cost;
  struct queue_t* next;
};

int findCheapestPrice(
    int n, int** flights, int flightsSize, int* flightsColSize,
    int src, int dst, int k) {
  (void)flightsColSize;

  int nextCitiesSize[100] = {0};
  int totalNextCitiesCount = 0;
  for (int i = 0; i < flightsSize; ++i) {
    ++nextCitiesSize[flights[i][0]];
    ++totalNextCitiesCount;
  }

  int* nextCities[100];
  int* nextCitiesBuffer = malloc(2 * totalNextCitiesCount * sizeof(int));
  for (int i = 0, shift = 0; i < n; ++i) {
    nextCities[i] = nextCitiesBuffer + shift;
    shift += 2 * nextCitiesSize[i];
  }

  memset(nextCitiesSize, 0, n * sizeof(int));
  for (int i = 0; i < flightsSize; ++i) {
    nextCities[flights[i][0]][nextCitiesSize[flights[i][0]] * 2] = flights[i][1];
    nextCities[flights[i][0]][nextCitiesSize[flights[i][0]] * 2 + 1] = flights[i][2];
    ++nextCitiesSize[flights[i][0]];
  }

  int distanceToCities[100];
  for (int i = 0; i < n; ++i) distanceToCities[i] = INT_MAX;

  struct queue_t* qbegin = malloc(sizeof(struct queue_t));
  qbegin->city = src;
  qbegin->cost = 0;
  qbegin->next = NULL;

  struct queue_t* qpool = NULL;

  while (qbegin != NULL && k >= 0) {
    struct queue_t* qnode = qbegin;
    qbegin = NULL;

    while (qnode != NULL) {
      const int city = qnode->city;
      const int cost = qnode->cost;

      struct queue_t* temp = qnode;
      qnode = qnode->next;
      temp->next = qpool;
      qpool = temp;

      for (int i = 0; i < nextCitiesSize[city]; ++i) {
        const int nextCity = nextCities[city][i * 2];
        const int nextCost = nextCities[city][i * 2 + 1];
        if (cost + nextCost >= distanceToCities[nextCity]) continue;
        distanceToCities[nextCity] = cost + nextCost;

        struct queue_t* temp = qbegin;
        if (qpool == NULL) {
          qbegin = malloc(sizeof(struct queue_t));
        } else {
          qbegin = qpool;
          qpool = qpool->next;
        }
        qbegin->next = temp;
        qbegin->city = nextCity;
        qbegin->cost = cost + nextCost;
      }
    }
    --k;
  }

  free(nextCitiesBuffer);
  while (qpool != NULL) {
    struct queue_t* temp = qpool;
    qpool = qpool->next;
    free(temp);
  }

  return distanceToCities[dst] != INT_MAX ? distanceToCities[dst] : -1;
}
