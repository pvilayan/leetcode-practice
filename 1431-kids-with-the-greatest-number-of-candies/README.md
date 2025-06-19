# 🍭 LeetCode Problem: Kids With the Greatest Number of Candies (Problem 1431)

## 🧠 Problem Summary

You're given an array `candies` where `candies[i]` represents how many candies the `i`-th kid has. You also have an integer `extraCandies`.

For each kid, determine if giving them **all the extraCandies** would make them have the **greatest or equal to the greatest number** of candies among all kids.

Return a boolean array where each element is `true` if the kid **could have the most candies**, and `false` otherwise.

---

## ✅ Final Working Code

```cpp
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> candies_amount;
        int max_candies = *max_element(candies.begin(), candies.end());  // ✅ Find the current max first

        for (int i = 0; i < candies.size(); i++) {
            // ✅ Check if current kid's total with extra is >= max
            if (candies[i] + extraCandies >= max_candies) {
                candies_amount.push_back(true);
            } else {
                candies_amount.push_back(false);
            }
        }

        return candies_amount;
    }
};

```

# ❌ Mistake I Made


1. Calculated max_element inside the loop
```
int max_candies = *max_element(candies_amount.begin(), candies_amount.end());  // ❌
```
2. candies_amount is empty at the start, leading to undefined behavior and runtime error.

3. Used the wrong vector to find max
   - candies_amount is a vector of bool values, not the actual candy counts.

4. You should find the max from candies, which contains the actual data.


# 📌 Key Concepts
max_element(begin, end) returns an iterator, so we use * to dereference it.

vector<bool> uses bit-packing internally, so incorrect access (like pushing wrong types) can cause errors.

Always find max once before the loop to avoid unnecessary computation.


# 🧪 Sample Test Case

Input:  candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]

# 🧠 Time and Space Complexity
Time: O(n) — one pass to find max, one pass to compare each kid.
Space: O(n) — for the result vector.

# ✅ Takeaway
This problem shows how careful attention to vector usage, loop design, and STL functions (like max_element) helps write cleaner, safer, and more efficient C++ code.
