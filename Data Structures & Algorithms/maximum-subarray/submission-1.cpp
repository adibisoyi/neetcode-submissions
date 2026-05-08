class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0],sum=0;

        for(int num:nums)
        {
            if(sum<0)
                sum=0;
            sum += num;
            maxsum = max(maxsum,sum);

        }
        return maxsum;
    }
};
