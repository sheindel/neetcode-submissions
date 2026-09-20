class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalSum = 1;
        int zeroCount = 0;
        for (int num: nums) {
            if (num != 0) {
                totalSum *= num;
            } else {
                zeroCount++;
            }
        }

        std::cout << "totalSum=" << totalSum << endl;

        vector<int> result;
        for (int num: nums) {
            if (num == 0) {
                if (zeroCount == 1) {
                    result.push_back(totalSum);
                } else {
                    result.push_back(0);
                }
            } else {
                if (zeroCount > 0) {
                    result.push_back(0);
                } else {
                    result.push_back(totalSum / num);
                }
            }
        }

        return result;
    }
};
