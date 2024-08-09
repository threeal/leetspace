#include <functional>

class FizzBuzz {
 public:
  FizzBuzz(int /*n*/) {}

  void fizz(std::function<void()> printFizz) {
    printFizz();
  }

  void buzz(std::function<void()> printBuzz) {
    printBuzz();
  }

  void fizzbuzz(std::function<void()> printFizzBuzz) {
    printFizzBuzz();
  }

  void number(std::function<void(int)> printNumber) {
    printNumber(1);
  }
};
