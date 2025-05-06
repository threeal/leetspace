#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> validStrings(int n) {
    std::vector<std::string> output{};

    std::string str(n, '0');
    generate(output, str, 1);

    str[0] = '1';
    generate(output, str, 1);

    return output;
  }

 private:
  static void generate(
      std::vector<std::string>& output, std::string& str, std::size_t i) {
    if (i == str.size()) {
      output.push_back(str);
    } else {
      if (str[i - 1] == '1') {
        str[i] = '0';
        generate(output, str, i + 1);
      }

      str[i] = '1';
      generate(output, str, i + 1);
    }
  };
};
