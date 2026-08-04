class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        vector<int> dp(nums.size()+1,0);
        int ans = nums[0];
        for(int i=1;i<nums.size()+1;i++)
        {
            dp[i] = max(nums[i-1] + dp[i-1],nums[i-1]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
