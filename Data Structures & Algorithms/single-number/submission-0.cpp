#include <cassert>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 0b0000 0011
        // 0b0000 0010
        // 0b0000 0011

        // 0b0000 0111
        // 0b0000 0110
        // 0b0000 0110
        // 0b0000 0111
        // 0b0000 1000

        assert(nums.size() > 0);

        int xorValue = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            xorValue ^= nums[i];
        }

        return xorValue;
    }
};
