class Solution {
public:
    int search(vector<int>& nums, int target) {
        // x x x x x
        // l       h
        // 0       4
        // (4 - 0) / 2 = 2
        // x x x x x
        // l   ^   h
        //     
        // > pointer?
        // low becomes pointer
        // less than pointer?
        // high becomes pointer
        // 
        // x x x x x
        //     l   h
        //     2 ^ 4
        // less than pointer?
        //
        // x x x x x
        //       l h
        //       ^ 4


        // x x x x x x
        // l         h
        // 

        if (nums.size() == 0) { 
            return -1;
        }

        if (nums.size() == 1) {
            return target == nums[0] ? 0 : -1;
        }

        int left = 0;
        int right = nums.size() - 1;
        // std::cout << "left=" << left << ",right=" << right << std::endl;
        int count = 100;
        while (left <= right and (count-->0)) {
            int pointerOffset = (right - left) / 2;
            int pointer = left + pointerOffset;
            // std::cout << "left=" << left << ",right=" << right << ",pointer=" << pointer << std::endl;
            if (pointer < 0 || pointer >= nums.size()) {
                // std::cout << pointer << std::endl;
                return -1;
                //throw new invalid_argument("Error! impossible pointer!");
            }
            auto number = nums[pointer];
            // std::cout << "left=" << left << ",right=" << right << ",pointer=" << pointer << ",number=" << number << std::endl;

            if (number == target) {
                return pointer;
            }

            if (number > target) {
                right = pointer - 1;
            }

            if (number < target) {
                left = pointer + 1;
            }
        }

        return -1;
    }
};
