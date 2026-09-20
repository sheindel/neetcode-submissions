#include <cassert>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        assert(nums.size() > 0);
        
        // vector<int> newNums = {
        //     0, 1, 2, 3, 4, 5, 7, 8, 6, 9
        // };

        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            result ^= nums[i];
        }

        for (int i = 0; i < nums.size()+1; i++) {
            result ^= i;
        }

        std::cout << result << std::endl;

        return result;
    }
};
