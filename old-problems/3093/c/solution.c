#include <stdlib.h>
#include <string.h>

struct trie_t {
  int idx;
  int idxLen;
  struct trie_t* children[26];
};

static void initTrie(struct trie_t* trie, int idx, int idxLen) {
  memset(trie, 0, sizeof(struct trie_t));
  trie->idx = idx;
  trie->idxLen = idxLen;
}

static void cleanupTrie(struct trie_t* trie) {
  for (int i = 0; i < 26; ++i) {
    if (trie->children[i] != NULL) {
      cleanupTrie(trie->children[i]);
      free(trie->children[i]);
    }
  }
}

int* stringIndices(
    char** wordsContainer, int wordsContainerSize,
    char** wordsQuery, int wordsQuerySize, int* returnSize) {
  struct trie_t root;
  initTrie(&root, 0, strlen(wordsContainer[0]));

  for (int i = 0; i < wordsContainerSize; ++i) {
    const int len = strlen(wordsContainer[i]);
    if (len < root.idxLen) {
      root.idx = i;
      root.idxLen = len;
    }

    struct trie_t* trie = &root;
    for (int j = len - 1; j >= 0; --j) {
      int k = wordsContainer[i][j] - 'a';
      if (trie->children[k] == NULL) {
        struct trie_t* child = malloc(sizeof(struct trie_t));
        initTrie(child, i, len);
        trie->children[k] = child;
      } else if (len < trie->children[k]->idxLen) {
        trie->children[k]->idx = i;
        trie->children[k]->idxLen = len;
      }
      trie = trie->children[k];
    }
  }

  int* output = malloc(wordsQuerySize * sizeof(int));
  for (int i = 0; i < wordsQuerySize; ++i) {
    const int len = strlen(wordsQuery[i]);
    struct trie_t* trie = &root;
    for (int j = len - 1; j >= 0; --j) {
      int k = wordsQuery[i][j] - 'a';
      if (trie->children[k] == NULL) break;
      trie = trie->children[k];
    }
    output[i] = trie->idx;
  }

  cleanupTrie(&root);

  *returnSize = wordsQuerySize;
  return output;
}
