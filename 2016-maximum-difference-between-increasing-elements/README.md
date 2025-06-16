# 2016. Maximum Difference Between Increasing Elements

## 🧠 Intuition  
My first thought was to compare every pair of elements where the second element comes after the first.  
If the first element is smaller, I compute the difference and keep track of the maximum.

## 🔍 Approach  
- Use two nested loops:  
  - Outer loop picks the second element (`nums[j]`)  
  - Inner loop checks all previous elements (`nums[i]`) before `j`  
  - If `nums[i] < nums[j]`, calculate the difference and update `max_diff` if it's larger  
- If no such increasing pair exists, return `-1`.

## ⏱️ Complexity  
- **Time complexity:** O(n²)  
  We check all possible pairs using nested loops.  
- **Space complexity:** O(1)  
  Only a few variables are used for tracking the result.

## 💻 Code  
See [`solution.cpp`](./solution.cpp)

  
