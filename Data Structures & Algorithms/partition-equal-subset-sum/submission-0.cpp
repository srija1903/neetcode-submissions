class Solution {
public:
    bool subSetSum(vector<int>& nums, int sum,int size)
    {
        if(sum == 0)
            return true;
        
        if(size == 0 && sum > 0)
            return false;

        if(nums[size - 1] <= sum)
            return subSetSum(nums,sum-nums[size - 1],size -1) || subSetSum(nums,sum,size-1);
        else
            return subSetSum(nums,sum,size-1);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];

        if(sum%2 != 0)
            return false;
        else
        {
            return subSetSum(nums,sum/2,nums.size());
        }   
    }
};
