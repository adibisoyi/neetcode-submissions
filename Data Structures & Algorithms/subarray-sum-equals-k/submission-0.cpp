class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    /*    int n= nums.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum += nums[j];
                if(sum == k)
                    res++;
            }
        }
        return res;*/

        int res=0,curSum=0;
        unordered_map<int,int> prefix;
        prefix[0]=1;

        for(int num:nums)
        {
            curSum += num;
            int diff = curSum-k;
            res += prefix[diff];
            prefix[curSum]++;
        }
        return res;
    }
};