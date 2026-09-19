#include <map>

using FreqMap = array<int, 26>;

class Solution {
public:
    // int calculateAnagramHash(std::string word) {
    //     // store word size in the upper 8 bits
    //     // covers words up to 255, which is a big word
    //     // (upper bound is actually 100)
    //     int hash = word.size() << 24;
    //     std::unordered_map<char, int> occurrences;
    //     for (auto character: word) {
    //         if (!occurrences.contains(character)) {
    //             occurrences[character] = 0;
    //         }
    //         auto occurrence = ++occurrences[character];

    //         hash += (character*occurrence);
    //     }
    //     return hash;
    // }

    FreqMap getAnagramKey(string word) {
        FreqMap key{};
        for (auto character: word) {
            key[character - 'a']++;
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<FreqMap, vector<string>> anagrams;
        for (const auto& word : strs) {
            // int hash = calculateAnagramHash(word);
            FreqMap freqMap = getAnagramKey(word);

            anagrams[freqMap].push_back(word);
        }

        vector<vector<string>> result;
        for (const auto [freqMap, words]: anagrams) {
            result.push_back(words);
        }
        return result;
    }
};