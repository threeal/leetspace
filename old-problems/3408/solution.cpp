#include <queue>
#include <unordered_map>
#include <vector>

class TaskManager {
 private:
  std::unordered_map<int, std::tuple<int, int>> tasks{};
  std::priority_queue<std::tuple<int, int>> taskPriorities;

 public:
  TaskManager(std::vector<std::vector<int>>& tasks) {
    for (const auto& task : tasks) {
      add(task[0], task[1], task[2]);
    }
  }

  void add(int userId, int taskId, int priority) {
    tasks.emplace(taskId, std::tuple<int, int>{userId, priority});
    taskPriorities.push({priority, taskId});
  }

  void edit(int taskId, int newPriority) {
    std::get<1>(tasks[taskId]) = newPriority;
    taskPriorities.push({newPriority, taskId});
  }

  void rmv(int taskId) {
    tasks.erase(taskId);
  }

  int execTop() {
    while (!taskPriorities.empty()) {
      const auto [priority, taskId] = taskPriorities.top();
      taskPriorities.pop();

      const auto it = tasks.find(taskId);
      if (it != tasks.end()) {
        const auto [userId, actualPriority] = it->second;
        if (priority == actualPriority) {
          rmv(taskId);
          return userId;
        }
      }
    }
    return -1;
  }
};
