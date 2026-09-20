#include <bit>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        int bits = std::bit_width(n);
        cout << n << endl;
        for (int i = 0; i < bits; i++) {
            // check if the bit in the 0th position is a 1 now
            if (n & 0b1) {
                sum += 1;
            }

            // shift n down by 1 bit
            n>>=1;
            cout << n << endl;
        }
        return sum;
    }
};
