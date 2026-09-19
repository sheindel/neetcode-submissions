class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for (auto t1 = nums.begin(); t1 < std::prev(nums.end()); t1=std::next(t1)) {
            for (auto t2 = std::next(t1); t2 < nums.end(); t2=std::next(t2)) {
                const auto value = *t1 + *t2;
                if (value == target) {
                    return { static_cast<int>(t1 - nums.begin()), static_cast<int>(t2 - nums.begin()) };
                }
            }
        }
        // std::sort(nums.begin(), nums.end());
        
        // auto head = nums.begin();
        // auto tail = std::prev(nums.end());

        // while (head < tail) {
        //     const auto value = *head + *tail;
        //     if (value == target) {
        //         return {static_cast<int>(head - nums.begin()), static_cast<int>(tail - nums.begin())};
        //     }
        //     if (value > target) {
        //         tail = std::prev(tail);
        //     } else {
        //         head = std::next(head);
        //     }
        // }
        // return {};
    }
};
