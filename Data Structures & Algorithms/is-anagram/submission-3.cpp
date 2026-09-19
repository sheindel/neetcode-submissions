class Solution {
public:
    void printSet(std::set<char> set) {
        for (const auto& character : set) {
            std::cout << character << ",";
        }
        std::cout << std::endl;
    }
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            std::cout << "Strings don't match in size, not anagrams" << std::endl;
            return false;
        }

        std::unordered_map<char, int> map;

        // std::sort(s.begin(), s.end());
        // std::sort(t.begin(), t.end());

        auto sPointer = s.begin();
        auto tPointer = t.begin();
        while (sPointer < s.end()) {
            // if (*sPointer != *tPointer) {
            //     return false;
            // }
            const auto sValue = *sPointer;
            if (!map.contains(sValue)) {
                map[sValue] = 0;
            }

            map[sValue]++;

            const auto tValue = *tPointer;
            if (!map.contains(tValue)) {
                map[tValue] = 0;
            }
            map[tValue]--;
            sPointer = std::next(sPointer);
            tPointer = std::next(tPointer);
        }
        for (const auto [character, count]: map) {
            if (count != 0) {
                return false;
            }
        }
        return true;

        // palindrome check.... duh
        // auto sPointer = s.begin();
        // auto tPointer = std::prev(t.end());

        // // since we know both are the same length, we can just track s
        // while (sPointer < s.end()) {
        //     std::cout << *sPointer << "," << *tPointer << std::endl;
        //     // if our characters ever don't match, not an anagram
        //     if (*sPointer != *tPointer) {
        //         return false;
        //     }

        //     sPointer = std::next(sPointer);
        //     tPointer = std::prev(tPointer);
        // }

        // return true;
    }
};
