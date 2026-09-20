class Solution {
public:
    int getSum(int a, int b) {
        // 0b0010
        // 0b0110
        // 
        // 0b0100 xor
        // 0b0110 or
        // 0b0010 and
        // 
        // 0b1000 actual result
        // 
        // 0b0000 0101
        // 0b0000 0100
        // 0b0000 1001
        int result = 0;
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            int tempA = (a >> i) & 0x1;
            int tempB = (b >> i) & 0x1;
            int axorb = (tempA ^ tempB ^ carry);

            result |= (axorb << i);
            carry = (tempA and tempB) or (tempB and carry) or (tempA and carry);
            std::cout << "a=" << tempA << ",b=" << tempB << ",carry=" << carry << endl;
        }
        return result;
    }
};
