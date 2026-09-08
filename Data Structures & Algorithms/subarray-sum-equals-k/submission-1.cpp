class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cursum =0,res =0;
        unordered_map<int,int> prefix;
        prefix[0]=1;
        for(int num:nums)
        {
            cursum += num;
            int diff = cursum-k;
            res += prefix[diff];
            prefix[cursum]++;
        }
        return res;
    }
};