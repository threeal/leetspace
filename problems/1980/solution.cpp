// The solution can be done as follows:
// - First, sort the binary numbers.
// - Declare a binary number 0 as an iterator.
// - For each binary number, compare it with the iterator.
// - If it is equal, increment the iterator; otherwise, return the iterator.

class Solution {
 public:
  string findDifferentBinaryString(vector<string>& nums) {
    // Sort the binary numbers.
    sort(nums.begin(), nums.end());

    // Declare a binary number 0 as an iterator.
    string res(nums.size(), '0');

    // For each binary number, compare it with the iterator.
    for (const auto& num : nums) {
      if (num != res) break;

      // Increment the iterator.
      auto c = res.rbegin();
      *c += 1;
      while (*c == '2') {
        *c = '0';
        ++c;
        *c += 1;
      }
    }

    return res;
  }
};
