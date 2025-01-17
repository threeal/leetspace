#include <algorithm>
#include <vector>

class Solution {
 public:
  int largestValsFromLabels(
      std::vector<int>& values, std::vector<int>& labels,
      int numWanted, int useLimit) {
    std::vector<int> indexes(values.size());
    for (int i = values.size() - 1; i >= 0; --i) {
      indexes[i] = i;
    }

    auto valuesData = values.data();
    auto labelsData = labels.data();
    std::sort(
        indexes.begin(), indexes.end(),
        [valuesData, labelsData](int a, int b) {
          return labelsData[a] == labelsData[b]
              ? valuesData[a] < valuesData[b]
              : labelsData[a] < labelsData[b];
        });

    auto label = labelsData[indexes.back()];
    auto count = useLimit - 1;
    for (int i = indexes.size() - 2; i >= 0; --i) {
      if (labels[indexes[i]] == label) {
        if (count > 0) {
          --count;
        } else {
          valuesData[indexes[i]] = -1;
        }
      } else {
        label = labelsData[indexes[i]];
        count = useLimit - 1;
      }
    }

    std::sort(values.begin(), values.end());

    int sum{0};
    for (int i = values.size() - 1; numWanted > 0; --i, --numWanted) {
      if (valuesData[i] < 0) break;
      sum += valuesData[i];
    }

    return sum;
  }
};
