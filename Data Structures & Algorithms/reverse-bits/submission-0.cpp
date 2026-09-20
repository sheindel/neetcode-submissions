class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        auto bits = 32; //bit_width(n);
        std::cout << "n=" << n << ",bit width=" << bits << endl;
        int result = 0;
        int upperBitMarker = bits - 1;
        int lowerBitMarker = 0;
        for (int i = 0; i < bits / 2; i++) {
            // save upper bit
            int upperBit = 0b1 & (n >> upperBitMarker);
            int lowerBit = 0b1 & (n >> lowerBitMarker);
            cout << "upperBit=" << upperBit << ",lowerBit=" << lowerBit << ",i=" << i << endl;

            result |= (upperBit << lowerBitMarker);
            result |= (lowerBit << upperBitMarker);
            upperBitMarker--;
            lowerBitMarker++;
        }

        return result;
    }
};
