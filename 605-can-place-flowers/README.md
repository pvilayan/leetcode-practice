# 🌼 LeetCode 605: Can Place Flowers

## 📘 Problem Description

You have a long flowerbed in which some plots are planted and others are not.  
However, flowers **cannot be planted in adjacent plots**.

Given:
- An integer array `flowerbed` containing 0's and 1's:
  - `0` → empty plot
  - `1` → already planted
- An integer `n` → number of flowers you need to plant

Return `true` if `n` new flowers can be planted without violating the rule.

---

## 💡 Example

### Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

shell
Copy
Edit

### Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

---

## ✅ Final C++ Solution

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;

        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {

                flowerbed[i] = 1;
                count++;
            }
        }

        return count >= n;
    }
};
```

# ⚠️ Mistakes I Made Initially

❌ 1. Array Index Out of Bounds
I tried accessing flowerbed[i - 1] and flowerbed[i + 1] without checking if i is at the edge.

✅ Fix:
Used short-circuit logic:
```
(i == 0 || flowerbed[i - 1] == 0)
(i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)
```

# 🧠 Key Concepts

1. Short-circuit logic protects against accessing out-of-bounds elements.
2. Plant only if current plot is 0, and both neighbors are also 0 or don't exist.
3. Increment count every time a flower is planted.
4. Final return checks if count >= n.

# ⏱️ Time & Space Complexity

1. Time Complexity: O(n)
2. Space Complexity: O(1)

# 🧪 Edge Cases to Test

Test Case	Expected Output:
1. [0, 0, 0, 0, 0], n = 2	true
2. [1, 0, 0, 0, 1], n = 2	false
3. [1, 1, 1, 1], n = 1	false
4. [1, 0, 1, 0, 1], n = 0	true
5. [0], n = 1	true

# ✍️ Author Notes

This problem helped me understand:

1. Safe edge handling in arrays
2. Importance of short-circuiting in C++
3. Efficient greedy placement logic
