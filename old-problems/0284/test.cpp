#include <vector>

class Iterator {
 private:
  const std::vector<int> nums;
  std::size_t i;

 public:
  Iterator(const std::vector<int>& nums) : nums{nums}, i{0} {};

  int next() {
    return nums[i++];
  }

  bool hasNext() const {
    return i < nums.size();
  }
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("284. Peeking Iterator") {
  SECTION("Example 1") {
    PeekingIterator it({1, 2, 3});
    REQUIRE(it.next() == 1);
    REQUIRE(it.peek() == 2);
    REQUIRE(it.next() == 2);
    REQUIRE(it.next() == 3);
    REQUIRE_FALSE(it.hasNext());
  }
}
