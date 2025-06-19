# 🧪 Leetcode Problem: 345 - Reverse Vowels of a String

## 🧠 Problem Summary

Given a string `s`, reverse **only the vowels** in the string and return the modified string.

- Vowels are: `a`, `e`, `i`, `o`, `u` (case-insensitive).
- Constraints: `1 <= s.length <= 3 * 10⁵`

---

## ✅ Final Working Solution (Two-Pointer Approach)

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            while (i < j && !isVowel(s[i])) i++;
            while (i < j && !isVowel(s[j])) j--;

            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'A' ||
               c == 'e' || c == 'E' ||
               c == 'i' || c == 'I' ||
               c == 'o' || c == 'O' ||
               c == 'u' || c == 'U';
    }
};
```
# ❌ Mistakes I Made
1. ❗ Forgot to initialize vector<char> word with string contents
```
vector<char> word;  // ❌ this is empty
```
Fix:
```
vector<char> word(s.begin(), s.end());  // ✅ copies contents of s into vector
```

2. ❗ Used auto i = word.begin(); i != word.end(); i++ then word[i]
word[i] is incorrect here because i is already an iterator.

Fix:
```
for (auto it = word.begin(); it != word.end(); ++it) {
    if (*it == 'a' || ...)  // ✅ use *it, not word[i]
}
```

3. ❗ Tried to define left and right inside if-blocks — variables went out of scope
```
if (condition) {
    int left = i;  // ❌ will be lost after this block
}
swap(word[left], word[right]);  // ❌ left/right not defined here
```
Fix:
```
Declare left and right outside the loop first.
```

4. ❗ Tried using nested loops to track vowels from both sides, overcomplicated logic

Fix:
```

Used the two-pointer approach, which is simpler and cleaner:

1. Start from both ends

2. Move inward until both pointers hit vowels

3. Swap
```

# 🧩 Concept Behind Two-Pointer Swap

```
while (i < j && !isVowel(s[i])) i++;   // skip non-vowels from left
while (i < j && !isVowel(s[j])) j--;   // skip non-vowels from right

swap(s[i], s[j]);  // swap the vowels
This keeps everything in-place, efficient, and avoids creating extra vectors.

```
# 📝 What I Learned
1. Always make sure you know when you're working with iterators vs. indices.

2. Declare variables outside conditional blocks if you plan to use them later.

3. Built-in helper functions like tolower() and isalpha() can make checks easier.

4. Swapping is simpler when using two pointers instead of nested loops.

# 🔍 Sample Test Case
```
Input: "IceCreAm"
Vowels: I, e, e, A
Output: "AceCreIm"
```

# 🌟 Extra Tip
You can improve the vowel-checking logic like this:
```
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
```
