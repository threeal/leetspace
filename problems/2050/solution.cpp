#include <algorithm>
#include <list>
#include <memory>
#include <optional>
#include <vector>

class Course {
 public:
  int time;
  std::list<std::shared_ptr<Course>> dependencies;

 private:
  mutable std::optional<int> totalTimeCache;

 public:
  Course(int time);

  int totalTime() const;
};

Course::Course(int time) : time(time) {}

int Course::totalTime() const {
  if (!totalTimeCache) {
    // Recursively collect the maximum time from all dependencies.
    int maxTime = 0;
    for (const auto& dependency : dependencies) {
      maxTime = std::max(maxTime, dependency->totalTime());
    }
    totalTimeCache = maxTime + time;
  }

  return *totalTimeCache;
}

class Solution {
 public:
  int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time) {
    // Initialize list of courses that contains time.
    std::vector<std::shared_ptr<Course>> courses(n);
    for (int i = 0; i < n; ++i) {
      courses[i] = std::make_shared<Course>(time[i]);
    }

    // Initialize dependencies of each course.
    for (const auto& relation : relations) {
      courses[relation[1] - 1]->dependencies.push_back(courses[relation[0] - 1]);
    }

    // Find the maximum time of each course.
    int maxTime = 0;
    for (const auto& course : courses) {
      maxTime = std::max(maxTime, course->totalTime());
    }

    return maxTime;
  }
};
