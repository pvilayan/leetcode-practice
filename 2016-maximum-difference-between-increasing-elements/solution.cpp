class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_diff = -1;
        for (int j = 1; j<nums.size(); j++){
            for (int i = 0; i<j; i++){
                if(nums[i]<nums[j]){
                    max_diff = max(max_diff,nums[j] - nums[i]);

                }
                
            }
            
        }
        return max_diff;
    }
    
};
