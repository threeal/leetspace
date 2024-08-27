#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    std::vector<std::vector<int>> output(m, std::vector(n, -1));

    int y{0}, x{-1};
    for (int i{n}; i > 0; --i) {
      if (head == nullptr) return output;
      output[y][++x] = head->val;
      head = head->next;
    }

    --m, --n;
    while (m > 0 || n > 0) {
      for (int i{m}; i > 0; --i) {
        if (head == nullptr) return output;
        output[++y][x] = head->val;
        head = head->next;
      }

      for (int i{n}; i > 0; --i) {
        if (head == nullptr) return output;
        output[y][--x] = head->val;
        head = head->next;
      }

      --m, --n;
      if (m <= 0 && n <= 0) break;

      for (int i{m}; i > 0; --i) {
        if (head == nullptr) return output;
        output[--y][x] = head->val;
        head = head->next;
      }

      for (int i{n}; i > 0; --i) {
        if (head == nullptr) return output;
        output[y][++x] = head->val;
        head = head->next;
      }

      --m, --n;
    }

    return output;
  }
};
