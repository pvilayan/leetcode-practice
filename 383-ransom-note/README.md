# 383. Ransom Note

## 🧠 Intuition  
My first thought was to count how many times each letter appears in the `ransomNote`, and then check if the `magazine` contains enough of each required letter. A hash map makes this process efficient.

## 🔍 Approach  
1. Count the frequency of each character in `ransomNote` using a hash map  
2. Loop through `magazine`, and subtract each character from the map  
3. After processing, if any character count is still ≥ 1, return `false`  
4. If all counts are ≤ 0, return `true`

## ⏱️ Complexity  
- **Time complexity:** O(n + m)  
  n = length of `ransomNote`, m = length of `magazine`  
- **Space complexity:** O(1)  
  The map only stores lowercase letters, so the size is constant

## 💻 Code  
See [`solution.cpp`](./solution.cpp)
