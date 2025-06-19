# LeetCode Problem: Merge Strings Alternately (Problem 1768)

## 📝 Problem Description

Given two strings `word1` and `word2`, merge them by alternating characters from each string. Start with the first character of `word1`, then the first character of `word2`, and so on. If one string is longer than the other, append the remaining characters to the end of the merged string.

---

## ❗ My Initial Solution (Using `vector<char>`)

```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        vector<char> merged_total;
        int min_length = min(word1.length(), word2.length());

        // Alternating characters
        for (int i = 0; i < min_length; i++) {
            merged_total.push_back(word1[i]);
            merged_total.push_back(word2[i]);
        }

        // Remaining characters from word1
        for (int i = min_length; i < word1.length(); i++) {
            merged_total.push_back(word1[i]);
        }

        // Remaining characters from word2
        for (int i = min_length; i < word2.length(); i++) {
            merged_total.push_back(word2[i]);
        }

        // Convert to string and return
        string result(merged_total.begin(), merged_total.end());
        return result;
    }
};
```

❌ Issues in Early Versions
Used a global vector which persisted across test cases in LeetCode.

Overused multiple vectors (merged1, merged2) when only one was needed.

Incorrect indexing with i + 2 caused skipped or out-of-bound characters.

Redundant length checks inside the loop — should have been handled after the main merging.

✅ Final Optimized Solution (Using string)
```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;

        // Loop until both strings are fully processed
        while (i < word1.length() || j < word2.length()) {
            if (i < word1.length()) result += word1[i++];
            if (j < word2.length()) result += word2[j++];
        }

        return result;
    }
};
✅ Why the Optimized Version is Better
No extra memory used for vectors — just one string result.

Handles unequal string lengths smoothly with simple conditionals.

Shorter, cleaner, and easier to read.

Avoids scope or memory issues common with global vectors in LeetCode.

# 🧠 Takeaway
When solving string manipulation problems:

Favor simplicity when possible.

Avoid global variables in online judges like LeetCode.

Think about how the loop will behave with different input lengths.

📚 Time and Space Complexity
Time Complexity: O(n + m), where n = word1.length() and m = word2.length()

Space Complexity: O(n + m) for the result string

