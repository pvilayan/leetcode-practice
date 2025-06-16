class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>frequency;
        for (char c : ransomNote){
            frequency[c]++;
        }

        for (char c : magazine){
            frequency[c]--;
    }

    for (auto pair: frequency){
        if (pair.second >= 1){
            return false;
        }
        
    }

    return true;
    }
};
