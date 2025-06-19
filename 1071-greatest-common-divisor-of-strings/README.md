# 🧠 Problem Summary
Given two strings `str1` and `str2`, return the **largest string `x`** such that:
- `x` divides both `str1` and `str2`
- That means `str1 = x + x + ...` and `str2 = x + x + ...`

If no such string exists, return `""`.

---

# ✅ Final Solution

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Step 1: If str1 + str2 != str2 + str1, they can't have a common base string
        if (str1 + str2 != str2 + str1) {
            return "";
        } else {
            // Step 2: Find the greatest common divisor of the lengths
            int len = gcd(str1.length(), str2.length());

            // Step 3: Return the substring of length 'len' from the beginning of str1
            return str1.substr(0, len);
        }
    }
};
```

# 💡 Key Concepts Used
1. gcd(a, b) gives the largest length that can divide both strings evenly.

2. If str1 + str2 != str2 + str1, then no common base substring is possible.

2. substr(0, len) is used to extract the potential base string.

# ❌ Mistakes I Made Earlier

1. Tried using unordered_map to count character frequencies.

   -❗ GCD of strings is about patterns, not individual characters.

2. Two strings can have the same characters but not be divisible (e.g., "AB" and "BA").

3. Tried using ASCII math (int conversion and division).

   -❗ ASCII math doesn’t capture repeated string structure and breaks the logic.

4. Thought GCD would return wrong value.

   -❗ GCD gives the maximum possible length of a valid repeating unit, not just any matching prefix.


# 🧪 Test Case Examples
```

1. str1 = "ABCABC", str2 = "ABC" → Output: "ABC"

2. str1 = "ABABAB", str2 = "ABAB" → Output: "AB"

3. str1 = "LEET", str2 = "CODE" → Output: ""

4. str1 = "ABABA", str2 = "ABA" → Output: "" (not evenly divisible)

```
# 🧠 Takeaway
Don't overcomplicate string problems with frequency or ASCII unless it's clearly character-count-related. Sometimes math + string functions (gcd, substr) solve it more cleanly and efficiently
