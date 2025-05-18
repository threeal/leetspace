#include <vector>

class Solution {
 public:
  std::vector<int> processQueries(std::vector<int>& queries, int m) {
    std::vector<int> tree(queries.size() + m + 1, 0);
    std::vector<int> map(m + 1);
    for (int i{1}; i <= m; ++i) {
      update(tree, queries.size() + i, 1);
      map[i] = queries.size() + i;
    }

    std::vector<int> output(queries.size());
    for (std::size_t i{0}; i < queries.size(); ++i) {
      output[i] = query(tree, map[queries[i]] - 1);
      update(tree, map[queries[i]], -1);
      update(tree, queries.size() - i, 1);
      map[queries[i]] = queries.size() - i;
    }

    return output;
  }

 private:
  static void update(std::vector<int>& tree, int i, int delta) {
    const int n = tree.size();
    while (i < n) {
      tree[i] += delta;
      i += i & -i;
    }
  }

  static int query(std::vector<int>& tree, int i) {
    int sum{0};
    while (i > 0) {
      sum += tree[i];
      i -= i & -i;
    }
    return sum;
  }
};
