// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

std::vector<std::string> startFizzBuzz(int n) {
  FizzBuzz fizzBuzz(n);

  std::mutex mutex;
  std::vector<std::string> output{};
  std::thread fizzThread(&FizzBuzz::fizz, &fizzBuzz, [&]() {
    std::lock_guard lock(mutex);
    output.push_back("fizz");
  });
  std::thread buzzThread(&FizzBuzz::buzz, &fizzBuzz, [&]() {
    std::lock_guard lock(mutex);
    output.push_back("buzz");
  });
  std::thread fizzbuzzThread(&FizzBuzz::fizzbuzz, &fizzBuzz, [&]() {
    std::lock_guard lock(mutex);
    output.push_back("fizzbuzz");
  });
  std::thread numberThread(&FizzBuzz::number, &fizzBuzz, [&](int number) {
    std::lock_guard lock(mutex);
    output.push_back(std::to_string(number));
  });

  fizzThread.join();
  buzzThread.join();
  fizzbuzzThread.join();
  numberThread.join();

  std::lock_guard lock(mutex);
  return output;
}

TEST_CASE("1195. Fizz Buzz Multithreaded") {
  SECTION("Example 1") {
    const auto actual = startFizzBuzz(15);
    const std::vector<std::string> expected{
        "1", "2", "fizz", "4", "buzz", "fizz", "7", "8", "fizz", "buzz",
        "11", "fizz", "13", "14", "fizzbuzz"};
    REQUIRE(expected == actual);
  }

  SECTION("Example 1") {
    const auto actual = startFizzBuzz(5);
    const std::vector<std::string> expected{"1", "2", "fizz", "4", "buzz"};
    REQUIRE(expected == actual);
  }
}
