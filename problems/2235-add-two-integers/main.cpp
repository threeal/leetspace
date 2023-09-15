#include <cassert>

#include "solution.cpp"

int main() {
    Solution solution;
    assert(solution.sum(12, 5) == 17);
    assert(solution.sum(-10, 4) == -6);
}
