class Solution {
public:
    void printArray(std::span<int> s, std::string debug) {
        std::cout << debug << " - ";
        for (auto n: s) {
            std::cout << n;
        }
        std::cout << std::endl;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // [ ]++
        // [ ]++
        // [ ]++
        // [ ]++

        // idea 1: if frequency list is *mostly* sorted, we can do insert sort operation on 
        // the element we just touched by comparing it the value above it
        // then at the end, we have a sorted list of the most frequent and the answer lookup
        // is O(1)
        // problem is that insertion sorts will take something between O(1) O(n) every time we 
        // insert a value, and as the frequency list grows, this likely approachs O(log n) operations
        // possibly an ordered map, being a red black tree, could solve this somehow? 
        // but its insertion is also not guaranteed to be O(1), so this still adds complexity

        // naive solution
        // key is number in list, value is occurrence



        unordered_map<int, int> frequency;
        for (const auto& number : nums) {
            frequency[number]++; // TODO look up the assertion that the [] operator initializes a value...
        }

        std::vector<std::vector<int>> occurrences(nums.size()+1);
        for (const auto& [number, occurrence]: frequency) {
            occurrences[occurrence].push_back(number);
        }

        auto kCounter = k;
        std::vector<int> answer;
        for (auto it = std::prev(occurrences.end()); it >= occurrences.begin(); it = std::prev(it)) {
            auto numbersAtOccurrence = *it;
            if (numbersAtOccurrence.size() != 0) {
                // std::cout << "Occurred " << (it - occurrences.begin()) << " times";
                // printArray(numbersAtOccurrence, "");
                kCounter -= numbersAtOccurrence.size();
                answer.insert(answer.begin(), numbersAtOccurrence.begin(), numbersAtOccurrence.end());
                if (kCounter == 0) {
                    break;
                }
            }
        }

        return answer;

        // // convert map to vector
        // std::vector<std::pair<int, int>> result(frequency.begin(), frequency.end());
        // std::sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
        //     return a.second > b.second;
        // });
        // auto kMostFrequent = std::vector<std::pair<int, int>>(result.begin(), result.begin() + k);
        // vector<int> result2;
        // std::transform(kMostFrequent.begin(), kMostFrequent.end(), std::back_inserter(result2), [](const auto& valueFrequency) {
        //     return valueFrequency.first;
        // });
        // return result2;
    }
};
