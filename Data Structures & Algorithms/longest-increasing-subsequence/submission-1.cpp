class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        std::vector<int> dp(n, 1);
        int maxLength = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Strictly less than: ignore equal elements
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            maxLength = std::max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
