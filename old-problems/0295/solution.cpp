#include <queue>
#include <vector>

class MedianFinder {
 private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  std::priority_queue<int> maxHeap;

 public:
  MedianFinder() : minHeap{}, maxHeap{} {}

  void addNum(int num) {
    if (maxHeap.empty() || num <= maxHeap.top()) {
      maxHeap.push(num);
      if (maxHeap.size() > minHeap.size() + 1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      }
    } else {
      minHeap.push(num);
      if (minHeap.size() > maxHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }
    }
  }

  double findMedian() {
    return maxHeap.size() == minHeap.size()
        ? (maxHeap.top() + minHeap.top()) / 2.0
        : maxHeap.top();
  }
};
