#include <stdlib.h>
#include <string.h>

struct stream_node_t {
  const char* str;
  int len;
  struct stream_node_t* next;
};

struct stream_t {
  struct stream_node_t* head;
  struct stream_node_t* tail;
  int totalLen;
};

struct stream_t* create_stream() {
  struct stream_node_t* node = malloc(sizeof(struct stream_node_t));
  node->str = NULL;
  node->len = 0;
  node->next = NULL;

  struct stream_t* stream = malloc(sizeof(struct stream_t));
  stream->head = node;
  stream->tail = node;
  stream->totalLen = 1;

  return stream;
}

void destroy_stream(struct stream_t* stream) {
  struct stream_node_t* node = stream->head;
  while (node != NULL) {
    struct stream_node_t* next = node->next;
    free(node);
    node = next;
  }
  free(stream);
}

void stream_push(struct stream_t* stream, const char* str, int len) {
  struct stream_node_t* node = malloc(sizeof(struct stream_node_t));
  node->str = str;
  node->len = len;
  node->next = NULL;

  stream->tail->next = node;
  stream->tail = node;

  stream->totalLen += len;
}

char* stream_to_string(struct stream_t* stream) {
  char* str = malloc(stream->totalLen * sizeof(char));
  char* it = str;

  struct stream_node_t* node = stream->head->next;
  while (node != NULL) {
    memcpy(it, node->str, node->len);
    it += node->len;
    node = node->next;
  }
  *it = 0;

  return str;
}

void first(struct stream_t* stream, int num) {
  switch (num) {
      // clang-format off
    case 1: stream_push(stream, "One", 3); break;
    case 2: stream_push(stream, "Two", 3); break;
    case 3: stream_push(stream, "Three", 5); break;
    case 4: stream_push(stream, "Four", 4); break;
    case 5: stream_push(stream, "Five", 4); break;
    case 6: stream_push(stream, "Six", 3); break;
    case 7: stream_push(stream, "Seven", 5); break;
    case 8: stream_push(stream, "Eight", 5); break;
    case 9: stream_push(stream, "Nine", 4); break;
      // clang-format on
  }
}

static void tenth(struct stream_t* stream, int num) {
  if (num >= 20) {
    // clang-format off
    switch (num / 10) {
      case 2: stream_push(stream, "Twenty", 6); break;
      case 3: stream_push(stream, "Thirty", 6); break;
      case 4: stream_push(stream, "Forty", 5); break;
      case 5: stream_push(stream, "Fifty", 5); break;
      case 6: stream_push(stream, "Sixty", 5); break;
      case 7: stream_push(stream, "Seventy", 7); break;
      case 8: stream_push(stream, "Eighty", 6); break;
      case 9: stream_push(stream, "Ninety", 6); break;
    }
    // clang-format on

    num %= 10;
    if (num > 0) {
      stream_push(stream, " ", 1);
      first(stream, num);
    }
  } else {
    // clang-format off
    switch (num) {
      case 10: stream_push(stream, "Ten", 3); break;
      case 11: stream_push(stream, "Eleven", 6); break;
      case 12: stream_push(stream, "Twelve", 6); break;
      case 13: stream_push(stream, "Thirteen", 8); break;
      case 14: stream_push(stream, "Fourteen", 8); break;
      case 15: stream_push(stream, "Fifteen", 7); break;
      case 16: stream_push(stream, "Sixteen", 7); break;
      case 17: stream_push(stream, "Seventeen", 9); break;
      case 18: stream_push(stream, "Eighteen", 8); break;
      case 19: stream_push(stream, "Nineteen", 8); break;
      default: first(stream, num);
    }
    // clang-format on
  }
}

static void hundredth(struct stream_t* stream, int num) {
  if (num >= 100) {
    first(stream, num / 100);
    stream_push(stream, " Hundred", 8);
    num %= 100;
    if (num > 0) {
      stream_push(stream, " ", 1);
      tenth(stream, num);
    }
  } else {
    tenth(stream, num);
  }
}

static void thousandth(struct stream_t* stream, int num) {
  if (num >= 1000) {
    hundredth(stream, num / 1000);
    stream_push(stream, " Thousand", 9);
    num %= 1000;
    if (num > 0) {
      stream_push(stream, " ", 1);
      hundredth(stream, num);
    }
  } else {
    hundredth(stream, num);
  }
}

static void millionth(struct stream_t* stream, int num) {
  if (num >= 1000000) {
    hundredth(stream, num / 1000000);
    stream_push(stream, " Million", 8);
    num %= 1000000;
    if (num > 0) {
      stream_push(stream, " ", 1);
      thousandth(stream, num);
    }
  } else {
    thousandth(stream, num);
  }
}

static void billionth(struct stream_t* stream, int num) {
  if (num >= 1000000000) {
    hundredth(stream, num / 1000000000);
    stream_push(stream, " Billion", 8);
    num %= 1000000000;
    if (num > 0) {
      stream_push(stream, " ", 1);
      millionth(stream, num);
    }
  } else {
    millionth(stream, num);
  }
}

char* numberToWords(int num) {
  if (num == 0) return "Zero";
  struct stream_t* stream = create_stream();

  billionth(stream, num);
  char* words = stream_to_string(stream);

  destroy_stream(stream);
  return words;
}
