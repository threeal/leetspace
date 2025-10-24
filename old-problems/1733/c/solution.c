#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minimumTeachings(
    int n, int** languages, int languagesSize, int* languagesColSize,
    int** friendships, int friendshipsSize, int* friendshipsColSize) {
  (void)friendshipsColSize;

  for (int i = 0; i < languagesSize; ++i) {
    qsort(languages[i], languagesColSize[i], sizeof(int), compare);
  }

  int* languagesCounts = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) languagesCounts[i] = 0;

  int needLearn = 0;
  bool* visited = malloc(languagesSize * sizeof(bool));
  for (int i = 0; i < languagesSize; ++i) visited[i] = false;

  for (int i = 0; i < friendshipsSize; ++i) {
    bool canCommunicate = false;
    for (int j = 0; j < languagesColSize[friendships[i][0] - 1]; ++j) {
      const int language = languages[friendships[i][0] - 1][j];

      int l = 0, r = languagesColSize[friendships[i][1] - 1] - 1;
      while (l < r) {
        const int mid = l + (r - l) / 2;
        if (languages[friendships[i][1] - 1][mid] < language) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }

      if (languages[friendships[i][1] - 1][l] == language) {
        canCommunicate = true;
        break;
      }
    }

    if (!canCommunicate) {
      if (!visited[friendships[i][0] - 1]) {
        visited[friendships[i][0] - 1] = true;
        ++needLearn;

        for (int j = 0; j < languagesColSize[friendships[i][0] - 1]; ++j) {
          ++languagesCounts[languages[friendships[i][0] - 1][j] - 1];
        }
      }

      if (!visited[friendships[i][1] - 1]) {
        visited[friendships[i][1] - 1] = true;
        ++needLearn;

        for (int j = 0; j < languagesColSize[friendships[i][1] - 1]; ++j) {
          ++languagesCounts[languages[friendships[i][1] - 1][j] - 1];
        }
      }
    }
  }

  int maxLanguageCount = languagesCounts[0];
  for (int i = 1; i < n; ++i) {
    if (languagesCounts[i] > maxLanguageCount) {
      maxLanguageCount = languagesCounts[i];
    }
  }

  free(languagesCounts);
  free(visited);

  return needLearn - maxLanguageCount;
}
