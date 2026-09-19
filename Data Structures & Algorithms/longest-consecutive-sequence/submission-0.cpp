#include <map>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> hashedNums;

        // O(n) complexity, most likely (assuming minimal collisions)
        for (auto& num : nums) {
            hashedNums[num] = 0;
        }

        // check every value in the array to see if it's a start sequence, O(n)
        std::vector<int> startNumbers;
        for (auto const& hashedNum: hashedNums) {
            // if the previous value is in the array...
            if (!hashedNums.contains(hashedNum.first - 1)) {
                startNumbers.push_back(hashedNum.first);
            }
        }

        // Now we take our start sequences and we look for the longest chains
        int maxSequenceLength = 0;
        int maxStartNumber = 0;
        for (auto& startNumber : startNumbers) {
            // check for the next sequence value. Keep iterating as long as we keep finding it
            int currentSequenceLength = 0;
            while (hashedNums.contains(startNumber + currentSequenceLength)) {
                // if the next value doesn't exist, start the next sequence
                currentSequenceLength++;
                if (currentSequenceLength > maxSequenceLength) {
                    maxSequenceLength = currentSequenceLength;
                    maxStartNumber = startNumber;
                }
                continue;
            }
        }

        return maxSequenceLength;
    }
};
