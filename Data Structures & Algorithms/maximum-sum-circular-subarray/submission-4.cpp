class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        /*int n = nums.size(),res = nums[0];

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
        */

        int globmax = nums[0],globmin = nums[0], curmax =0, curmin =0, total =0;

        for(auto& num : nums)
        {
            curmax = max(curmax+num,num);
            curmin = min(curmin+num,num);
            total += num;
            globmax = max(globmax,curmax);
            globmin = min(globmin,curmin);
        }
        return globmax > 0 ? max(globmax, total - globmin) : globmax;
    }
};