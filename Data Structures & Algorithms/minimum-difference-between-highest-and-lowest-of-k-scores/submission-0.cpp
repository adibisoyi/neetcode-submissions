class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int res=INT_MAX;
        int l=0,r=k-1;
        sort(nums.begin(),nums.end());
        while(r<nums.size())
        {
            res = min(res,nums[r]-nums[l]);
            l++;r++;
        }
        return res;
    }
};