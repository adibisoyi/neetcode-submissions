class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(),res = nums[0];

        for(int i=0;i<n;i++)
        {
            int cursum = 0;
            for(int j=i;j<i+n;j++)
            {
                cursum += nums[j%n];
                res = max(res,cursum);
            }
        }
        return res;
    
    }
};