#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::string> findAllRecipes(
      std::vector<std::string>& recipes,
      std::vector<std::vector<std::string>>& ingredients,
      std::vector<std::string>& supplies) {
    std::unordered_map<std::string, std::size_t> recipeIndices{};
    for (std::size_t i{0}; i < recipes.size(); ++i) {
      recipeIndices.emplace(recipes[i], i);
    }

    std::unordered_map<std::string, bool> memo{};
    for (const std::string& supply : supplies) {
      memo.emplace(supply, true);
    }

    std::vector<std::string> output{};
    for (const std::string& recipe : recipes) {
      if (canCreate(recipe, recipeIndices, ingredients, memo)) {
        output.push_back(recipe);
      }
    }

    return output;
  }

  bool canCreate(
      const std::string& recipe,
      std::unordered_map<std::string, std::size_t>& recipeIndices,
      const std::vector<std::vector<std::string>>& ingredients,
      std::unordered_map<std::string, bool>& memo) {
    auto memoIt = memo.find(recipe);
    if (memoIt != memo.end()) {
      return memoIt->second;
    }

    const auto it = recipeIndices.find(recipe);
    if (it == recipeIndices.end()) {
      memo.emplace(recipe, false);
      return false;
    }

    memoIt = memo.emplace(recipe, false).first;
    for (const std::string& ingredient : ingredients[it->second]) {
      if (!canCreate(ingredient, recipeIndices, ingredients, memo)) {
        memo.emplace(recipe, false);
        return false;
      }
    }

    memoIt->second = true;
    return true;
  }
};
