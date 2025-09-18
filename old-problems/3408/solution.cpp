#include <vector>

class TaskManager {
 public:
  TaskManager(std::vector<std::vector<int>>& tasks) {
    (void)tasks;
  }

  void add(int userId, int taskId, int priority) {
    (void)userId;
    (void)taskId;
    (void)priority;
  }

  void edit(int taskId, int newPriority) {
    (void)taskId;
    (void)newPriority;
  }

  void rmv(int taskId) {
    (void)taskId;
  }

  int execTop() {
    return 0;
  }
};
