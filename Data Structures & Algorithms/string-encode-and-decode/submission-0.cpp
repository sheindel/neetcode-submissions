#include <cassert>

class Solution {
public:

    string encode(vector<string>& strs) {
        // our delimeter between word size and word will be a ;
        // at the start of the sentence, we will put the total 
        // number of words, and a semicolon, and then the next number
        // before a semicolon will be the next word length. We will then
        // read the string for that length to get the word, and then
        // get the next word length. the total number of words will be a 
        // crude way to ensure we read the string correctly.
        stringstream ss;
        vector<int> lengths;

        ss << strs.size() << ";";
        for (auto& inputString : strs) {
            ss << inputString.size() << ";" << inputString;
        }

        return ss.str();
    }

    vector<string> decode(string s) {
        int totalWords = 0;
        string buffer = "";
        int readMarker = 0;

        // read the number of words
        while (readMarker < s.size()) {
            // read and iterate after reading
            auto nextChar = s[readMarker++];
            if (nextChar == ';') { // we found the first delimeter
                totalWords = stoi(buffer);
                buffer = "";
                break;
            } else {
                buffer += nextChar;
            }
        }

        std::cout << "We got a buffer with " << totalWords << " words" << endl;

        buffer = "";
        int wordLength = -1;

        vector<string> words;
        
        // read the number of words, readMarker is where we left off
        while (readMarker < s.size()) {
            auto nextChar = s[readMarker++];
            if (nextChar == ';') { // we found the first delimeter
                wordLength = stoi(buffer);
                words.push_back(std::string(s.begin() + readMarker, s.begin() + readMarker + wordLength));
                readMarker += wordLength;
                buffer = "";
                wordLength = -1;
            } else {
                buffer += nextChar;
            }
            std::cout << "buffer=" << buffer << endl;
        }

        return words;
    }
};
