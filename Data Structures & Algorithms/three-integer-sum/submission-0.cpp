#include <algorithm>
#include <tuple>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::set<std::vector<int>> solutions;

        // sort the input array
        std::sort(nums.begin(), nums.end());

        // Start with a single value. We will only go up to list end -2 
        // to account for the two pointers
        for (auto it = nums.begin(); it < nums.end()-2; it++) {
            // the lower pointer starts right after the start value
            auto lower = it + 1;

            // the upper pointer will always start at the end of the list
            auto upper = nums.end() - 1;
            while (lower < upper) {
                const auto currentValue = *it + *lower + *upper;
                if (currentValue == 0) {
                    solutions.insert({ *it, *lower, *upper });
                    // if we have a solution, let's arbitrarily move the upper in
                    upper--;
                } else if (currentValue > 0) {
                    // we need a lower value, so reduce upper
                    upper--;
                } else if (currentValue < 0) {
                    // we need a higher value, move the lower up
                    lower++;
                }
            }
        }

        std::vector<std::vector<int>> result(solutions.begin(), solutions.end());
        return result;
    }
};
