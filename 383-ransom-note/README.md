🧠 Intuition
I wanted to check if the magazine had enough of each letter needed in the ransom note. A hash map made it easy to track and compare frequencies.

🔍 Approach
Count how many times each letter appears in ransomNote using a hash map

Subtract the count using letters in magazine

If any count is still ≥ 1 after processing, return false

If all counts are ≤ 0, return true

⏱️ Complexity
Time: O(n + m) — n = ransomNote length, m = magazine length

Space: O(1) — Only lowercase letters, so map size stays constant

💻 Code
See solution.cpp in this folder.
