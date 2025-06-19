## Merge Strings Alternately - LeetCode 1768

# Problem Description

Given two strings word1 and word2, merge them by alternating characters from each string one by one. If one string is longer than the other, append the remaining characters of the longer string to the merged result.

Example:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"

My Initial Solution (Using vector<char>)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        vector<char> merged_total;
        int min_length = min(word1.length(), word2.length());

        // Alternating characters from both words
        for (int i = 0; i < min_length; i++) {
            merged_total.push_back(word1[i]);
            merged_total.push_back(word2[i]);
        }

        // Append remaining characters from word1
        for (int i = min_length; i < word1.length(); i++) {
            merged_total.push_back(word1[i]);
        }

        // Append remaining characters from word2
        for (int i = min_length; i < word2.length(); i++) {
            merged_total.push_back(word2[i]);
        }

        // Convert vector<char> to string
        string result(merged_total.begin(), merged_total.end());
        return result;
    }
};

Issues with This Version

Declared multiple vectors (merged_total, merged1, merged2) in earlier attempts — overcomplicated the logic.

Tried using i + 2 to get remaining characters — caused incorrect indexing and skipped letters.

Originally used a class-level vector<char> — led to bugs in LeetCode's multiple test case environment.

Final Optimized Solution (Using string)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;

        while (i < word1.length() || j < word2.length()) {
            if (i < word1.length()) result += word1[i++];
            if (j < word2.length()) result += word2[j++];
        }

        return result;
    }
};

Why This Version is Better

No need for extra vectors.

Uses one loop to handle both alternating and remaining characters.

Clean, short, and easy to read.

Safer for multiple test cases in LeetCode.

Time and Space Complexity

Time Complexity: O(n + m), where n is the length of word1 and m is the length of word2.

Space Complexity: O(n + m) for the final result string.

Takeaway

For string merging problems, using just a string and managing indices directly often results in simpler, safer, and more efficient code.
