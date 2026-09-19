#include <algorithm>
#include <set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> numsSet(nums.begin(), nums.end());
        return numsSet.size() != nums.size();
    }
};