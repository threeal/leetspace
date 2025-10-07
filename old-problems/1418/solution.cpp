#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> displayTable(
      std::vector<std::vector<std::string>>& orders) {
    std::unordered_map<int, std::unordered_map<std::string_view, int>>
        tableOrders{};

    std::set<int> tableNums{};
    std::set<std::string_view> foods{};

    for (const auto& order : orders) {
      int tableNum{std::stoi(order[1])};
      ++tableOrders[tableNum][order[2]];
      tableNums.insert(tableNum);
      foods.insert(order[2]);
    }

    std::vector<std::vector<std::string>> display(
        tableNums.size() + 1, std::vector<std::string>(foods.size() + 1));

    display[0][0] = "Table";

    std::size_t j{0};
    for (const auto& food : foods) {
      display[0][++j] = food;
    }

    std::size_t i{0};
    for (const auto& tableNum : tableNums) {
      display[++i][0] = std::to_string(tableNum);

      std::size_t j{0};
      const auto& tableOrder = tableOrders[tableNum];
      for (const auto& food : foods) {
        const auto it = tableOrder.find(food);
        display[i][++j] = it != tableOrder.end()
            ? std::to_string(it->second)
            : "0";
      }
    }

    return display;
  }
};
