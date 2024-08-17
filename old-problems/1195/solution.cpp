#include <condition_variable>
#include <functional>
#include <mutex>

class FizzBuzz {
 private:
  std::mutex mtx;
  std::condition_variable cv;

  int i;
  int n;

 public:
  FizzBuzz(int n) : mtx{}, cv{}, i{1}, n(n) {}

  void fizz(std::function<void()> printFizz) {
    std::unique_lock<std::mutex> lock(mtx);
    while (i <= n) {
      while (i <= n && (i % 3 != 0 || i % 5 == 0)) cv.wait(lock);
      if (i > n) continue;
      printFizz();
      ++i;
      cv.notify_all();
    }
  }

  void buzz(std::function<void()> printBuzz) {
    std::unique_lock<std::mutex> lock(mtx);
    while (i <= n) {
      while (i <= n && (i % 3 == 0 || i % 5 != 0)) cv.wait(lock);
      if (i > n) continue;
      printBuzz();
      ++i;
      cv.notify_all();
    }
  }

  void fizzbuzz(std::function<void()> printFizzBuzz) {
    std::unique_lock<std::mutex> lock(mtx);
    while (i <= n) {
      while (i <= n && (i % 3 != 0 || i % 5 != 0)) cv.wait(lock);
      if (i > n) continue;
      printFizzBuzz();
      ++i;
      cv.notify_all();
    }
  }

  void number(std::function<void(int)> printNumber) {
    std::unique_lock<std::mutex> lock(mtx);
    while (i <= n) {
      while (i <= n && (i % 3 == 0 || i % 5 == 0)) cv.wait(lock);
      if (i > n) continue;
      printNumber(i);
      ++i;
      cv.notify_all();
    }
  }
};
