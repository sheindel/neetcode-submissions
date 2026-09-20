#include <bit>

class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> result;

        for (uint i = 0; i <= n; i++) {
            result.push_back(std::popcount(i));
        }
        return result;
    }
};
