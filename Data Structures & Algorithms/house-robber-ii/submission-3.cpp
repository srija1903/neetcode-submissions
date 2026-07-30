class Solution {
public:
    int findMaxSumCircle(vector<int>& nums, int i,int j)
    {
        vector<int> dp(j+1,0);
        dp[i] = nums[i];
        // For second house, we can either take
        // from 1st or 2nd.
        dp[i+1] = max(nums[i], nums[i+1]);
        for(int x=2;x<j+1;x++)
        {
            dp[x] = max(dp[x-2] + nums[x],dp[x-1]);
        }
        return dp[j];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) 
            return max(nums[0], nums[1]);
        if(n == 1)
            return nums[0];
        int ans = 0;
        // Starting from 0th index excluding the last house
        ans = max(ans,findMaxSumCircle(nums,0,n-2));
        // Starting from 1st index exluding the 1st house
        ans = max(ans,findMaxSumCircle(nums,1,n-1));

        return ans;
    }
};
