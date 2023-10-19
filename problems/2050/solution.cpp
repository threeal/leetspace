class Course {
 public:
  int time;
  list<shared_ptr<Course>> dependencies;

 private:
  mutable optional<int> totalTimeCache;

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
      maxTime = max(maxTime, dependency->totalTime());
    }
    totalTimeCache = maxTime + time;
  }

  return *totalTimeCache;
}

class Solution {
 public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    // Initialize list of courses that contains time.
    vector<shared_ptr<Course>> courses(n);
    for (int i = 0; i < n; ++i) {
      courses[i] = make_shared<Course>(time[i]);
    }

    // Initialize dependencies of each course.
    for (const auto& relation : relations) {
      courses[relation[1] - 1]->dependencies.push_back(courses[relation[0] - 1]);
    }

    // Find the maximum time of each course.
    int maxTime = 0;
    for (const auto& course : courses) {
      maxTime = max(maxTime, course->totalTime());
    }

    return maxTime;
  }
};
