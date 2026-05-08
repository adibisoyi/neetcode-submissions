class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_set<int> lookup(nums.begin(),nums.end());
        int longest=1;
        for(auto n:nums)
        {
            if(!lookup.count(n-1))
            {
                int cur = n,len=1;
                while(lookup.count(cur+1))
                {
                    cur++;
                    len++;
                }
                longest=max(longest,len);
            }
        }
        return longest;
    }
};
